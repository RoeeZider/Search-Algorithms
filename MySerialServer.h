//
// Created by roee on 09/01/2020.
//

#ifndef ADVANCEDPROG2_MYSERIALSERVER_H
#define ADVANCEDPROG2_MYSERIALSERVER_H


#include <netinet/in.h>
#include "ClientHandler.h"

class MySerialServer {

public:
    void open(int port, ClientHandler *c);

    void stop();

    static void start(int sockfd, sockaddr_in address, ClientHandler *c);

    static bool shouldStop;


};


#endif //ADVANCEDPROG2_MYSERIALSERVER_H
