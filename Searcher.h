//
// Created by harelfeldman on 1/14/20.
//

#ifndef ADVANCEDPROG2_SEARCHER_H
#define ADVANCEDPROG2_SEARCHER_H

#include "PriorityQueue.h"
#include "ISearcher.h"

template<class T>
class Searcher : ISearcher<T> {
private:
    int evaluateNodes;
    PriorityQueue<T> openList;
public:
    Searcher() {
        openList = new PriorityQueue<T>;
        this->evaluateNodes = 0;
    };

    int getNumberOfNodesEvaluated() {
        return this->evaluateNodes;
    };

    virtual vector<State<T> *> search(Searchable<T>* searchable) = 0;

    State<T> *popOpenList() {
        evaluateNodes++;
        return openList.pop();
    };

    void addOpenList(State<T> &s) {
        this->openList.push(s);
        s.setInOpenList();
    };

    bool OpenListIsEmpty() {
        return openList.isEmpty();
    };

    void updateOpenList(State<T> s) {
        this->openList.update(s);
    };
};


#endif //ADVANCEDPROG2_SEARCHER_H
