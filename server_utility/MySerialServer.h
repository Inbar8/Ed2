#ifndef ED2_MYSERIALSERVER_H
#define ED2_MYSERIALSERVER_H
#include "Server.h"

 class MySerialServer : public server_side::Server {

 public:
   MySerialServer() = default;

   void open(int port, ClientHandler*) override;

   void stop() override;
};


#endif //ED2_MYSERIALSERVER_H
