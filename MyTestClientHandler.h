//
// Created by roee on 09/01/2020.
//

#ifndef ADVANCEDPROG2_MYTESTCLIENTHANDLER_H
#define ADVANCEDPROG2_MYTESTCLIENTHANDLER_H
#include "Solver.h"
#include "Server.h"
#include "FileCacheManager.h"
#include <iostream>
#include "CacheManager.h"
#include "ClientHandler.h"
using namespace server_side;
class MyTestClientHandler : public ClientHandler{
    Solver<string,string> *solver;
    CacheManager<string, string> *cache;
public:
    virtual void handleClient(int server_socket);
    MyTestClientHandler(Solver<string,string> *mySolver,CacheManager<string,string>* myCache) {
        this->solver = mySolver;
        this->cache = myCache;
    }
};


#endif //ADVANCEDPROG2_MYTESTCLIENTHANDLER_H
