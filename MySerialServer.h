#ifndef ED2_MYSERIALSERVER_H
#define ED2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer: public Server{
public:
    void open(int port) override;

    void stop() override;
};
#endif //ED2_MYSERIALSERVER_H
