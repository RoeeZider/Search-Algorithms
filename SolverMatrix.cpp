//
// Created by harelfeldman on 1/14/20.
//

#include <iostream>
#include "Point.h"
#include "SolverMatrix.h"

#define DOWN "Down"
#define UP "Up"
#define RIGHT "Right"
#define LEFT "Left"

/*
SolverMatrix::SolverMatrix(Searcher<Point> *searcher) {
    this->searcher = searcher;
}

string SolverMatrix::solve(Searchable<Point> *problem) {
    vector<State<Point> *> solution = this->searcher->search(problem);
    return PathStr(solution);
}


string SolverMatrix::PathStr(vector<State<Point> *>vec) {
    string path;
    for(int i = 0; i < vec.size() -1; i++){
        path += getDirection(vec[i]->get_state(), vec[i+1]->get_state());
        if (i < vec.size() -2){
            path += ',';
        }
    }
    return path;
}

string SolverMatrix::getDirection(Point current, Point next) {
    int cI = current.getI();
    int cJ = current.getJ();
    int nI = next.getI();
    int nJ = next.getJ();

    if (cI < nI) {
        return DOWN;

    } else if (cI > nI) {
        return UP;

    } else if (cJ < nJ) {
        return RIGHT;

    } else {
        return LEFT;
    }
}
*/
SolverMatrix::SolverMatrix(ISearcher<Point> *searcher) {
    this->searcher = searcher;
}

/**
 * this function solve the problem (matrix) with a search algorithm (searcher) and returns the solution.
 * @param problem a problem to solve
 * @return the solution
 */
string SolverMatrix::solve(Searchable<Point> *problem) {
    vector<State<Point> *> solution = this->searcher->search(problem);
    cout<<"path cost: " << solution[solution.size()-1]->getTotalCost()<<endl;
    return getPath(solution);
}


/**
 * thie function takes the path in states, and calculate the path in direction from {up,down,right,left}
 * @param states the solution path
 * @return solution in string
 */
string SolverMatrix::getPath(vector<State<Point> *> states) {
    string path;
    if (states.empty())
        return "-1";


    for (int i = 0; i < states.size() - 1; i++) {
        Point cur(states[i]->getCurState());
        Point next(states[i + 1]->getCurState());
        path += getDirection(cur, next);
        if (i < states.size() - 2) {
            path += ',';
        }
    }

    return path;
}

/**
 * this function calculate from which direction the step from cur state to next state.
 * @param cur current state
 * @param next next state
 * @return the result from {up,down,right,left}
 */
string SolverMatrix::getDirection(Point cur, Point next) {
    int curI = cur.getI();
    int curJ = cur.getJ();

    int nextI = next.getI();
    int nextJ = next.getJ();

    if (curI < nextI) {
        return DOWN;

    } else if (curI > nextI) {
        return UP;

    } else if (curJ < nextJ) {
        return RIGHT;

    } else {
        return LEFT;
    }
}