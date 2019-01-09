

#ifndef ED2_OUTPUTSOCKET_H
#define ED2_OUTPUTSOCKET_H

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

 class OutputSocket : public streambuf {


  int sockFd;

 public:

  explicit OutputSocket(int setNSockFd) {
    this->sockFd = setNSockFd;

  }

  int getSocketFd() {
    return this->sockFd;
  }

  friend OutputSocket& operator<<(OutputSocket& out, const char* buffer) {

    if(write(out.getSocketFd(), buffer, sizeof(buffer)) < 0) {
      throw runtime_error("Can't write to socket");
    }
  //  streambuf::flflush();
    return out;
  }
};


#endif //ED2_OUTPUTSOCKET_H
