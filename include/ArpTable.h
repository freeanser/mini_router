// include/ArpTable.h
#ifndef ARP_TABLE_H
#define ARP_TABLE_H

#include <unordered_map>
#include <string>
using namespace std;

class ArpTable
{
private:
  unordered_map<string, string> table; // IP -> MAC

public:
  void addEntry(const string &ip, const string &mac);
  bool resolve(const string &ip, string &mac) const;
};

#endif
