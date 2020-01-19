//
// Created by harelfeldman on 1/13/20.
//

#ifndef ADVANCEDPROG2_STATE_H
#define ADVANCEDPROG2_STATE_H

#include <cmath>

/*
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
        this->cost = 0;//stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
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
        this->camefrom = &s;
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
 */
#define INF -1
/*
 * this class represent a state
 */
template <class T>
class State {
    T curState;
    int cost;
    State<T> *cameFrom;
    bool isMarked;
    long totalCost;
    double heuristic;

public:

    /*
     * constructor of state.
     * we initialize the total cost to be -1,
     * the came from to be nullptr
     * snd the isMarked to be false
     */
    State<T>(T state, int cost): curState(state){
        this->curState = state;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->isMarked=false;
        this->totalCost  = INF;
        this->heuristic = 0;
    }

    void setHeuristicValue(double value){
        this->heuristic = value;
    }

    double getHeuristicValue(){
        return this->heuristic;
    }

    /*
     * another constructor of state
     */
    State<T>(T state):curState(state){
        this->cost = 0;
        this->cameFrom = nullptr;
        this->isMarked=false;
    }


    /*
     * this method return true the the 2 state are equals
     */
    bool equals(State<T>* other){
        return this->curState == other->getCurState();
    }

    /*
     * this method set the came from of some state
     */
    void setCameFrom(State<T> *state){
        this->cameFrom = state;
    }

    /*
     * this method return state<T>*, its the from were we came from
     */
    State<T>* getCameFrom() const {
        return this->cameFrom;
    }

    /*
     * this function returns the T state
     */
    T getCurState() const{
        return this->curState;
    }

    /**
     * this function returns the cost of this state
     * @return the cost
     */
    int getCost() const{
        return this->cost;
    }

    /**
     * this function set the cost of a state
     * @param cost the new cost
     */
    void setCost(int cost){
        this->cost = cost;
    }

    /**
     * this function set the mark of a state that symbol if the state is visited
     * @param marked
     */
    void setIsMarked(bool marked){
        this->isMarked=marked;
    }

    /**
     * this function returns the mark of a state.
     * @return if the state is visited
     */
    bool getIsMarked() const{
        return this->isMarked;
    }

    /**
     * this function returns the cost from other cost to this state.
     * @return total cost
     */
    long getTotalCost(){
        return this->totalCost;
    }

    /**
     * this function set the total cost
     * @param upToCost
     */
    void setTotalCost(long upToCost){
        this->totalCost = upToCost;
    }

    bool operator==(const State<T> &other)const{
        return this->getCost() == other.getCost();
    }

    bool operator<(const State<T> &other)const{
        return this->getCost() < other.getCost();
    }

    bool operator>(const State<T> &other)const{
        return this->getCost() > other.getCost();
    }

    bool operator>=(const State<T> &other)const{
        return this->getCost() >= other.getCost();
    }

    bool operator<=(const State<T> &other)const{
        return this->getCost() <= other.getCost();
    }

    bool operator!=(const State<T> &other)const{
        return this->getCost() != other.getCost();
    }

};

#endif //ADVANCEDPROG2_STATE_H
