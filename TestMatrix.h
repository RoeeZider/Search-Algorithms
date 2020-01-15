//
// Created by gal on 14/01/2020.
//
#include "Matrix.h"
#include <vector>
#include <string>
#include <fstream>
#include "BestFirstSearch.h"
#include "Dfs.h"
#include "BestFirstSearch.h"
#include "AStar.h"
#include "BreadthFS.h"


#ifndef EX4_TESTMATRICES_H
#define EX4_TESTMATRICES_H
using namespace std;
class TestMatrices {
    vector<vector<State<Point>*>>  randomMatrix(int row, int col) {
        vector<vector<State<Point>*>> matrix;
        for (int i = 0; i < row; ++i) {
            vector<State<Point>*> row;
            for (int j = 0; j < col; ++j) {
                int r = rand() % 5;
                if (r == 0) r = 1;
                if (i == j && i % 2 == 0) r = -1;
                row.push_back(new State<Point>(Point(i,j), stoi(r)));            }
            matrix.push_back(row);
        }
      //  matrix[row - 1][col - 1] = to_string(rand() % 10 + 1);
        //matrix[0][0] = to_string(rand() % 10 + 1);
       // matrix.push_back({"0", "0"});
        //matrix.push_back({to_string(row - 1), to_string(col - 1)});
        return matrix;
    }

    void writeMatrix(vector<vector<string>> matrix, fstream &graphs) {
        for (int i = 0; i < matrix.size() - 2; i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (j != matrix[0].size() - 1) {
                    graphs << matrix[i][j] << ",";
                } else {
                    graphs << matrix[i][j];
                }
            }
            graphs << "\n";
        }
    }
public:
    void testAndWriteToFiles() {
        // save to file each problem and solution.
        fstream graphs, solutions;
        graphs.open("graphs.txt", std::ofstream::out | std::ofstream::trunc);
        solutions.open("solutions.txt", std::ofstream::out | std::ofstream::trunc);
        int i = 40, j = 40;
        graphs << "10\n";
      //  auto *bfs = new BestFirstSearch<pair<int, int>>();
       // auto *dfs = new BreadthFS<pair<int, int>>();
        Searcher<Point>* aStarAlgo = new AStar<Point>();
       // auto *bestfirst = new Dfs<pair<int, int>>();
        for (i; i <= 50; i += 5, j += 5) {
            graphs << to_string(i) << endl;
            graphs << "0,0" << endl;
            graphs << to_string(i - 1) << "," << to_string(i - 1) << endl;
            vector<vector<string>> matrix = randomMatrix(i, j);
            writeMatrix(matrix, graphs);

       //     string res1 = solve<pair<int, int>>(matrix,bestfirst);
            string res2 = solve<pair<int, int>>(matrix,aStarAlgo);
         //   string res4 = solve<pair<int, int>>(matrix,bfs);
          //  string res3 = solve<pair<int, int>>(matrix,dfs);

            solutions << to_string(bestfirst->getNumOfNodesEvaluated()) << ","
                      << endl;
            solutions << to_string(dfs->getNumOfNodesEvaluated()) << ","  << endl;
            solutions << to_string(bfs->getNumOfNodesEvaluated()) << ","  << endl;
            solutions << to_string(aStarAlgo->getNumberOfNodesEvaluated())<< endl;

        }
        graphs.close();
        solutions.close();
        // free algs
        delete(bfs);
        delete(dfs);
        //delete(astar);
        delete(bestfirst);

    }
    template<class T>
    string solve(vector<vector<string>> lines,Searcher<T> *searcher) {
        // init matrix into nre searchable
        Point* p = new Point(0,0);
        Point* p1 = new Point(49,49);
        Searchable<T> *matrix = new Matrix(lines,p,p1);
        // find path- from start to goal state
        vector<State<T> *> path = searcher->search(matrix);
        // return the result in string of directions
        return to_string(searcher->getNumOfNodesEvaluated());
    }
};


#endif //EX4_TESTMATRICES_H