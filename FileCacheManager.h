//
// Created by roee on 09/01/2020.
//

#ifndef ADVANCEDPROG2_FILECACHEMANAGER_H
#define ADVANCEDPROG2_FILECACHEMANAGER_H

#include <unordered_map>
#include <fstream>
#include <mutex>
#include "CacheManager.h"

using namespace std;


class FileCacheManager : public CacheManager<string, string> {
    // <problem, solution>
    unordered_map<string, string> map;
    hash<string> hasher;
    mutex mutex_;

public:

    virtual bool isSolved(string problem) {
        //mutex_.lock();
        if (exist(problem)) {
            //mutex_.unlock();

            return true;
        }
        return false;
    }

    virtual string getSolution(string problem) {
        //mutex_.lock();
        // if the key doesn't exist
        if (!exist(problem)) {
            throw "Error: The key doesn't existing";
        }
        // read object from file
        string solution = this->readObj(problem);
        //mutex_.unlock();

        return solution;
    }

    virtual void saveSolution(string problem, string &solution) {
        // will always be string
        //mutex_.lock();
        size_t hash = hasher(problem);
        ofstream outFile(to_string(hash));
        if (!outFile) {
            throw "File create error";
        }
        outFile << solution;
        outFile.close();
        map[problem] = hash;
        //mutex_.unlock();
    }

    string readObj(string problem) {
        //mutex_.lock();
        string solution = "";
        size_t hash = hasher(problem);
        ifstream inFile(to_string(hash));
        if (!inFile) {
            throw "Can't open file";
        }
        string line;
        // read solution
        while (inFile >> line) {
            solution += line;
        }
        inFile.close();
        //mutex_.unlock();
        return solution;

    }


    inline bool exist(const std::string &name) {
        if (this->map.find(name) != this->map.end()) {
            return true;
        }
        size_t hash = hasher(name);
        ifstream file(to_string(hash));
        if (!file) {         // If the file was not found, then file is 0, i.e. !file=1 or true.
            return false;    // The file was not found.
        } else {             // If the file was found, then file is non-0.
            return true;     // The file was found.
        }
    }

};
/*
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

    size_t hash = hasher(problem+"");
    //insert to cache
    cacheMap.insert(to_string(hash),solution);
    //insert to file
    ofstream outFile(to_string(hash), std::ios::binary);
    if (!outFile) {
        throw" cannot open the file";
    }
    outFile.write((char *) &solution, sizeof(solution));
    outFile.close();

}
 */
#endif //ADVANCEDPROG2_FILECACHEMANAGER_H
