#include "Socket.h"
#include <algorithm>
#include <strings.h>

#define ERROR -1
#define BUFFER_SIZE 1024
#define TIME_WAIT 15
posix_sockets::TCP_socket::TCP_socket() {
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    throw system_error(error_code(errno, generic_category()),
                       "failure on opening socket");
  }
}

void posix_sockets::TCP_socket::close() {
  if (::close(sock_fd) < 0) {
    throw system_error(error_code(errno, generic_category()),
                       "failure on closing socket");
  }
}

void posix_sockets::TCP_socket::setTimeOut(int sec, int usec) {
  timeval timeout;
  timeout.tv_sec = sec;
  timeout.tv_usec = usec;

  // setting socket option for recieve timeout
  if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO,
                 (char *) &timeout, sizeof(timeout)) == -1) {
    throw system_error(error_code(errno, generic_category()),
                       "failure on setsockopt");
  }
}



posix_sockets::TCP_server::TCP_server(int port) {
  sockaddr_in addr_in;
  addr_in.sin_family = AF_INET;
  addr_in.sin_port = htons((uint16_t) port);
  addr_in.sin_addr.s_addr = INADDR_ANY;

  if (bind(sock.sock_fd, (sockaddr *) &addr_in, sizeof(addr_in)) == ERROR) {
    throw system_error(error_code(errno, generic_category()),
                       "failure on bind");
  }
}

void posix_sockets::TCP_server::listen(int max_lis) {
  if (::listen(sock.sock_fd, max_lis) == ERROR) {
    throw system_error(error_code(errno, generic_category()),
                       "error on listen");
  }
}


posix_sockets::TCP_client posix_sockets::TCP_server::accept() {
  sockaddr_in addr;
  socklen_t len = sizeof(addr);
  int client_sock_fd = ::accept(sock.sock_fd, (sockaddr *) &addr, &len);
  if (client_sock_fd < 0) {
    // eagain and ewouldblock are errors normally hapenning on timeouts
    if (errno == EAGAIN || errno == EWOULDBLOCK) {
      throw timeout_exception("timeout on accept");
    } else {
      throw system_error(error_code(errno, generic_category()),
                         "error on accept");
    }
  }

  TCP_client client_socket = TCP_client(TCP_socket(client_sock_fd));
  client_socket.setTimeout(TIME_WAIT);
  return client_socket;
}


void posix_sockets::TCP_server::setTimeout(int sec, int usec) {
  sock.setTimeOut(sec, usec);
}

void posix_sockets::TCP_server::close() {
  sock.close();
}


void posix_sockets::TCP_client::setTimeout(int sec, int usec) {
  sock.setTimeOut(sec, usec);
}

void posix_sockets::TCP_client::close() {
  sock.close();
}


posix_sockets::string posix_sockets::TCP_client::read() {

  char buffer[BUFFER_SIZE];
  ::bzero(buffer, BUFFER_SIZE);

    if (::read(this->sock.sock_fd, buffer, BUFFER_SIZE - 1) < 0)	{
      if (errno == EAGAIN || errno == EWOULDBLOCK)	{
        throw timeout_exception("timeout on read");
      }
      throw system_error(error_code(errno, generic_category()), "error on read");
    }

    string str = buffer;
  str.erase(remove(str.begin(), str.end(), '\r'), str.end());
  return str;
}



void posix_sockets::TCP_client::write(const string& sendIt) {

  if(::write(this->sock.sock_fd, sendIt.c_str(), sendIt.size()) < 0) {

    throw system_error(error_code(errno, generic_category()),
                       "failure to write to the socket");
  };
}
