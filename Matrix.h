//
// Created by harelfeldman on 1/14/20.
//

#ifndef ADVANCEDPROG2_MATRIX_H
#define ADVANCEDPROG2_MATRIX_H

#include <vector>
#include "Searchable.h"
#include "Point.h"

class Matrix : Searchable<Point> {
private:
    State<Point> *initState;
    State<Point> *goalState;
    vector<vector<State<Point> *>> matrix;
public:
    Matrix(vector<vector<State<Point> *>> matrix) {
        this->matrix = matrix;
        this->initState = matrix[0][0];
        this->goalState = matrix[matrix.size() - 1][matrix[0].size() - 1];

    };

    State<Point> *getInitialState() {
        return this->initState;
    };

    State<Point> *getGoalState() {
        return this->goalState;
    };

    list<State<Point> *> getAllPossibleStates(State<Point> &state) {
        int x = state.get_state().getI();
        int y = state.get_state().getJ();
        list<State<Point> *> possibleStates;
        // iterating 8 neighbors of the current state
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; y++) {
                if ((i != x || j != y) && (isValid(i, j)))
                    possibleStates.push_back(this->matrix[i][j]);
            }
        }
        return possibleStates;
    };
    //checks if a neighbor is in the matrix and the state is not with infinite cost.
    bool isValid(int i, int j) {
        if ((i >= 0 && i < this->matrix.size()) && (j >= 0 && j < this->matrix[0].size()) {
            if (this->matrix[i][j]->getCost() != INFINITY) {
                return true;
            }
        }
        return false;
    }

};

#endif //ADVANCEDPROG2_MATRIX_H
