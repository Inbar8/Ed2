#ifndef ED2_SERVER_H
#define ED2_SERVER_H

using namespace std;

class Server {
public:
    virtual void open(int port) = 0;

    virtual void stop() = 0;
};

#endif //ED2_SERVER_H
