// include/Router.h
#ifndef ROUTER_H
#define ROUTER_H

#include "RoutingTable.h"
#include "ArpTable.h"
#include <string>

class Router
{
private:
  RoutingTable routing; // Destination → Next Hop
  ArpTable arp;         // IP → MAC

public:
  Router(); // Constructor
  void forwardPacket(const std::string &dstIP) const;
  void addRoute(const std::string &dstIp, const std::string &nextHopIp);
  void addArp(const std::string &ip, const std::string &mac);
};

#endif