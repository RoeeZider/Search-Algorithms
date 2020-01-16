#include <iostream>
#include <vector>
#include "MySerialServer.h"
#include "CacheManager.h"
#include "stringReverser.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "Point.h"
#include "Searcher.h"
#include "SolverMatrix.h"
#include "MyClientHandler.h"
#include "AStar.h"
#include "BestFirstSearch.h"

namespace boot {
    class Main{
    public:
        int main(int argc, char** argv){
            int port;
            // the port number is in argv[1]
            if(argc > 1){
                port = stoi(argv[1]);
            } else{
                // port number not found
                return 0;
            }
            // the A* algorithm is the best!!!
            Searcher<Point>* BFS = new BestFirstSearch<Point>();
            SolverMatrix m(BFS);
            MyClientHandler c(m);
            MySerialServer server;
            server.open(port,&c);
            delete(BFS);
            return 0;
        }
    };
}

int main(int argc, char** argv) {
    boot::Main m;
    m.main(argc, argv);
    return 0;
}

