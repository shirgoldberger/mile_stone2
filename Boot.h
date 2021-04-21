//
// Created by shirgold on 15/01/2020.
//

#ifndef MILE_STONE2_BOOT_H
#define MILE_STONE2_BOOT_H

#include "MySerialServer.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MyParallelServer.h"
#include "RunMatrix.h"
#include "MyClientHandler.h"
#include "SolverSearch.h"
namespace Boot {
    class Main {
    public:
        void main(int port) {
            MyParallelServer *s = new MyParallelServer();
            CacheManager<string,string>* fileCache = new FileCacheManager();
            Searcher<Point *, string> *bestFS = new BestFirstSearch<Point *, string>();
            Solver<ISearchable<Point *> *, string> *solverDfs = new SolverSearch<string, Point *>(bestFS);
            ClientHandler *c = new MyClientHandler(solverDfs, fileCache);
//            RunMatrix* r = new RunMatrix();
//            r->returnResults();
            s->open(port, c);
            delete (s);
            delete (fileCache);
            delete (solverDfs);
            delete (c);
            delete (bestFS);
//            delete(r);

        }
    };
}





#endif //MILE_STONE2_BOOT_H
