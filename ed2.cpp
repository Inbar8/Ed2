#include "Server.h"
#include "StringReverser.h"
#include "MyClientHandler.h"

namespace server_side {

template<class Problem, class Solution>
class Server;

namespace boot {
class Main {
 public:
  int main(const string &port);

};
}
};





//int server_side::boot::Main::main(const string &port) {
//
//    Server<string, string>* server = new MySerialServer::MySerialServer();
//
//    server->open(stoi(port),new MyClientHandler<string, string>(
//                                            new StringReverser,
//                                            new FileCacheManager<string,string>));
//
//  }