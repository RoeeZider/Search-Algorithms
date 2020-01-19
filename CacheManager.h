//
// Created by roee on 08/01/2020.
//

#ifndef ADVANCEDPROG2_CACHEMANAGER_H
#define ADVANCEDPROG2_CACHEMANAGER_H
using namespace std;
#include "Solver.h"
template<typename P, typename S>
class CacheManager {
    //check solution - problem
    public:
        virtual S getSolution(P problem) = 0;
        virtual void saveSolution(P problem, S& solution) = 0;
        virtual bool isSolved(P problem) = 0;
    };




#endif //ADVANCEDPROG2_CACHEMANAGER_H
