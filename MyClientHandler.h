//
// Created by harelfeldman on 1/14/20.
//

#ifndef ADVANCEDPROG2_MYCLIENTHANDLER_H
#define ADVANCEDPROG2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Matrix.h"
#include "SolverMatrix.h"


class MyClientHandler: ClientHandler {

    SolverMatrix solver;
    CacheManager<Matrix, string> *cache;
    string data;

public:
    MyClientHandler(SolverMatrix solver);
    void handleClient(int socket);
};


#endif //ADVANCEDPROG2_MYCLIENTHANDLER_H
