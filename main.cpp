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
#include "Dfs.h"
#include "BreadthFS.h"
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
            CacheManager<string, string> *fileCache = new FileCacheManager();


            ISearcher<Point>* aStarAlgo = new AStar<Point>();
            ISearcher<Point>* bestFS = new BestFirstSearch<Point>();
            ISearcher<Point>* dfs = new DFS<Point>();
            ISearcher<Point>* bfs = new BreadthFS<Point>();

            SolverMatrix m1(aStarAlgo);
            SolverMatrix m2(bestFS);
            SolverMatrix m3(dfs);
            SolverMatrix m4(bfs);

            MyClientHandler c1(m1, fileCache);
            MyClientHandler c2(m2, fileCache);
            MyClientHandler c3(m3, fileCache);
            MyClientHandler c4(m4, fileCache);

            auto *server=new MyParallelServer();

            //The A* algorithm is the best!!
           server->open(port,&c1);

            delete(aStarAlgo);
            delete(bestFS);
            delete(dfs);
            delete(bfs);
            return 0;
        }
    };
}

int main(int argc, char** argv) {
    boot::Main m;
    m.main(argc, argv);
    return 0;
}

