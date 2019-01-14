
#ifndef ED2_PROTOCOLTRACE_H
#define ED2_PROTOCOLTRACE_H
#include <vector>
#include "Protocol.h"
class ProtocolTrace : public Protocol<vector<string>> {

 public:
  vector<string> readProtocol(string readVector) override {


    return vector<string>();
  }
  string writeProtocol(vector<string> t) override {
    return std::__cxx11::string();
  }
//}Right, Left, Down, Up }
};

#endif //ED2_PROTOCOLTRACE_H
