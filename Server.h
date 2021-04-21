//
// Created by eliadsellem on 1/6/20.
//

#ifndef MILE_STONE2__SERVER_H_
#define MILE_STONE2__SERVER_H_
#include "ClientHandler.h"
namespace server_side {
class Server{
 public:
  virtual void open(int p, ClientHandler* c) = 0;
  virtual void stop() = 0;
  virtual ~Server(){}
};
}
#endif //MILE_STONE2__SERVER_H_
