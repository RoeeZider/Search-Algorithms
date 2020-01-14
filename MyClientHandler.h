//
// Created by harelfeldman on 1/14/20.
//

#ifndef ADVANCEDPROG2_MYCLIENTHANDLER_H
#define ADVANCEDPROG2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyClientHandler {

    template<class P, class S>
    Solver<P, S> solver;
    CacheManager<P, S> *cm;

public:
    void handleClient(int socket);
};


#endif //ADVANCEDPROG2_MYCLIENTHANDLER_H
