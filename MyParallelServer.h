//
// Created by roee on 16/01/2020.
//

#ifndef ADVANCEDPROG2_MYPARALLELSERVER_H
#define ADVANCEDPROG2_MYPARALLELSERVER_H

#include <queue>
#include <thread>
#include "Server.h"
using namespace std;
namespace server_side {
    class MyParallelServer : public Server {

    private:
        int serverSocket;

        void start(int serverSocket, ClientHandler &c);

    public:
        queue<thread> threads_queue;

        MyParallelServer();

        void stop() override;

        void handle(int clientSocket, ClientHandler &c);

        void open(int port, ClientHandler &c);
    };
}

#endif //ADVANCEDPROG2_MYPARALLELSERVER_H
