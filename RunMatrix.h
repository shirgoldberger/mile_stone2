//
// Created by shirgold on 15/01/2020.
//
#ifndef MILE_STONE2_RUNMMATRIX_H
#define MILE_STONE2_RUNMMATRIX_H
#include <fstream>
#include <vector>
#include <string>
#include "Point.h"
#include "ISearchable.h"
#include "Searcher.h"
#include "MySerialServer.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "Solver.h"
#include "StringReverser.h"
#include "Matrix.h"
#include "AStar.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearch.h"
using namespace std;
class RunMatrix {
 public:
  /*
   * the function run specific algorithm on specific matrix
   */
  static double runAlgorithm(ISearchable<Point *> *matrix, Searcher<Point *, string> *search);
  /*
   * the function run all the algorithms with the given matrix
   */
  static vector<double> runAllAlgorithm(ISearchable<Point *> *matrix, vector<Searcher<Point *, string> *> searcher);
  /*
   * the function read matrix from file
   */
  static string readFromFile(string file);
  static void returnResults() {
    // read matrix
    string m1 = readFromFile("matrix1.txt");
    string m2 = readFromFile("matrix2.txt");
    string m3 = readFromFile("matrix3.txt");
    string m4 = readFromFile("matrix4.txt");
    string m5 = readFromFile("matrix5.txt");
    string m6 = readFromFile("matrix6.txt");
    string m7 = readFromFile("matrix7.txt");
    string m8 = readFromFile("matrix8.txt");
    string m9 = readFromFile("matrix9.txt");
    string m10 = readFromFile("matrix10.txt");

    // create matrix
    ISearchable<Point *> *matrix1 = new Matrix(m1);
    ISearchable<Point *> *matrix2 = new Matrix(m2);
    ISearchable<Point *> *matrix3 = new Matrix(m3);
    ISearchable<Point *> *matrix4 = new Matrix(m4);
    ISearchable<Point *> *matrix5 = new Matrix(m5);
    ISearchable<Point *> *matrix6 = new Matrix(m6);
    ISearchable<Point *> *matrix7 = new Matrix(m7);
    ISearchable<Point *> *matrix8 = new Matrix(m8);
    ISearchable<Point *> *matrix9 = new Matrix(m9);
    ISearchable<Point *> *matrix10 = new Matrix(m10);


    //searchers
    Searcher<Point *, string> *aStar = new AStar<Point *, string>();
    Searcher<Point *, string> *BestFS = new BestFirstSearch<Point *, string>();
    Searcher<Point *, string> *dfs = new DFS<Point *, string>();
    Searcher<Point *, string> *bfs = new BFS<Point *, string>();

    // vector of searchers
    vector<Searcher<Point *, string> *> searchers;
    searchers.push_back(aStar);
    searchers.push_back(BestFS);
    searchers.push_back(bfs);
    searchers.push_back(dfs);


    // results
    vector<double> result1 = runAllAlgorithm(matrix1, searchers);
    vector<double> result2 = runAllAlgorithm(matrix2, searchers);
    vector<double> result3 = runAllAlgorithm(matrix3, searchers);
    vector<double> result4 = runAllAlgorithm(matrix4, searchers);
    vector<double> result5 = runAllAlgorithm(matrix5, searchers);
    vector<double> result6 = runAllAlgorithm(matrix6, searchers);
    vector<double> result7 = runAllAlgorithm(matrix7, searchers);
    vector<double> result8 = runAllAlgorithm(matrix8, searchers);
    vector<double> result9 = runAllAlgorithm(matrix9, searchers);
    vector<double> result10 = runAllAlgorithm(matrix10, searchers);

    delete (matrix1);
    delete (matrix2);
    delete (matrix3);
    delete (matrix4);
    delete (matrix5);
    delete (matrix6);
    delete (matrix7);
    delete (matrix8);
    delete (matrix9);
    delete (matrix10);
    delete (aStar);
    delete (bfs);
    delete (dfs);
    delete (BestFS);

  }
};

#endif //MILE_STONE2_RUNMMATRIX_H
