//
// Created by Gastone Pietro Rosati Papini on 10/08/22.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

extern "C" {
#include "screen_print_c.h"
}
#include "screen_print.h"
#include "server_lib.h"
#include "logvars.h"

// --- MATLAB PRIMITIVES INCLUDE ---
#include "primitives.h"
// --- MATLAB PRIMITIVES INCLUDE ---

#define DEFAULT_SERVER_IP    "127.0.0.1"
#define SERVER_PORT               30000  // Server port
#define DT 0.05

// Handler for CTRL-C
#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal) {
    server_run = 0;
}

void free_flow(double v0, double a0, double xf, double vr, double coeffsT[6], double *v, double *T) {
    student_pass_primitive(v0, a0, xf, vr, vr, 1.0, 100.0, coeffsT, v, T, coeffsT, v, T);
}

int main(int argc, const char * argv[]) {
    logger.enable(true);

    // Messages variables
    scenario_msg_t scenario_msg;
    manoeuvre_msg_t manoeuvre_msg;
    size_t scenario_msg_size = sizeof(scenario_msg.data_buffer);
    size_t manoeuvre_msg_size = sizeof(manoeuvre_msg.data_buffer);
    uint32_t message_id = 0;

#if not defined( _MSC_VER ) and not defined( _WIN32 )
    // More portable way of supporting signals on UNIX
    struct sigaction act;
    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);
#else
    signal(SIGINT, intHandler);
