//
// Created by eliadsellem on 1/6/20.
//
#include <unordered_map>
#include <fstream>
#include <mutex>
#include "CacheManager.h"

using namespace std;
#ifndef MILE_STONE2__FILECACHEMANAGER_H_
#define MILE_STONE2__FILECACHEMANAGER_H_

class FileCacheManager : public CacheManager<string, string> {
    // <problem, solution>
    unordered_map<string, string> map;
    hash<string> hasher;
    mutex m1;
    mutex m2;
    mutex m3;

public:

    virtual bool isSolved(string problem) {
        m1.lock();
        if (exist(problem)) {
            m1.unlock();

            return true;
        }
        return false;
    }

    virtual string getSolution(string problem) {
        m2.lock();
        // if the key doesn't exist
        if (!exist(problem)) {
            throw "Error: The key doesn't existing";
        }
        // read object from file
        string solution = this->readObj(problem);
        m2.unlock();

        return solution;
    }

    virtual void saveSolution(string problem, string &solution) {
        // will always be string
        m3.lock();
        size_t hash = hasher(problem);
        ofstream outFile(to_string(hash));
        if (!outFile) {
            throw "File create error";
        }
        outFile << solution;
        outFile.close();
        map[problem] = hash;
        m3.unlock();
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

#endif //MILE_STONE2__FILECACHEMANAGER_H_
