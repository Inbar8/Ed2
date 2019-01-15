#ifndef ED2_SERVER_H
#define ED2_SERVER_H
#include <pthread.h>
#include "../server_utility/Socket.h"
#include "../ClientHandler.h"
#include "../StringReverser.h"
#include "../MyClientHandler.h"

namespace server_side {

class Server;

namespace boot {

class Main {
 public:
  void main(char**);

};
}
}

class server_side::Server {

public:

virtual void open(int port, ClientHandler* handleType) = 0;

virtual void stop() = 0;
};

#endif //ED2_SERVER_H
