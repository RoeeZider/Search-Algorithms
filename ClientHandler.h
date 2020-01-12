//
// Created by roee on 08/01/2020.
//

#ifndef ADVANCEDPROG2_CLIENTHANDLER_H
#define ADVANCEDPROG2_CLIENTHANDLER_H

#include <iostream>
#include <istream>
using namespace std;


class ClientHandler {

public:
    virtual void handleClient(int socket) = 0;
    virtual ~ClientHandler() {}
};



#endif //ADVANCEDPROG2_CLIENTHANDLER_H
