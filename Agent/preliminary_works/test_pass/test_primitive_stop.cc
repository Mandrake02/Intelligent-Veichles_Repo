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

#include "primitives.h"
#define DEFAULT_SERVER_IP "127.0.0.1"
#define SERVER_PORT 30000
#define DT 0.05

#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal) {
  server_run = 0;
}

int main(int argc, const char *argv[]) {
  logger.enable(true);

  scenario_msg_t scenario_msg;
  manoeuvre_msg_t manoeuvre_msg;
  size_t scenario_msg_size = sizeof(scenario_msg.data_buffer);
  size_t manoeuvre_msg_size = sizeof(manoeuvre_msg.data_buffer);
  uint32_t message_id = 0;

#ifndef WIN32
  struct sigaction act;
  act.sa_handler = intHandler;
  sigaction(SIGINT, &act, NULL);
#else 
  signal(SIGINT, intHandler);
#endif

  server_agent_init(DEFAULT_SERVER_IP, SERVER_PORT);
  printLine();
  printTable("Waiting for scenario message", 0);
  printLine();

  while(server_run==1) {
    memset(scenario_msg.data_buffer, '\0', scenario_msg_size);
    if (server_receive_from_client(&server_run, &message_id, &scenario_msg.data_struct) == 0) {
      printLogTitle(message_id, "recieved message");

      input_data_str* in = &scenario_msg.data_struct;
      manoeuvre_msg.data_struct.CycleNumber = scenario_msg.data_struct.CycleNumber;
      manoeuvre_msg.data_struct.Status = scenario_msg.data_struct.Status;

      double coeffs[6];
      double smax;
      double tf;
      double minAcc = -10;
      double maxAcc = 5;
      double acc = fmin(fmax(in->ALgtFild, minAcc), maxAcc);
      double vel = in->VLgtFild;
      static double init_dist = in->TrfLightDist;
      double sf = in->TrfLightDist;
      double req_ped = 0;
      double req_acc;
      static double old_req_acc = 0;
      static double integral = 0;

      if(in->TrfLightDist < 80 && in->TrfLightDist > 0 && vel > 0) {
        student_stop_primitive(vel, acc, sf, coeffs, &smax, &tf);
        double longGain = 20;
        double j0 = coeffs[3];
        double s0 = coeffs[4];
        double cr0 = coeffs[5];
        double tOffs = 0;
        double jT0 = j0 + tOffs * s0 + 0.5 * tOffs * tOffs * cr0;
        double jT1 = j0 + (DT + tOffs) * s0 + 0.5 * (DT+tOffs) * (DT+tOffs) * cr0;
        req_acc = fmin(fmax((old_req_acc + longGain * (DT * (jT0+jT1) * 0.5)), minAcc), maxAcc);
        old_req_acc = req_acc;

        double P_gain = 0.02;
        double I_gain = 1;
        double error = req_acc - acc;
        integral = integral + error * DT;
        req_ped = P_gain * error + I_gain * integral;
      } else {
        integral = 0;
        old_req_acc = 0;
        if(init_dist-in->TrfLightDist < 10) {
          req_ped = 10.0;
        } else {
          req_ped = 0.0;
        }
      }

      // Log on file
      logger.log_var("logout", "time", in->ECUupTime);
      logger.log_var("logout", "dist", init_dist - in->TrfLightDist);
      logger.log_var("logout", "vel", vel);
      logger.log_var("logout", "acc", acc);
      logger.log_var("logout", "sf", sf);
      // logger.log_var("logout", "vmin", vmin);
      // logger.log_var("logout", "vmax", vmax);
      // logger.log_var("logout", "tmin", tmin);
      // logger.log_var("logout", "tmax", tmax);
      logger.log_var("logout", "req_acc", req_acc);
      // logger.log_var("logout", "req_vel", req_vel);
      logger.log_var("logout", "C0", coeffs[0]);
      logger.log_var("logout", "C1", coeffs[1]);
      logger.log_var("logout", "C2", coeffs[2]);
      logger.log_var("logout", "C3", coeffs[3]);
      logger.log_var("logout", "C4", coeffs[4]);
      logger.log_var("logout", "C5", coeffs[5]);
      // logger.log_var("logout", "T", bestT);
      logger.write_line("logout");

      // Print
      printLogVar(message_id, "CycleNumber", scenario_msg.data_struct.CycleNumber);
      printLogVar(message_id, "time", in->ECUupTime);
      printLogVar(message_id, "dist [m]", init_dist - in->TrfLightDist);
      printLogVar(message_id, "vel [m/s]", vel);
      // printLogVar(message_id, "req_vel [m/s^2]", req_vel);
      printLogVar(message_id, "req_ped [-]", req_ped);

      manoeuvre_msg.data_struct.RequestedAcc = req_ped;

      if (server_send_to_client(server_run, message_id, &manoeuvre_msg.data_struct) == -1) {
        perror("error send_message()");
        exit(EXIT_FAILURE);
      } else {
        printLogTitle(message_id, "sent message");
      }
    }
  }
  server_agent_close();
  return 0;
}