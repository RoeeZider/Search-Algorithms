//
// Created by harelfeldman on 1/14/20.
//

#include "Point.h"
#include "SolverMatrix.h"

#define DOWN "Down"
#define UP "Up"
#define RIGHT "Right"
#define LEFT "Left"


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