#endif

    server_agent_init(DEFAULT_SERVER_IP, SERVER_PORT);

    // Start server of the Agent
    printLine();
    printTable("Waiting for scenario message...", 0);
    printLine();
    while (server_run == 1) {

        // Clean the buffer
        memset(scenario_msg.data_buffer, '\0', scenario_msg_size);

        // Receive scenario message from the environment
        if (server_receive_from_client(&server_run, &message_id, &scenario_msg.data_struct) == 0) {
            // Init time
            static auto start = std::chrono::system_clock::now();
            auto time = std::chrono::system_clock::now()-start;
            double num_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(time).count()/1000.0;
            printLogTitle(message_id, "received message");

            // Data struct
            input_data_str *in = &scenario_msg.data_struct;
            manoeuvre_msg.data_struct.CycleNumber = in->CycleNumber;
            manoeuvre_msg.data_struct.Status = in->Status;

            // Example of using log
            logger.log_var("Example", "cycle", in->CycleNumber);
            logger.log_var("Example", "vel", in->VLgtFild);

            // ADD AGENT CODE HERE
            double v0 = in->VLgtFild;
            double a0 = in->ALgtFild;

            double look_ahead = fmax(50, 5*v0);

            double vmin = 3.0;
            double vmax = 15.0;
            double minAcc = -10;
            double maxAcc = 5;
            double vr = in->RequestedCruisingSpeed;

            double xs = 5.0;
            double Ts = xs/vmin;
            double xin = 10.0;
            double Tin = xin/vmin;
            double xtr = 0.0;
            double xstop = 0.0;
            static double init_dist = in->TrfLightDist;

            double bestCoeffs[6];
            double bestT = 0;
            double bestv = 0;
            double bests = 0;
            double bestCoeffsT1[6];
            double bestT1 = 0;
            double bestv1 = 0;
            double bestCoeffsT2[6];
            double bestT2 = 0;
            double bestv2 = 0;

            double Tg = 0;
            double Tr = 0;

            double flag = 0;

            if(in->NrTrfLights != 0) {
                xtr = in->TrfLightDist;
                xstop = in->TrfLightDist - xs/2;
            }

            if(in->NrTrfLights == 0 || xtr >= look_ahead) {
                free_flow(v0, a0, look_ahead, vr, bestCoeffs, &bestv, &bestT);
            } else {
                switch(in->TrfLightCurrState) {
                case 1:
                    Tg = 0;
                    Tr = in->TrfLightFirstTimeToChange - Tin - Ts;
                    break;
                case 2:
                    Tg = in->TrfLightSecondTimeToChange + Ts;
                    Tr = in->TrfLightThirdTimeToChange - Tin - Ts;
                    break;
                case 3:
                    Tg = in->TrfLightFirstTimeToChange + Ts;
                    Tr = in->TrfLightSecondTimeToChange - Tin - Ts;
                    break;
                // default:
                //     Tg = 0;
                //     Tr = 0;
                }
                if(in->TrfLightCurrState == 1 && in->TrfLightDist <= xs) {
                    free_flow(v0, a0, look_ahead, vr, bestCoeffs, &bestv, &bestT);
                } else {
                    student_pass_primitive(v0, a0, xtr, vmin, vmax, Tg, Tr, bestCoeffsT2, &bestv2, &bestT2, bestCoeffsT1, &bestv1, &bestT1);
                    for(int i = 0; i<6; i++) {
                        if(bestCoeffsT1[i] != 0 || bestCoeffsT2[i] != 0) {
                            flag = 1;
                        } 
                    }
                    if(flag == 0) {
                        student_stop_primitive(v0, a0, xstop, bestCoeffs, &bests, &bestT);
                    } else {
                        if((bestCoeffsT1[3] <= 0 && bestCoeffsT2[3] >= 0) || (bestCoeffsT1[3] >= 0 && bestCoeffsT2[3] <= 0)) {
                            student_pass_primitive_j0(v0, a0, xtr, vmin, vmax, bestCoeffs, &bestv, &bestT);
                        } else {
                            if(abs(bestCoeffsT1[3]) < abs(bestCoeffsT2[3])) {
                                for(int i=0; i<6; i++) {
                                    bestCoeffs[i] = bestCoeffsT1[i];
                                }
                                bestv = bestv1; 
                                bestT = bestT1;
                            } else {
                                for(int i=0; i<6; i++) {
                                    bestCoeffs[i] = bestCoeffsT2[i];
                                }
                                bestv = bestv2; 
                                bestT = bestT2;
                            }
                        }
                    }
                }
            }

            // ADD LOW LEVEL CONTROL CODE HERE
            static double old_req_acc = 0;
            static double integral = 0;
            double req_acc = 0.0;
            double req_vel = v0;
            double req_ped = 0;
            if(bestT <= 0) {
                old_req_acc = 0;
                integral = 0;
                req_acc = 0;
                req_vel = v0;
                req_ped = 0;
            } else {
                double longGain = 20;
                double j0 = bestCoeffs[3];
                double s0 = bestCoeffs[4];
                double cr0 = bestCoeffs[5];
                double tOffs = 0;
                double jT0 = j0 + tOffs * s0 + 0.5 * tOffs * tOffs * cr0;
                double jT1 = j0 + (DT + tOffs) * s0 + 0.5 * (DT+tOffs) * (DT+tOffs) * cr0;
                req_acc = fmin(fmax((old_req_acc + longGain * (DT * (jT0+jT1) * 0.5)), minAcc),  maxAcc);
                old_req_acc = req_acc;
                req_vel = v_opt(DT, v0, a0, bests, bestv, 0, bestT);

                double P_gain = 0.02;
                double I_gain = 1;
                double error = req_acc - a0;
                integral = integral + error * DT;
                req_ped = P_gain * error + I_gain * integral; 
            }

            // Log on file
            logger.log_var("logout", "time", in->ECUupTime);
            logger.log_var("logout", "dist", init_dist - in->TrfLightDist);
            logger.log_var("logout", "vel", v0);
            logger.log_var("logout", "acc", a0);
            logger.log_var("logout", "sf", in->TrfLightDist);
            logger.log_var("logout", "vmin", vmin);
            logger.log_var("logout", "vmax", vmax);
            logger.log_var("logout", "req_acc", req_acc);
            logger.log_var("logout", "req_vel", req_vel);
            logger.log_var("logout", "C0", bestCoeffs[0]);
            logger.log_var("logout", "C1", bestCoeffs[1]);
            logger.log_var("logout", "C2", bestCoeffs[2]);
            logger.log_var("logout", "C3", bestCoeffs[3]);
            logger.log_var("logout", "C4", bestCoeffs[4]);
            logger.log_var("logout", "C5", bestCoeffs[5]);
            logger.log_var("logout", "T", bestT);
            logger.write_line("logout");
            
            // Print
            printLogVar(message_id, "CycleNumber", scenario_msg.data_struct.CycleNumber);
            printLogVar(message_id, "time", in->ECUupTime);
            printLogVar(message_id, "xtr-look", xtr-look_ahead);
            printLogVar(message_id, "xs-trfligthdist", xs/2-in->TrfLightDist);
            printLogVar(message_id, "vel [m/s]", v0);
            printLogVar(message_id, "req_vel [m/s^2]", req_vel);
            printLogVar(message_id, "req_ped [-]", req_ped);

            manoeuvre_msg.data_struct.RequestedAcc = req_ped;

            // Send manoeuvre message to the environment
            if (server_send_to_client(server_run, message_id, &manoeuvre_msg.data_struct) == -1) {
                perror("error send_message()");
                exit(EXIT_FAILURE);
            } else {
                printLogTitle(message_id, "sent message");
            }
        }
    }

    // Close the server of the agent
    server_agent_close();
    return 0;
}