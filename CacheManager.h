//
// Created by roee on 08/01/2020.
//

#ifndef ADVANCEDPROG2_CACHEMANAGER_H
#define ADVANCEDPROG2_CACHEMANAGER_H

#include "Solver.h"
template<typename P, typename S>
class CacheManager {
    //check solution - problem
public:
    virtual bool IsSolutionExist(P problem)=0;
    virtual S getSolution(P problem) = 0;
    virtual void saveSolution(S solution,P problem) = 0;
    virtual ~CacheManager() {}
};



#endif //ADVANCEDPROG2_CACHEMANAGER_H
