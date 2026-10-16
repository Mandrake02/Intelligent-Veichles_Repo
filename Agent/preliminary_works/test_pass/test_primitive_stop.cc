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

      

      // Log on file
      logger.log_var("logout", "time", in->ECUupTime);
      logger.log_var("logout", "dist", init_dist - in->TrfLightDist);
      logger.log_var("logout", "vel", vel);
      logger.log_var("logout", "acc", acc);
      logger.log_var("logout", "sf", sf);
      logger.log_var("logout", "vmin", vmin);
      logger.log_var("logout", "vmax", vmax);
      logger.log_var("logout", "tmin", tmin);
      logger.log_var("logout", "tmax", tmax);
      logger.log_var("logout", "req_acc", req_acc);
      logger.log_var("logout", "req_vel", req_vel);
      logger.log_var("logout", "C0", bestCoeff[0]);
      logger.log_var("logout", "C1", bestCoeff[1]);
      logger.log_var("logout", "C2", bestCoeff[2]);
      logger.log_var("logout", "C3", bestCoeff[3]);
      logger.log_var("logout", "C4", bestCoeff[4]);
      logger.log_var("logout", "C5", bestCoeff[5]);
      logger.log_var("logout", "T", bestT);
      logger.write_line("logout");

      // Print
      printLogVar(message_id, "CycleNumber", scenario_msg.data_struct.CycleNumber);
      printLogVar(message_id, "time", in->ECUupTime);
      printLogVar(message_id, "dist [m]", init_dist - in->TrfLightDist);
      printLogVar(message_id, "vel [m/s]", vel);
      printLogVar(message_id, "req_vel [m/s^2]", req_vel);
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