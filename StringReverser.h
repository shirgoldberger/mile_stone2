//
// Created by shirgold on 06/01/2020.
//

#ifndef MILE_STONE2_STRINGREVERSER_H
#define MILE_STONE2_STRINGREVERSER_H

#include <string>
#include <algorithm>
#include "Solver.h"
using namespace std;
class StringReverser : public Solver<string,string> {
public:
    /*
     * the function returns the reverse of the given string
     */
    virtual string solve(string problem) {
        reverse(problem.begin(), problem.end());
        string solution = problem.c_str();
        return solution;
    }
    Solver* clone(){
      return new StringReverser();
    }
};


#endif //MILE_STONE2_STRINGREVERSER_H