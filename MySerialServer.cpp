#include "MySerialServer.h"
#include "checkcheck.h"
#include "ProtocolTrace.h"
#include <istream>


void server_side::boot::Main::main(char** args) {

  try {

    Server *server = new MySerialServer();
    server->open(stoi(args[0]),
                 new MyClientHandler<MatrixMaze<Point>, vector<string>>(
                     new checkcheck,
                     new FileCacheManager<MatrixMaze<Point>, vector<string>>,
                     new ProtocolMatrix, new ProtocolTrace));

  } catch (...) {
    cout << "Failed to create server" << endl;
  }

}

void MySerialServer::open(int port, ClientHandler* clientType) {

  auto *serialServer = new posix_sockets::TCP_server(port);

  serialServer->listen(INT16_MAX);
  serialServer->setTimeout(1500000);

  posix_sockets::TCP_client client = serialServer->accept();
  clientType->handleClient(&client, &client);

  serialServer->close();
  delete serialServer;
}



void MySerialServer::stop() {

}
MySerialServer::MySerialServer() = default;

// public:
//  //void open(int port, ClientHandler) override {
//
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
//   // pthread_create(&threadServer, nullptr, OpenReadingServer, this->data);
//    pthread_cond_wait(&flightGearConnected, &mu);
//    pthread_mutex_unlock(&mu);
//
//    // Clean.
//    pthread_mutex_destroy(&mu);
//    pthread_cond_destroy(&flightGearConnected);
//  }
//
//  time_t startTimeSec = time(NULL);
//
//  // answering
//
//  time_t endTimeSec = time(NULL);
//  time_t timeTakenSec = endTime-startTime;
//  if (timeTaken > 10) {
//    // do your thing
//  }
//}
//
