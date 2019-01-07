
#ifndef ED2_SOCKETINPUTSTREAM_H
#define ED2_SOCKETINPUTSTREAM_H
#include <istream>
#include <sys/socket.h>

 using namespace std;

 template <class DataType>
 class InputSocket : public istream {


  int sockFd;

  public:

   explicit InputSocket(int setNSockFd) {
   this->sockFd = setNSockFd;
  }
//
//   friend *this operator>> (*this is, int& answer) {
//
//     is>>answer;
//
//
//   }



 };

#endif //ED2_SOCKETINPUTSTREAM_H
