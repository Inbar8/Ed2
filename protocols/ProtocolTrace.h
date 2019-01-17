
#ifndef ED2_PROTOCOLTRACE_H
#define ED2_PROTOCOLTRACE_H
#include <vector>
#include "Protocol.h"
class ProtocolTrace : public Protocol<vector<string>> {

 public:
  vector<string>* readProtocol(string readVector) override {
    auto * vectorToReturn = new vector<string>;
    string tempString;
    stringstream stream(readVector);
    char temp;
    while (stream >> temp) {
      if (temp == '{') {
        continue;
      }
      tempString += temp;
      if (stream.peek() == ',') {
        stream.ignore();
        vectorToReturn->push_back(tempString);
        tempString.clear();
      } else if (stream.peek() == '}') {
        vectorToReturn->push_back(tempString);
        break;
      }
  }
    return vectorToReturn;
  }
  string writeProtocol(vector<string> t) override {
    string returnString;

    returnString += "{";
    for(const string &add : t) {

      returnString += add;

    }
    returnString += "}";

  //  return returnString;
  string h = "hello";
  return h;
  }
//}Right, Left, Down, Up }
};

#endif //ED2_PROTOCOLTRACE_H
