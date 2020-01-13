//
// Created by harelfeldman on 1/13/20.
//

#ifndef ADVANCEDPROG2_SEARCHABLE_H
#define ADVANCEDPROG2_SEARCHABLE_H

#include <list>
#include "State.h"

using namespace std;
template<class T>
class Searchable {
    State<T> getInitialState()=0;
    State<T> getGoalState()=0;
    list<State<T>> getAllPossibleStates(State<T> s)=0;

};
#endif //ADVANCEDPROG2_SEARCHABLE_H
