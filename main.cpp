#include <iostream>
#include <cstring>
#include "Server.h"

int main(int argc, char **argv) {


    std::string str = "-1,2,3,4,5,6\n7,8,9\n10,11,12,13,14,16\n";
    std::vector<int> vect;

    std::stringstream ss(str);

    int i;

    while (ss >> i)
    {
      vect.push_back(i);

      if (ss.peek() == ',')
        ss.ignore();
      if (ss.peek() == '\n') {

        for (i=0; i< vect.size(); i++) {
          std::cout << vect.at(i) << " ";
        }
        vect.clear();
        cout<<endl;
      }

    }


  exit(0);

  server_side::boot::Main runMain;
  runMain.main(++argv);


  return 0;
}


