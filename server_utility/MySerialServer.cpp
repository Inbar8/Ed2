#include "MySerialServer.h"
#include "../checkcheck.h"
#include "../protocols/ProtocolTrace.h"
#include <istream>
void server_side::boot::Main::main(char** args) {

  Server *server = new MySerialServer();
  server->open(stoi(args[0]),
               new MyClientHandler<MatrixMaze<Point>,
                                   vector<string>>(new checkcheck,
                                                   new FileCacheManager<
                                                       MatrixMaze<Point>,
                                                       vector<string>>(
                                                       new ProtocolMatrix,
                                                       new ProtocolTrace),
                                                   new ProtocolMatrix,
                                                   new ProtocolTrace));
}



void runServer(posix_sockets::TCP_server *server) {

  server->listen(INT16_MAX);

  server->push(server->accept());
  server->setTimeout(TIME_OUT);

  while (!server->offline()) {
    server->push(server->accept());


  }

}

void MySerialServer::open(int port, ClientHandler* clientType) {


  try {
    auto * server = new posix_sockets::TCP_server(port);
    queue<thread> handleThreads;
    handleThreads.push(thread(runServer, server));

    while (!server->offline()) {
      posix_sockets::TCP_client* client = server->pop();
      handleThreads.push(thread([&]() {clientType->handleClient(client, client);}));
      delete client;
    }


    while (!handleThreads.empty()) {

      handleThreads.front().join();
      handleThreads.pop();
    }

  } catch (invalid_argument &e) {

  } catch (runtime_error &e) {

  } catch (...) {

  }

}

void MySerialServer::stop() {}
