// src/Router.cpp

#include "Router.h"
#include <iostream>
using namespace std;

Router::Router()
{
  // 初始化 Routing Table
  routing.addRoute("10.0.0.2", "192.168.1.1");
  routing.addRoute("10.0.0.3", "192.168.1.2");

  // 初始化 ARP Table
  arp.addEntry("192.168.1.1", "AA:BB:CC:DD:EE:01");
  arp.addEntry("192.168.1.2", "AA:BB:CC:DD:EE:02");
}

void Router::addRoute(const string &dstIp, const string &nextHopIp)
{
  routing.addRoute(dstIp, nextHopIp);
}

void Router::addArp(const string &ip, const string &mac)
{
  arp.addEntry(ip, mac);
}

void Router::forwardPacket(const string &dstIP) const
{
  cout << "[Router] Receiving packet destined for " << dstIP << endl;

  string nextHop;
  if (!routing.lookup(dstIP, nextHop))
  {
    cout << "No route found for " << dstIP << endl;
    return;
  }
  cout << "Next hop: " << nextHop << endl;

  string mac;
  if (!arp.resolve(nextHop, mac))
  {
    cout << "No ARP entry for " << nextHop << endl;
    return;
  }

  cout << "Packet sent to MAC: " << mac << endl;
}
