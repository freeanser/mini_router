// src/RoutingTable.cpp
#include "RoutingTable.h"

void RoutingTable::addRoute(const string &dstIp, const string &nextHopIp)
{
  table[dstIp] = nextHopIp;
}

bool RoutingTable::lookup(const string &dstIp, string &nextHopIp) const
{
  auto it = table.find(dstIp);
  if (it == table.end())
    return false;
  nextHopIp = it->second;
  return true;
}
