//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__MYCLIENTHANDLER_H_
#define MILE_STONE2__MYCLIENTHANDLER_H_

#include <vector>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "ISearchable.h"
#include "Point.h"

using namespace std;

class MyClientHandler : public ClientHandler {
    Solver<ISearchable<Point *> *, string> *solver;
    CacheManager<string, string> *file_cache;

    virtual void handleClient(int socket);

public:
    // constructor
    MyClientHandler(Solver<ISearchable<Point *> *, string> *solver_, CacheManager<string, string> *cache) {
        this->solver = solver_;
        this->file_cache = cache;
    }

    ClientHandler *clone();
};

#endif //MILE_STONE2__MYCLIENTHANDLER_H_
