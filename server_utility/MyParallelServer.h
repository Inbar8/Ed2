#ifndef ED2_MYPARALLELSERVER_H
#define ED2_MYPARALLELSERVER_H

#include "Server.h"

 class MyParallelServer : public server_side::Server {


    public:
   MyParallelServer() = default;

     void open(int port, ClientHandler*) override;

     void stop() override;
   };





#endif //ED2_MYPARALLELSERVER_H
