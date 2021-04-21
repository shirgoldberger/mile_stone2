//
// Created by eliadsellem on 1/6/20.
//


#include "MySerialServer.h"
#define OUT_FILE "solution.txt"
void MySerialServer::open(int p, ClientHandler *c) {

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
  if (listen(sockfd, 1) == -1) {
    cerr << "error during listening command" << endl;
  }
  MySerialServer::start(sockfd, address, c);
  //thread listen_thread (start ,sockfd, address ,c);
  close(sockfd);

}
void MySerialServer::start(int sockfd, sockaddr_in address, ClientHandler *c) {
  int iResult, client_socket;
  string bufferOut;
  while (!shouldStop) {
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    struct timeval tv;
    tv.tv_sec = (long) 10;
    tv.tv_usec = 0;
    cout<<"wait"<<endl;

    iResult = select(sockfd + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
    if (iResult > 0) {

      client_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);
    } else {
      cout << "didnt connect" << endl;
      continue;
    }
    if (client_socket == -1) {
      cerr << "Error accepting clinet" << endl;
    }
    c->handleClient(client_socket);
  }
}

void MySerialServer::stop() {
  shouldStop = true;
  //listen_thread.join();
}

