// include/RoutingTable.h
#ifndef ROUTING_TABLE_H
#define ROUTING_TABLE_H

#include <unordered_map>
#include <string>
using namespace std;

class RoutingTable
{
private:
  unordered_map<string, string> table; // 目的 IP -> 下一跳 IP

public:
  void addRoute(const string &dstIp, const string &nextHopIp);
  bool lookup(const string &dstIp, string &nextHopIp) const;
};

#endif