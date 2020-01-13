//
// Created by roee on 11/01/2020.
//

#ifndef ADVANCEDPROG2_STRINGREVERSER_H
#define ADVANCEDPROG2_STRINGREVERSER_H


#include <string>
#include <algorithm>

using namespace std;

class StringReverser : public Solver<string, string> {
public:
    virtual string solve(string problem) {
        reverse(problem.begin(), problem.end());
        string solution = problem.c_str();
        return solution;
    }
};


#endif //ADVANCEDPROG2_STRINGREVERSER_H

