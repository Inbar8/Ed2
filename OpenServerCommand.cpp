//#include "OpenServerCommand.h"
//
//#define OPEN_SERVER ", trouble in open server syntax."
//#define MAX_PORT_NUMBER 65535
//#define VALID_DATA_COUNT 2
//
//// Type of data passed.
//enum Data {
//    PORT_TO_CONNECT, READS_FOR_SECOND
//};
//
///**
// * Construct the open server class command.
// * @param stringData - get the data to open by.
// */
//OpenServerCommand::OpenServerCommand(const vector<string> &stringData) {
//
//    // Create a packet to send the server data.
//    this->data = new PassProgramData();
//
//    // Check valid for the data.
//    if (checkValid(stringData)) {
//        // Convert data to usable numbers, if double catch it.
//        this->data->serverData.port = (uint16_t) stoi(
//                stringData[PORT_TO_CONNECT]);
//
//        this->data->serverData.readForSecond =
//                (this->data->serverData.readForSecond /
//                 stoi(stringData[READS_FOR_SECOND]));
//
//    } else {
//        throw invalid_argument(SYNTAX_ERROR OPEN_SERVER);
//    }
//}
//
//
//
///**
// * Execute the command, open server for reading information.
// * @param data - port and read for second speed(inside the list).
// */
//void OpenServerCommand::doCommand() {
//
//    // Create pthread, conditional thread & mutex.
//
//    pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
//    pthread_t threadServer;
//    pthread_cond_t flightGearConnected = PTHREAD_COND_INITIALIZER;
//    // Pass the cond for stopping the program until connection created.
//    this->data->serverCond = &flightGearConnected;
//
//    // Lock until the connection created, wait for signal.
//    pthread_mutex_lock(&mu);
//    pthread_create(&threadServer, nullptr, OpenReadingServer, this->data);
//    pthread_cond_wait(&flightGearConnected, &mu);
//    pthread_mutex_unlock(&mu);
//
//    // Clean.
//    pthread_mutex_destroy(&mu);
//    pthread_cond_destroy(&flightGearConnected);
//}
//
///**
// * Clean data passes.
// */
//OpenServerCommand::~OpenServerCommand() {
//    delete data;
//}
