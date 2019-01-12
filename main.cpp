#include <iostream>
#include <cstring>
#include "Server.h"

int main(int argc, char **argv) {

  server_side::boot::Main runMain;
  runMain.main(++argv);


  return 0;
}


