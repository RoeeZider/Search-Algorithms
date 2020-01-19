//
// Created by harelfeldman on 1/13/20.
//

#ifndef ADVANCEDPROG2_BESTFIRSTSEARCH_H
#define ADVANCEDPROG2_BESTFIRSTSEARCH_H

#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

#include "ISearcher.h"
#include "Searcher.h"

template <class Node>
class BestFirstSearch : public Searcher<Node>{

    // a class for the priority queue order
    class StateComparator{
    public:
        bool operator()(State<Node>* left, State<Node>* right){
            return (left->getTotalCost() > right->getTotalCost());
        }
    };

public:
    BestFirstSearch(){
        this->evaluatedNodes = 0;
        this->pathCost = 0;
    }

    /*
    * this method reality the Best search first algorithm
    */
    vector<State<Node>*> search(Searchable<Node> *searchable) override {
        this->initialization();
        State<Node>* curS =searchable->getInitState();
        //the end state
        State<Node>* endS =searchable->getGoalState();

        priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> openPQueue;
        curS->setTotalCost(curS->getCost());
        openPQueue.push(curS);

        while (!openPQueue.empty()){
            //see the object in the front of the queue
            curS = openPQueue.top();
            openPQueue.pop();
            //this->evaluatedNodes ++;
            if (!curS->getIsMarked()){
                this->evaluatedNodes ++;
            }
            curS->setIsMarked(true);
            //we check if we arrive the end and found our path
            if(curS->equals(endS)){
                break;
            }

            // get all the possible states that adjacent to current state
            vector<State<Node>*> possibleStates = searchable->getPossibleStates(curS);
            long upToCost = curS->getTotalCost();
            for (int i = 0; i < possibleStates.size(); i++) {
                State<Node>* adj = possibleStates[i];
                // calculate the total path cost for this adj
                long adjFutureTotalCost = adj->getCost() + upToCost;
                // if the total cost is -1- we didnt get to thus node yet;
                if(adj->getTotalCost() == INF || adj->getTotalCost() > adjFutureTotalCost){
                    adj->setCameFrom(curS);
                    adj->setTotalCost(adjFutureTotalCost);
                    // update the queue order
                    if (adj->getTotalCost() > adjFutureTotalCost) {
                        openPQueue = updatePriorityOrder(openPQueue);
                    } else{
                        openPQueue.emplace(adj);
                    }
                }

            }
        }
        return this->findPath(searchable->getGoalState());
    }

    /**
     * this function orders the priority queue
     * @param curQueue
     * @return new priority queue
     */
    priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> updatePriorityOrder
            (priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> curQueue){
        priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> newQueue;
        while (!curQueue.empty()){
            State<Node>* temp = curQueue.top();
            curQueue.pop();
            newQueue.emplace(temp);
        }
        return newQueue;
    }

};

/*
using namespace std;

template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    unordered_set<State<T> *> closed;
    State<T> InitialState;
    State<T> GoalState;

    vector<State<T> *> backTrace() {
        vector<State<T> *>* trace = new vector<State<T> *>;
        State<T> n = this->GoalState;
        while (n.Equals(InitialState)!=0) {
            trace->push_back(&n);
            n = *(n.getCameFrom());
        }
        trace->push_back(&InitialState);
        reverse(trace->begin(), trace->end());
        return *trace;
    }

public:
    BestFirstSearch<T>(){
       this->evaluateNodes=0;
    };

    vector<State<T> *> search(Searchable<T>* searchable) {
        this->InitialState = *(searchable->getInitialState());
        this->GoalState = *(searchable->getGoalState());
        //closed = new unordered_set<State<T>*>;
        this->addOpenList(InitialState);
        while (!this->OpenListIsEmpty()) {
            State<T>* n = this->popOpenList();
            closed.insert(n);
            if (n->Equals(GoalState)) {
                return backTrace();
            }
            list<State<T> *> successors = searchable->getAllPossibleStates(*n);
            for (auto it = successors.begin(); it != successors.end(); ++it) {
                State<T> *temp = *it;
                if (closed.find(temp)!=closed.end() && !temp->getInOpenList()) {
                    //update the parent
                    temp->setCameFrom(*n);
                    //update the cost
                    temp->setTotalCost(n->getTotalCost() + temp->getCost());
                    //pushing to open list
                    this->addOpenList(*temp);
                } else if (temp->getTotalCost() > n->getTotalCost() + temp->getCost()) {
                    temp->setCameFrom(*n);
                    temp->setTotalCost(n->getTotalCost() + temp->getCost());
                    if (!temp->getInOpenList()) {
                        this->addOpenList(*temp);
                        //if the state already in open just update the cost
                    } else {
                        this->updateOpenList(*temp);
                    }
                }
            }
        }
    }
};

*/

#endif //ADVANCEDPROG2_BESTFIRSTSEARCH_H
