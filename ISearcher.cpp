//
// Created by harelfeldman on 1/13/20.
//

#include "ISearcher.h"
ISearcher::ISearcher(){
    evaluateNodes=0;
}

int ISearcher::getNumberOfNodesEvaluated() {
    return evaluateNodes;
}
