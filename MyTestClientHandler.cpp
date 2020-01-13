//
// Created by roee on 09/01/2020.
//

#include "MyTestClientHandler.h"
#include <unistd.h>
#include <sys/socket.h>
#include "MyTestClientHandler.h"

#include <string>
#include <iostream>

using namespace std;

void MyTestClientHandler:: handleClient(int server_socket) {
    while (true) {
        char buffer[4096] = {0};
        //receive massage
        int valRead = read(server_socket, buffer, 1500);
        if (valRead == 0) {
            break;
        }
        string problem = string(buffer);
        problem = problem.substr(0, valRead);

        if (problem.compare("end\r\n") == 0) {
            cout << "client send end" << endl;
            close(server_socket);
            break;
        }
        //write the massage into file
        cout << "buffer : " << buffer << endl;
        string solution;
        if (cache->IsSolutionExist(problem)) {
            solution = cache->getSolution(problem);
            cout << "from file: " << solution << endl;
        } else {
            solution = solver->solve(problem);
            cache->saveSolution(problem, solution);
        }

        cout << "solution : " << solution << endl;
        char *bufferOut = &solution[0];
        int is_send = send(server_socket, bufferOut, solution.length(), 0);
        if (is_send == -1) {
            cerr << "error sending massage to client" << endl;
        }
        cout << "bufferOut : " << bufferOut << endl;
    }
}



