//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__MATRIX_H_
#define MILE_STONE2__MATRIX_H_

#include "Searchable.h"
#include "Point.h"

class Matrix : public Searchable<Point *> {
  // all the states in the matrix
  vector<vector<State<Point *> *>> vertexes;

 public:
  // constructor
  Matrix(string problem) {
    vector<string> lines = splitLines(problem);
    setMatrix(lines);
  }
  /*
   * the function returns one step of the solution:
   * where we go (left, right, down and up) and what is the trial cost
   */
  virtual string printOne(State<Point *> *s) {
    State<Point *> *father = s->getCameFrom();
    Point *fatherPoint = father->getT();
    Point *sonPoint = s->getT();
    if (fatherPoint->getX() > sonPoint->getX()) {
      return "Up(" + to_string(s->getTrialCost()) + "), ";
    }
    if (fatherPoint->getX() < sonPoint->getX()) {
      return "Down(" + to_string(s->getTrialCost()) + "), ";
    }
    if (fatherPoint->getY() > sonPoint->getY()) {
      return "Left(" + to_string(s->getTrialCost()) + "), ";
    }
    if (fatherPoint->getY() < sonPoint->getY()) {
      return "Right(" + to_string(s->getTrialCost()) + "), ";
    }
    return "not good";
  }

  virtual vector<State<Point *> *> getAllPossibleState(State<Point *> *s) {
    int size = this->vertexes.front().size() - 1;
    vector<State<Point *> *> sons;
    Point *p = s->getT();
    if (p->getX() != size) {
      sons.push_back(vertexes[p->getX() + 1][p->getY()]);
    }
    if (p->getY() != size) {
      sons.push_back(vertexes[p->getX()][p->getY() + 1]);
    }
    if (p->getY() != 0) {
      sons.push_back(vertexes[p->getX()][p->getY() - 1]);
    }
    if (p->getX() != 0) {
      sons.push_back(vertexes[p->getX() - 1][p->getY()]);
    }



    return sons;
  }

  virtual vector<State<Point *> *> getAllState() {
    vector<State<Point *> *> allStates;
    for (vector<State<Point *> *> v : this->vertexes) {
      for (State<Point *> *s : v) {
        allStates.push_back(s);
      }
    }
    return allStates;
  }

  void setMatrix(vector<string> allProblem) {
    int size = allProblem.size();
    string line;
    string substr = "";
    int pos = 0;
    int i, j = 0;
    for (i = 0; i < size - 2; i++) {
      line = allProblem[i];
      vector<State<Point *> *> row;
      while (true) {
        if (line.find(",") < line.find("\n")) {
          substr = line.substr(pos, line.find(","));
          double val = stod(substr);
          Point *p = new Point(i, j);
          State<Point *> *t = new State<Point *>(p, val);
          row.push_back(t);
          line = line.substr(line.find(",") + 1);
          j++;
        } else {
          substr = line.substr(pos, line.find("\n"));
          double val = stof(substr);
          Point *p = new Point(i, j);
          State<Point *> *t = new State<Point *>(p, val);
          row.push_back(t);
          vertexes.push_back(row);
          j = 0;
          break;
        }
      }
    }
    //get start point
    double x, y;
    split(allProblem[i], &x, &y);
    this->setInitialState(vertexes[x][y]);
    //get goal point
    split(allProblem[i + 1], &x, &y);
    this->setGoalState(vertexes[x][y]);
  }

  void split(string line, double *x, double *y) {
    string substr = "";
    double val = 0;
    int pos = 0;
    substr = line.substr(pos, line.find(","));
    val = stod(substr);
    *x = val;
    line = line.substr(line.find(",") + 1);
    substr = line.substr(pos, line.find("\n"));
    val = stod(substr);
    *y = val;
  }

  vector<string> splitLines(string problem) {
    vector<string> lines;
    string line = "";
    for (char c:problem) {
      if (c == ' ') {
        continue;
      }
      line += c;
      if (c == '\n') {
        lines.push_back(line);
        if (line.compare("end\n") == 0) {
          break;
        }
        line = "";
      }
    }
    lines.pop_back();
    return lines;
  }

  virtual void nullify() {
    for (vector<State<Point *> *> s : this->vertexes) {
      for (State<Point *> *t : s) {
        t->setTrailCost(numeric_limits<double>::infinity());
        t->setCameFrom(nullptr);
        t->setFScore(0);
      }
    }
  }

  ~Matrix(){
    for(auto vec:vertexes){
      for(auto state:vec){
        delete(state->getT());
        delete(state);
      }
    }
  }
};

#endif //MILE_STONE2__MATRIX_H_
