#ifndef ED2_SERVER_H
#define ED2_SERVER_H
#include "../server_utility/Socket.h"
#include "../MyClientHandler.h"

namespace server_side {

class Server;


namespace boot {

class Main {
 public:
  void main(char **);

};
}
}

class server_side::Server {

 public:

  virtual void open(int port, ClientHandler *handleType) = 0;

  virtual void stop() = 0;

  void runServer(posix_sockets::TCP_server *server) {

    try {
      int i = 1;
      server->listen(INT16_MAX);

      server->setTimeout(0);
      server->push(server->accept());
      server->setTimeout(5);

      while (!server->offline()) {
        posix_sockets::TCP_client* gotClient = server->accept();
        if (gotClient != nullptr) {
          server->push(gotClient);
        }
      }
      // Notify the user.
      cout<<"Server disconnected"<<endl;
      flush(cout);

    } catch (runtime_error &e) {
      e.what();
    } catch (...) {}

  }
};


#endif //ED2_SERVER_H
