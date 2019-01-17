#include "MySerialServer.h"
#include "../protocols/ProtocolTrace.h"
#include <istream>
//void server_side::boot::Main::main(char** args) {
//
//  Server *server = new MySerialServer();
//  server->open(stoi(args[0]),
//               new MyClientHandler<MatrixMaze<Point>,
//                                   vector<string>>(new checkcheck,
//                                                   new FileCacheManager<
//                                                       MatrixMaze<Point>,
//                                                       vector<string>>(
//                                                       new ProtocolMatrix,
//                                                       new ProtocolTrace),
//                                                   new ProtocolMatrix,
//                                                   new ProtocolTrace));
//}





void MySerialServer::open(int port, ClientHandler* clientType) {

  try {

    auto * server = new posix_sockets::TCP_server(port);

    thread running([&]() {
      this->runServer(server);});

    while (!server->offline()) {

      while (!server->empty()) {
        posix_sockets::TCP_client *client = server->pop();
        thread t([&]() { clientType->handleClient(client, client); });

        if (t.joinable()) {
          t.join();
        }
      }
    }
    exit(0);

  } catch (invalid_argument &e) {

  } catch (runtime_error &e) {

  } catch (...) {

  }

}

void MySerialServer::stop() {}
