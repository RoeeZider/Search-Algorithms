//
// Created by roee on 08/01/2020.
//

#ifndef ADVANCEDPROG2_SERVER_H
#define ADVANCEDPROG2_SERVER_H

#include <netinet/in.h>
#include "ClientHandler.h"

namespace server_side {
    class Server {

    public:
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void stop() = 0;
        virtual ~Server() {}
    };
}


#endif //ADVANCEDPROG2_SERVER_H
