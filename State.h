//
// Created by harelfeldman on 1/13/20.
//

#ifndef ADVANCEDPROG2_STATE_H
#define ADVANCEDPROG2_STATE_H

#include <cmath>

template<class T>
class State {
private:
    T state;
    double cost;
    State<T> *camefrom;
    double totalCost;
    bool inOpenList;
public:
    State<T>(T s){
        this->state = s;
        this->cost = 0;
        this->camefrom = nullptr;
        this->totalCost=-1;
        this->inOpenList=false;
        this->totalCost=0;
    };
    State<T>(T s,double costa){
        this->state = s;
        this->cost = costa;
        this->camefrom = nullptr;
        this->totalCost=-1;
        this->inOpenList=false;
        this->totalCost=0;
    };

    bool Equals(State<T> s){
        return state.Equals(s.state);
    };

    void setTotalCost(double c){
        this->totalCost = c;
    };
    double getTotalCost(){
        return this->totalCost ;
    };

    void setCameFrom(State<T>& s){
        this->camefrom = s;
    };
    double getCost(){
        return this->cost;
    };
    State<T>* getCameFrom(){
        return this->camefrom;
    };
    void setInOpenList(){
        this->inOpenList=true;
    };
    bool getInOpenList(){
        return inOpenList;
    };
   T get_state(){
       return this->state;
   };
};

#endif //ADVANCEDPROG2_STATE_H
