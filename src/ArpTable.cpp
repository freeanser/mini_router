// src / ArpTable.cpp
#include "ArpTable.h"

void ArpTable::addEntry(const string &ip, const string &mac)
{
  table[ip] = mac;
}

bool ArpTable::resolve(const string &ip, string &mac) const
{
  auto it = table.find(ip);
  if (it == table.end())
    return false;
  mac = it->second;
  return true;
}
