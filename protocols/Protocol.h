

#ifndef ED2_PROTOCOL_H
#define ED2_PROTOCOL_H

#include <string>
using namespace std;
template <class T>
class Protocol {


 public:

  virtual T* readProtocol(string) = 0;

  virtual string writeProtocol(T) = 0;

};

#endif //ED2_PROTOCOL_H
