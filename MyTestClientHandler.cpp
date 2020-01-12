//
// Created by roee on 09/01/2020.
//

#include "MyTestClientHandler.h"
/*
 *
Skip to content
Pull requests
Issues
Marketplace
Explore
@RoeeZider
Eliadsellem /
mile_stone2

1
0

    0

Code
Issues 0
Pull requests 0
Actions
Projects 0
Wiki
Security
Insights
mile_stone2/MyTestClientHandler.cpp
@Eliadsellem Eliadsellem replace c3d55e9 2 days ago
42 lines (40 sloc) 1.15 KB
//
// Created by eliadsellem on 1/6/20.
//
#include <unistd.h>
#include <sys/socket.h>
#include "MyTestClientHandler.h"
void MyTestClientHandler:: handleClient(int server_socket){
  while(true) {
    char buffer[1500] = {0};
    //receive massage
    int valRead = read(server_socket, buffer, 1500);
    if(valRead == 0) {
      break;
    }
    string problem = string(buffer);
    problem = problem.substr(0, valRead);

    if (problem.compare("End") == 0) {
      cout << "endddd" << endl;
      close(server_socket);
      break;
    }
    //write the massage into file
    cout << "buffer : " << buffer << endl;
    string solution;
    if(file_cache->isSolved(problem)) {
      solution = file_cache->getSolution(problem);
      cout<<"from file: "<<solution<<endl;
    }else {
      solution = solver->solve(problem);
      file_cache->saveSolution(problem,solution);
    }

    cout<<"solution : "<<solution<<endl;
    char *bufferOut = &solution[0];
    int is_send = send(server_socket, bufferOut, solution.length(), 0);
    if (is_send == -1) {
      cerr << "error sending massage to client" << endl;
    }
    cout << "bufferOut : " << bufferOut << endl;
  }
}

    © 2020 GitHub, Inc.
    Terms
    Privacy
    Security
    Status
    Help

    Contact GitHub
    Pricing
    API
    Training
    Blog
    About


 */