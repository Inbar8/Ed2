

#ifndef ED2_OUTPUTSOCKET_H
#define ED2_OUTPUTSOCKET_H

#include <ostream>
#include <sys/socket.h>

using namespace std;

class OutputSocket : public ostream {


  int sockFd;

 public:

  explicit OutputSocket(int setNSockFd) {
    this->sockFd = setNSockFd;
  }

  istream& operator>> (istream& is, int func) {





  }



};


#endif //ED2_OUTPUTSOCKET_H
