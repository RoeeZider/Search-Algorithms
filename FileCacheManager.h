//
// Created by roee on 09/01/2020.
//

#ifndef ADVANCEDPROG2_FILECACHEMANAGER_H
#define ADVANCEDPROG2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <map>
#include <fstream>
#include <mutex>

#define DELIMITER  '$'

using  namespace std;

/*
 * thus class represent a manager that responsible on a file cache
 * its have the ability to check is some problem and her solution are found in the
 * file already and return the answer or to write a new problem and solution in the file
 */
template <class P, class S>
class FileCacheManager : public CacheManager<P,S>{
    map<string,string> pAndS;
    string fileName;
    mutable mutex m;

public:
    /*
     * constructor of fileCacheManager
     */
    FileCacheManager(string fileName){
        this->fileName = fileName;
        loadFromFile();
    };

    /*
     * this method check if some problem exist in the file
     * return true if the problem exists false otherwise
     */
    bool IsSolutionExist(P problem) override{
        unique_lock<mutex> ul(m);
        bool result = this->pAndS.find(problem) != pAndS.end();
        ul.unlock();
        return result;
    };

    /*
     * this method return from the file the solution as string
     */
    string getSolution(P problem) override {
        if(isSolutionExist(problem)){
            unique_lock<mutex> ul(m);
            string str = this->pAndS.at((string)problem);
            ul.unlock();
            return str;
        }
        perror("The solution of this problem not found");
        string s;
        return s;
    };

    /*
     * this save the problem and her solution to the file,if hey are ot exist
     */
    void saveSolution(P problem, S solution) override{
        if (!isSolutionExist(problem)){
            unique_lock<mutex> ul(m);
            this->pAndS.insert(make_pair(problem,solution));
            ul.unlock();
            saveToFile(problem, solution);
        }
    };


    /*
    * this method write to the file the problem and the solution with a separator $ between them
    */
    void saveToFile(P problem, S solution){
        ofstream outFile;
        outFile.open(this->fileName, ios::out | ios::app | ios::ate);
        if (!outFile.is_open()){
            perror("error opening file");
            exit(1);
        }
        unique_lock<mutex> ul(m);
        outFile << (string)problem << DELIMITER << (string)solution << endl;
        ul.unlock();
        outFile.close();
    };

    /*
     * this method load the information of the problem and the solution from the file to the map in the program
     */
    void loadFromFile(){
        ifstream inFile;
        inFile.open(this->fileName);

        //problem with opening the file
        if (inFile.bad()){
            perror("error opening file");
            exit(1);
        }

        //run over the lines in the file
        unique_lock<mutex> ul(m);
        for(string line; getline(inFile, line);){

            unsigned long splitIndex = line.find(DELIMITER);
            string problem = line.substr(0, splitIndex);
            string solution = line.substr(splitIndex+1, line.size() - problem.size() -1);
            this->pAndS.insert(make_pair(problem, solution));

        }
        ul.unlock();
        inFile.close();
    };

    ~FileCacheManager() override = default;


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
