//
// Created by roee on 16/01/2020.
//

#ifndef ADVANCEDPROG2_MYPARALLELSERVER_H
#define ADVANCEDPROG2_MYPARALLELSERVER_H

#include <queue>
#include <thread>
#include "Server.h"
using namespace std;
using namespace server_side;
class MyParallelServer : Server{

    queue<thread> myThreads;

public:

};


#endif //ADVANCEDPROG2_MYPARALLELSERVER_H
