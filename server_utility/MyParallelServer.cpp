#include "MyParallelServer.h"
#include "../protocols/ProtocolTrace.h"
#include "../SolverAlgorithms.h"
#include "../BestFirstSearch.h"
#include <istream>
#define PROBLEM MatrixMaze<Point>
#define SOLUTION vector<string>
void server_side::boot::Main::main(char** args) {

  Server *server = new MyParallelServer();
  server->open(stoi(args[0]),
               new MyClientHandler<PROBLEM, SOLUTION >(
                   new SolverAlgorithms<PROBLEM, SOLUTION >(
                       new BestFirstSearch<PROBLEM, SOLUTION >),
                   new FileCacheManager<PROBLEM, SOLUTION >(
                       new ProtocolMatrix,
                       new ProtocolTrace),
                   new ProtocolMatrix,
                   new ProtocolTrace));
}

void MyParallelServer::open(int port, ClientHandler* clientType) {

  try {

    auto * server = new posix_sockets::TCP_server(port);

    queue<thread> handleThreads;
    thread running([&]() {
      this->runServer(server);});

    while (!server->offline()) {

      if (!server->empty()) {
        posix_sockets::TCP_client *client = server->pop();
        handleThreads.push(thread([&]() {
          clientType->handleClient(client,
                                   client);
        }));
      }
    }


    while (!handleThreads.empty()) {

      handleThreads.front().join();
      handleThreads.pop();
    }
    exit(0);

  } catch (invalid_argument &e) {
    exit(0);
  } catch (runtime_error &e) {
    exit(0);
  } catch (...) {
    exit(0);
  }

}


void MyParallelServer::stop() {}
