//
// Created by roee on 08/01/2020.
//

#ifndef ADVANCEDPROG2_SOLVER_H
#define ADVANCEDPROG2_SOLVER_H

template<typename P, typename S>
class Solver {
    virtual S solve(P problem)=0;
    virtual ~Solver() {}
};



#endif //ADVANCEDPROG2_SOLVER_H
