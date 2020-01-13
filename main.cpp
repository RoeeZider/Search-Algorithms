#include <iostream>
#include "MySerialServer.h"
#include "CacheManager.h"
#include "stringReverser.h"
#include "MyTestClientHandler.h"

using namespace std;



int main() {
    MySerialServer* s = new MySerialServer();
    CacheManager<string, string>* fileCache= new FileCacheManager<string, string>();
    Solver<string,string>* solver = new StringReverser();
    ClientHandler *c  = new MyTestClientHandler(solver,fileCache);
    s->open(12345, c);
}
