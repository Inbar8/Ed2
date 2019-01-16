#ifndef ED2_SOCKET_H
#define ED2_SOCKET_H
#include <iostream>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include <string>
#include <system_error>
#include <stdexcept>
#include <thread>
#include <queue>
#include <atomic>
#include <mutex>
#include <iostream>
#include <condition_variable>

#include "MyException.h"
#include "StreamInput.h"
#include "StreamOutput.h"
#define TIME_OUT 10


namespace posix_sockets {

using namespace std;

struct TCP_socket {
  int sock_fd;
  TCP_socket();

  explicit TCP_socket(int open_sock_fd) {
    this->sock_fd = open_sock_fd;
  }

  void close();

  void setTimeOut(int, int usec = 0);
};

class TCP_client : public StreamOutput, public StreamInput {

  TCP_socket sock;

 public:

  explicit TCP_client(TCP_socket sock) : sock(sock) {}

 public:

  void write(const string &) override;

  string read() override;

  void setTimeout(int, int usec = 0);

  void close();
};

class TCP_server {

  std::atomic<bool> stopServer;

  std::queue<posix_sockets::TCP_client *> clients;

  mutable std::condition_variable queue_cond_var;

  mutable std::mutex mut;

  TCP_socket sock;

 public:
  explicit TCP_server(int port);

  void listen(int max_lis);

  void setTimeout(int sec, int usec = 0);

  TCP_client *accept();

  bool offline() const { return stopServer; }
  void close();

  bool empty() const {
    std::lock_guard<std::mutex> g(mut);
    return clients.empty();
  }
  TCP_client *pop() {
    std::lock_guard<std::mutex> g(mut);
    if (clients.empty()) {
      return nullptr;
    }
    auto *client = clients.front();
    clients.pop();
    return client;
  }

  void push(TCP_client *client) {
    if (client == nullptr) {
      throw std::invalid_argument("Task should not be null");
    }
    std::lock_guard<std::mutex> g(mut);
    clients.push(client);
    queue_cond_var.notify_one();
  }

  void wait() const {
    std::unique_lock<std::mutex> ul(mut);
    if (stopServer) return;
    queue_cond_var.wait(ul);
  }

};






}


#endif //ED2_SOCKET_H
