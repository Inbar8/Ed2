#ifndef ED2_MYSERIALSERVER_H
#define ED2_MYSERIALSERVER_H
#include "Server.h"

 class MySerialServer : public server_side::Server {

  pthread_t serialThread;

 public:
   MySerialServer();

   void open(int port, ClientHandler*) override;

   void stop() override;
};


#endif //ED2_MYSERIALSERVER_H
