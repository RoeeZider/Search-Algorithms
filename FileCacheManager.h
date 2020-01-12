//
// Created by roee on 09/01/2020.
//

#ifndef ADVANCEDPROG2_FILECACHEMANAGER_H
#define ADVANCEDPROG2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <unordered_map>
#include <string.h>

#include <fstream>
#include "FileCacheManager.h"

using namespace std;
template<typename P, typename S>

class FileCacheManager :public CacheManager<P,S>  {
    std::unordered_map<P,S> cacheMap;
    hash<std::string> hasher;
     //bool isSolved=false;
     //in the constractor??
    // int limit_size=5;
public:
    virtual bool IsSolutionExist(P problem);
    virtual S getSolution(P problem) ;
    virtual void saveSolution(S solution,P problem) ;
};



template<class P, class S>
bool FileCacheManager<P, S>::IsSolutionExist(P problem) {
    //check if the problem exist in files
    if (cacheMap.find(problem) != cacheMap.end()) {
        return true;
    }

    size_t hash = hasher(problem);
    ifstream file(to_string(hash),ios::in);
    if (!file) return false;
    file.close();
    return true;
}

template<class P, class S>
S FileCacheManager<P, S>::getSolution(P problem) {
    S solution;
    auto item=cacheMap.find(problem);
    //if the solution in cache
    if(item != cacheMap.end()) {
        return item->second;
    }
    else {
        size_t hash = hasher(problem);
        ifstream file(to_string(hash));
        if(!file) {
            throw "There isnt solution for this problem";

        }
        //read from file the solution
        file.read((char *) &solution, sizeof(solution));
        file.close();
    }
    return solution;
}

template<class P, class S>
void FileCacheManager<P, S>::saveSolution(S solution, P problem) {

    size_t hash = hasher(problem);
    //insert to cache
    cacheMap[to_string(hash)] = solution;
    //insert to file
    ofstream outFile(to_string(hash), std::ios::binary);
    if (!outFile) {
        throw" cannot open the file";
    }
    outFile.write((char *) &solution, sizeof(solution));
    outFile.close();

}
#endif //ADVANCEDPROG2_FILECACHEMANAGER_H
