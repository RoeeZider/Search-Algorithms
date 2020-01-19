//
// Created by roee on 16/01/2020.
//

#ifndef ADVANCEDPROG2_MYPARALLELSERVER_H
#define ADVANCEDPROG2_MYPARALLELSERVER_H


#include <vector>
#include <thread>
#include "Server.h"

class MyParallelServer{
    vector<thread> m_threads;
    ClientHandler* m_handler;

private:
    static void clientHandlerObjectFunctionAdapter(ClientHandler* ch, int sockfd);

public:
    MyParallelServer();
    virtual ~MyParallelServer();

    virtual void open(int port, ClientHandler* ch);
    virtual void stop(int sockfd);


};

#endif //ADVANCEDPROG2_MYPARALLELSERVER_H
