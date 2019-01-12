#ifndef ED2_SOCKET_H
#define ED2_SOCKET_H
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include <string>
#include <system_error>
#include <stdexcept>
#include "MyException.h"
#include "StreamInput.h"
#include "StreamOutput.h"

namespace posix_sockets {
using namespace std;

// the socket is not automatically closed in the destructor so that the object
// can be passed as a parameter (possibly to another thread)
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

  void write(const string&) override;

  string read() override;

  void setTimeout(int, int usec = 0);

  void close();
};


class TCP_server {
  TCP_socket sock;
 public:
  explicit TCP_server(int port);

  void listen(int max_lis);

  void setTimeout(int sec, int usec = 0);

  TCP_client accept();

  void close();
};
}

#endif //ED2_SOCKET_H
