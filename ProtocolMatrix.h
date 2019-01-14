
#ifndef ED2_PROTOCOLMATRIX_H
#define ED2_PROTOCOLMATRIX_H

#include "Protocol.h"
#include "MatrixMaze.h"

class ProtocolMatrix : public Protocol<MatrixMaze<int>> {



 public:


  MatrixMaze<int> readProtocol(string readMatrix) override {





    //return MatrixMaze<int>();
  }
  string writeProtocol(MatrixMaze<int> t) override {
    return std::__cxx11::string();
  }

};


#endif //ED2_PROTOCOLMATRIX_H
