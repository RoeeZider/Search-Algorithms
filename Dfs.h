//
// Created by roee on 15/01/2020.
//

#ifndef ADVANCEDPROG2_DFS_H
#define ADVANCEDPROG2_DFS_H

#include "Searcher.h"
#include <stack>

using namespace std;

/*
 * this class represent a BFS that is kind of search algorithm that heir from Searcher
 */
template<class Node>
class DFS : public Searcher<Node> {

public:
    DFS();

    vector<State<Node> *> search(Searchable<Node> *searchable) override;
};

template<class Node>
DFS<Node>::DFS(): Searcher<Node>() {
    this->evaluatedNodes = 0;
    this->pathCost = 0;
}


/*
* this method reality the DFS algorithm
*/
template<class Node>
vector<State<Node> *> DFS<Node>::search(Searchable<Node> *searchable) {
    this->initialization();
    State<Node> *curS = searchable->getInitState();
    State<Node> *endS = searchable->getGoalState();

    stack<State<Node> *> stackDfs;

//the algorithm marked the first state
    curS->setIsMarked(true);

//put the first state at the queue
    stackDfs.push(curS);

//while the stack is not empty we want to go the adj
    while (!stackDfs.empty()) {
//see the object in the top of the stack
        curS = stackDfs.top();
//take the object in the top of the queue
        stackDfs.pop();

//        this->evaluatedNodes++;

//we check if we arrive the end and found our path
        if (curS->equals(endS)) {
            break;
        }

/*
 * now we get all the adj of the curS-point.
 * if we arrive to adj that is not marked,we visit him ,marked him,and push
 * to the stackDfs.
 */
        vector<State<Node> *> possibleStates = searchable->getPossibleStates(curS);
        for (int i = 0; i < possibleStates.size(); i++) {
            State<Node> *temp = possibleStates[i];
            if (!temp->getIsMarked()) {
                temp->setIsMarked(true);
                temp->setCameFrom(curS);
                stackDfs.push(temp);
                this->evaluatedNodes++;

            }
        }

    }
    return this->findPath(searchable->getGoalState());
}


#endif //ADVANCEDPROG2_DFS_H
