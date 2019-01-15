
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
    string returnString;

    returnString += "{";
    for(const string &add : t) {

      returnString += add;

    }
    returnString += "}";

    return returnString;
  }
//}Right, Left, Down, Up }
};

#endif //ED2_PROTOCOLTRACE_H
