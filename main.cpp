#include <iostream>
using namespace std;



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;

}


/*
 *  MySerialServer* s = new MySerialServer();
  CacheManager<string, string>* fileCache= new FileCacheManager<string, string>();
  Solver<string,string>* solver = new StringReverser();
  Searcher<Point*,string> * bfs = new BestFirstSearch<Point*,string>();
  Solver<ISearchable<Point*>*,string> *solverS = new SolverSearch<ISearchable<Point*>*,string,Point*>(bfs);
  ClientHandler *c  = new MyClientHandler(solverS,fileCache);
  s->open(12346, c);
 */