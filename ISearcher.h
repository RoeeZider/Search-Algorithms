//
// Created by harelfeldman on 1/13/20.
//

#ifndef ADVANCEDPROG2_ISEARCHER_H
#define ADVANCEDPROG2_ISEARCHER_H

#include <vector>
#include "Searchable.h"
#include "Point.h"
template <class T>
class ISearcher {
public:
    virtual vector<State<T>*> search(Searchable<T> *searchable) = 0;
    virtual int getNumberOfNodesEvaluated()=0;
    virtual int getTotalCostPath()=0;
    virtual ~ISearcher()=0;
};

#endif //ADVANCEDPROG2_ISEARCHER_H
