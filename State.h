//
// Created by harelfeldman on 1/13/20.
//

#ifndef ADVANCEDPROG2_STATE_H
#define ADVANCEDPROG2_STATE_H
template<class T>
class State {
private:
    T state;
    double cost;
    State<T> camefrom;
public:
    State<T>(T s){
        this->state = s;
        this->cost = 0;
        this->camefrom = nullptr;
    };

    bool Equals(State<T> s){
        return state.Equals(s.state);
    };

    void SetCost(double c){
        this->cost = c;
    };

    void SetCameFrom(State<T> s){
        this->camefrom = s;
    };
};

#endif //ADVANCEDPROG2_STATE_H
