//
// Created by harelfeldman on 1/15/20.
//

#include <unistd.h>
#include <algorithm>
#include "MyClientHandler.h"
#include "FileCacheManager.h"

using namespace std;

MyClientHandler::MyClientHandler(SolverMatrix solver) : solver(solver) {
    this->cache = new FileCacheManager<Matrix, string>(matrix_test.txt);
}

void MyClientHandler::handleClient(int socket) {
    vector<vector<State<Point> *>> matrix;
    Point init;
    Point goal;
    vector<State<Point> *> rowVec;
    while (true) {
        char buffer[4096] = {0};
        //receive massage
        int valRead = read(socket, buffer, 1500);
        if (valRead == 0) {
            break;
        }
        int i = 0;
        int j = 0;
        string rowStr = string(buffer);
        while (rowStr.compare("end\n") != 0) {
            int pos = rowStr.find('\n');
            //rowStr is a row
            rowStr = rowStr.substr(0, pos);
            //remove spaces
            rowStr.erase(std::remove(rowStr.begin(), rowStr.end(), ' '), rowStr.end());
            int p = rowStr.find(',');
            int c = min(p, pos);
            //p is the position of ",' and pos the position of the end of rowStr
            while (p < pos && p > -1) {
                //num is number in rowStr
                string num = rowStr.substr(0, c);
                double cost = stod(num);
                //create Point and State from current num location in row and the number of the row
                Point temp = Point(i, j);
                State<Point> st = State<Point>(temp, cost);
                //push to vector
                rowVec.push_back(&st);
                //erase the number to get the next one
                rowStr.erase(0, c);
                //get the next number
                p = rowStr.find(',');
                c = min(p, pos);
                j++;
            }
            j = 0;
            i++;
            rowStr = string(buffer);
            matrix.push_back(rowVec);
            rowVec.clear();
        }
        //get the init and goal points from matrix
        int initI = matrix[i - 2][0]->getCost();
        int initJ = matrix[i - 2][1]->getCost();
        int goalI = matrix[i - 1][0]->getCost();
        int goalJ = matrix[i - 1][1]->getCost();
        init = Point(initI, initJ);
        goal = Point(goalI, goalJ);
        //erase this two vectors
        matrix.erase(matrix.end() - 1);

        //create searchable matrix
        Matrix *MyMatrix = new Matrix(matrix, init, goal);
        string messege;
        // if the problem is already exists
        if (this->cache->IsSolutionExist(*MyMatrix)) {
            messege = this->cache->getSolution(*MyMatrix);
        } else {
            //send the problem to solvermatrix
            messege = this->solver.solve(MyMatrix)+"\n";
        }
        strcpy(buffer,messege.c_str());
        valRead=write(socket,buffer,strlen(buffer));

        if (valRead < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        close(socket);
    }

}