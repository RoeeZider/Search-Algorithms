//
// Created by harelfeldman on 1/14/20.
//

#ifndef ADVANCEDPROG2_PRIORITYQUEUE_H
#define ADVANCEDPROG2_PRIORITYQUEUE_H

#include <queue>
#include "State.h"
using namespace std;

template <class T>
class PriorityQueue{
private:
    vector<State<T>*> vec;
public:
    PriorityQueue<T>(){
    };
    State<T>* pop(){
        State<T>* temp=vec.front();
        vec.erase(vec.begin());
        return temp;
    };

    void push(State<T> &s){
        auto it=vec.begin();
        while (s.getTotalCost() < (*it)->getTotalCost() && it!=vec.end()){
            ++it;
        }
        vec.insert(it,&s);
    };

    bool isEmpty(){
        return vec.empty();
    };
    void update(State<T> s){
        auto it=vec.begin();
        while ((*it)->Equals(s)!=0){
            ++it;
        }
        this->vec.erase(it);
        push(**it);
    }

};

#endif //ADVANCEDPROG2_PRIORITYQUEUE_H
