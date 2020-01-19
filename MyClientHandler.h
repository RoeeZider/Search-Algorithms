//
// Created by harelfeldman on 1/14/20.
//

#ifndef ADVANCEDPROG2_MYCLIENTHANDLER_H
#define ADVANCEDPROG2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Matrix.h"
#include "SolverMatrix.h"
#include <iostream>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include "Searchable.h"
#define BUFFER_SIZE 1024
class MyClientHandler : public ClientHandler{
    //Solver< Searchable<Point>*, string>* solver;
    CacheManager<string, string>* cm;
    SolverMatrix solver;
    //SocketCommunication socketCommunication;

    string getSolution(Matrix matrix);
public:
    MyClientHandler(SolverMatrix solver);
    void handleClient(int socket) override;
    Matrix* lexer(string str);
    vector<string> split (const string &str,char delimiter);
    string readFromSocket(int socket, string separator);
    void writeToSocket(int socket, string data);
    string readFromSocket(int socket, char separator);
    ~MyClientHandler() override;
};

// constructor
MyClientHandler::MyClientHandler(SolverMatrix solver) : solver(solver) {
   // this->cm = &cacheManager;
}

/**
 * this function handle the client with reading the problem and returning the solution for the problem.
 * @param socket client socket
 */
void MyClientHandler::handleClient(int socket) {
    //read the problem
    string str = readFromSocket(socket, "end\n");
    Matrix *matrix = this->lexer(str);
    // write the solution
    writeToSocket(socket, getSolution(*matrix) + "\n");
    close(socket);
    vector<vector<State<Point> *>> mat = matrix->getMatrix();
    for (int i = 0; i < matrix->getRows(); i++) {
        for (int j = 0; j < matrix->getCols(); j++) {
            delete (mat[i][j]);
        }
    }
    delete (matrix);
}

/**
 * this function get a matrix and return the solution for this matrix.
 * if the problem is already exists, the function will return the solution from the cache manager.
 * @param matrix the matrix
 * @return string that represent the solution
 */
string MyClientHandler::getSolution(Matrix matrix) {

    // if the problem is already exists
    if (this->cm->IsSolutionExist(matrix)) {
        return this->cm->getSolution(matrix);
    }
    // solve the problem
    string solution = this->solver.solve(&matrix);
    // save the problem and its solution
    this->cm->saveSolution(solution,matrix);
    return solution;
}

/**
 * the function takes the string , split it, and made a matrix from it.
 * @param str string to made the matrix
 * @return matrix
 */
Matrix *MyClientHandler::lexer(string str) {
    vector<string> splitStr = split(str, '\n');
    unsigned long vecSize = splitStr.size();
    // take the init point and goal point
    vector<string> initIndex = split(splitStr[vecSize - 2], ',');
    vector<string> goalIndex = split(splitStr[vecSize - 1], ',');

    Point init(stoi(initIndex[0]), stoi(initIndex[1]));
    Point goal(stoi(goalIndex[0]), stoi(goalIndex[1]));

    vector<vector<State<Point> *>> matrix;
    // for each cell, made a state with the same i,j and the value in this place that represent the cost.
    for (int i = 0; i < vecSize - 2; i++) {
        vector<string> values = split(splitStr[i], ',');
        vector<State<Point> *> row;
        for (int j = 0; j < values.size(); j++) {
            row.push_back(new State<Point>(Point(i, j), stoi(values[j])));
        }
        matrix.push_back(row);
    }
    return new Matrix(matrix, init, goal);
}

/**
 * this function takes a string and each section between the delimiter put in the vector.
 * @param str  a string
 * @param delimiter the char to split
 * @return the splited string in a vector
 */
vector<string> MyClientHandler::split(const string &str, char delimiter) {
    vector<string> tokens;
    string token;

    for (unsigned long i = 0; i < str.length(); i++) {
        // skip on spaces
        if (str.at(i) == ' ') {
            continue;
        }

        if (str.at(i) != delimiter) {
            token += str.at(i);
        } else {
            tokens.push_back(token);
            token = "";
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

MyClientHandler::~MyClientHandler() {
    delete this->cm;
}

void MyClientHandler::writeToSocket(int socket, string data) {
    int n;
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    strcpy(buffer, data.c_str());

    /* Send message to the server */
    n = write(socket, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

string MyClientHandler::readFromSocket(int socket, char separator) {
    char c = '\0';
    int n;
    string data;

    if (socket < 0) {
        perror("ERROR socket not found");
    }

    n = read(socket, &c, 1);
    while (c != separator) {
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        data += c;
        n = read(socket, &c, 1);
    }

    return data;
}

string MyClientHandler::readFromSocket(int socket, string separator) {
    string data;
    string temp = readFromSocket(socket, '\n');
    temp += '\n';
    while (temp != separator) {
        data += temp;
        temp = readFromSocket(socket, '\n');
        temp += '\n';
    }
    return data;
}
#endif //ADVANCEDPROG2_MYCLIENTHANDLER_H
