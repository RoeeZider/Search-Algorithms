//
// Created by harelfeldman on 1/13/20.
//

#ifndef ADVANCEDPROG2_BESTFIRSTSEARCH_H
#define ADVANCEDPROG2_BESTFIRSTSEARCH_H

#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include "Searcher.h"

using namespace std;

template<class T>
class BestFirstSearch : Searcher<T> {
private:
    unordered_set<State<T> *> closed;
    State<T> InitialState;
    State<T> GoalState;

    vector<State<T> *> backTrace() {
        vector<State<T> *> trace = new vector<State<T> *>;
        State<T> *n = this->GoalState;
        while (n != InitialState) {
            trace.push_back(n);
            n = n->getCameFrom();
        }
        trace.push_back(InitialState);
        reverse(trace.begin(), trace.end());
        return trace;
    }

public:
    BestFirstSearch() = default;

    vector<State<T> *> search(Searchable<T> searchable) {
        this->InitialState = searchable.getInitialState();
        this->GoalState = searchable.getGoalState();
        closed = new unordered_set<State<T>>;
        addOpenList(InitialState);
        while (!this->OpenListIsEmpty()) {
            State<T> n = this->popOpenList();
            closed.insert(n);
            if (n.Equals(GoalState)) {
                return backTrace();
            }
            list<State<T> *> successors = searchable.getAllPossibleStates(n);
            for (auto it = successors.begin(); it != successors.end(); ++it) {
                State<T> &temp = it;
                if (!closed.containes(temp) && !temp->getInOpenList()) {
                    //update the parent
                    temp->setCameFrom(n);
                    //update the cost
                    temp->setTotalCost(n.getTotalCost() + temp.getCost());
                    //pushing to open list
                    addOpenList(temp);
                } else if (temp.getTotalCost() > n.getTotalCost() + temp.getCost()) {
                    temp->setCameFrom(n);
                    temp->setTotalCost(n.getTotalCost() + temp.getCost());
                    if (!temp->getInOpenList()) {
                        addOpenList(temp);
                        //if the state already in open just update the cost
                    } else {
                        updateOpenList(temp);
                    }
                }
            }
        }
    }
};


#endif //ADVANCEDPROG2_BESTFIRSTSEARCH_H
