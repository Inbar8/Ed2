#ifndef ED2_MYSERIALSERVER_H
#define ED2_MYSERIALSERVER_H
#include "ed2.cpp"


template<class Problem, class Solution>
 class MySerialServer : public server_side::Server<Problem, Solution> {


 public:
   MySerialServer() = default;

   void open(int port, ClientHandler<Problem, Solution>) override {};
   void stop() override {};


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
//
//
//  }
//
//  void stop() override {



};

#endif //ED2_MYSERIALSERVER_H
