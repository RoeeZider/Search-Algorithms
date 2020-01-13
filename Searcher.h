//
// Created by harelfeldman on 1/13/20.
//

#ifndef ADVANCEDPROG2_SEARCHER_H
#define ADVANCEDPROG2_SEARCHER_H

#include "Searchable.h"

class ISearcher {
public:
    virtual Solution search(Searchable searchable) = 0;
    virtual int getNumberOfNodesEvaluated()=0;
    virtual ~ISearcher();
};

class Searcher:ISearcher{
private:
    int evaluateNodes;
public:
    Searcher();
    int getNumberOfNodesEvaluated();
    virtual Solution search(Searchable searchable) = 0;
};
#endif //ADVANCEDPROG2_SEARCHER_H
