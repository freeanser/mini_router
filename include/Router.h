// include/Router.h

#ifndef ROUTER_H
#define ROUTER_H

#include "RoutingTable.h"
#include "ArpTable.h"
#include <string>

class Router
{
private:
  RoutingTable routing;
  ArpTable arp;

public:
  Router(); // 可在 ctor 放入少量初始值，或留空

  void forwardPacket(const std::string &dstIP) const;

  // 允許 main.cpp 增加資料
  void addRoute(const std::string &dstIp, const std::string &nextHopIp);
  void addArp(const std::string &ip, const std::string &mac);
};

#endif
