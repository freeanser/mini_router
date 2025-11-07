// include/RoutingTable.h
#ifndef ROUTING_TABLE_H
#define ROUTING_TABLE_H

#include <unordered_map>
#include <string>
using namespace std; // (Note: generally avoid this in headers)

class RoutingTable
{
private:
  unordered_map<string, string> table; // Destination IP → Next Hop IP

public:
  void addRoute(const string &dstIp, const string &nextHopIp); // Add or update a route
  bool lookup(const string &dstIp, string &nextHopIp) const;   // Find next hop by destination
};

#endif