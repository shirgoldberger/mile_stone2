//
// Created by shirgold on 13/01/2020.
//

#include <vector>
#include <netinet/in.h>
#include "MyParallelServer.h"
#include "CacheManager.h"
#include "Solver.h"
#include "ISearchable.h"
#include "MySerialServer.h"

void MyParallelServer::open(int p, ClientHandler *c) {
  this->listeners = 0;
  int client_socket, iResult;
  int port = p;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    //error
    cerr << "could'nt open the socket" << endl;
  }
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    cerr << "could'nt bind the socket to an ip" << endl;
  }
//making socket listen to the port
  if (listen(sockfd, LISTENERS) == -1) {
    cerr << "error during listening command" << endl;
  }
  while (!this->shouldStop) {
    //the listeners are full.
    if (listeners >= LISTENERS) {
      continue;
    }
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    struct timeval tv;
    tv.tv_sec = (long) 120;
    tv.tv_usec = 0;

    iResult = select(sockfd + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
    if (iResult > 0) {

      client_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);
      cout<<"connected"<<endl;
      noMoreClients = false;
      listeners++;
    } else {
      if (noMoreClients){
        stop();
        break;
      }
      cout << "didnt connect" << endl;
      continue;
    }
    if (client_socket == -1) {
      cerr << "Error accepting clinet" << endl;
    }
    ClientHandler *client_handler = c->clone();
    threads.push_back(thread(&MyParallelServer::start,this, client_socket, client_handler));
    //start(client_socket, address, client_handler);
    //while the client still sending massage - to "End"
  }
  close(sockfd);
}
void MyParallelServer::start(int client_socket, ClientHandler *c) {

  c->handleClient(client_socket);
  //finish handling the problem.
  cout << "finish handling the client" << endl;

  this->listeners--;
  cout << "listeners " << listeners << endl;
  if(listeners == 0){
    noMoreClients = true;
  }
}

void MyParallelServer::stop() {
  this->shouldStop = true;
  for (thread & th: threads) {
    if(th.joinable()){
      th.join();

    }
  }
}



