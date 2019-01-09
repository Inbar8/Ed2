
#ifndef ED2_SOCKETINPUTSTREAM_H
#define ED2_SOCKETINPUTSTREAM_H
#include <istream>
#include <sys/socket.h>
#include <unistd.h>
#include <strings.h>
using namespace std;

 class InputSocket {


  int sockFd;

  public:

   int getSocketFd() {
    return this->sockFd;
   }

   explicit InputSocket(int setNSockFd) {
   this->sockFd = setNSockFd;

  }


   friend InputSocket& operator>>(InputSocket& out, const char* buffer) {


    bzero(&buffer, sizeof(buffer));

    if(read(out.getSocketFd(), &buffer, sizeof(buffer)) < 0) {
     throw runtime_error("Can't read from socket");
    }

    return out;
   }
 };

#endif //ED2_SOCKETINPUTSTREAM_H
