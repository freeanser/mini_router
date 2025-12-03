// include/Router.h
#ifndef ROUTER_H
#define ROUTER_H

#include "RoutingTable.h"
#include "ArpTable.h"
#include <string>
#include <iostream>

// Define packet structure: Simulates Layer 3 (IP) encapsulated within Layer 2 (MAC)
struct Packet
{
  // Layer 3 Header Info
  std::string srcIp;
  std::string dstIp;
  int ttl; // Time To Live: Used to simulate TCP/IP Lifecycle

  // Layer 2 Header Info (Encapsulation)
  std::string srcMac;
  std::string dstMac;

  // Payload
  std::string payload;
};

class Router
{
private:
  RoutingTable routing; // Layer 3 Routing Logic
  ArpTable arp;         // Layer 2 ARP Logic
  std::string myMac;    // Router's MAC address

public:
  Router();
  // Receive a Packet object instead of a simple string
  void forwardPacket(Packet &packet);
  void addRoute(const std::string &dstIp, const std::string &nextHopIp);
  void addArp(const std::string &ip, const std::string &mac);
};

#endif