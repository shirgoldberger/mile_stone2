//
// Created by shirgold on 13/01/2020.
//

#ifndef MILE_STONE2_MYPARALLELSERVER_H
#define MILE_STONE2_MYPARALLELSERVER_H
#include "Server.h"
#include "MySerialServer.h"
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <vector>
#define LISTENERS 10
using namespace server_side;
class MyParallelServer : public Server {
  vector<thread> threads;
 public:
  MyParallelServer(){
    this->shouldStop = false;
    this->noMoreClients = true;
  }
  virtual void open(int p, ClientHandler *c);
  void start(int client_socket, ClientHandler *c);
  virtual void stop();
  int listeners;
  bool shouldStop;
  bool noMoreClients;
};

#endif //MILE_STONE2_MYPARALLELSERVER_H
