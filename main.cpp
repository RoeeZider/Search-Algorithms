#include <iostream>
#include <vector>
#include "MySerialServer.h"
#include "CacheManager.h"
#include "stringReverser.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "Point.h"
#include "Searcher.h"
#include "ISearcher.h"
#include "SolverMatrix.h"
#include "BestFirstSearch.h"
#include "AStar.h"
#include "MyParallelServer.h"
using namespace std;
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
            ISearcher<Point>* aStarAlgo = new AStar<Point>();
            SolverMatrix m(aStarAlgo);
            //FileCacheManager<std::string, std::string> *cache = new FileCacheManager<std::string,std::string>();
            CacheManager<string, string> *fileCache = new FileCacheManager();
            MyClientHandler c(m, fileCache);
            server_side::MyParallelServer server;
           server.open(port,c);
            delete(aStarAlgo);
            return 0;
        }
    };
}

int main(int argc, char** argv) {
    boot::Main m;
    m.main(argc, argv);
    return 0;
}

