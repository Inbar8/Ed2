#include <iostream>
#include <cstring>
#include "server_utility/Server.h"

int main(int argc, char **argv) {


  server_side::boot::Main runMain;
  runMain.main(++argv);


  return 0;
}


