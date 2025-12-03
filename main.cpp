// main.cpp
#include "Router.h"
#include <iostream>

int main()
{
  Router r;

  // Set additional routes and ARP entries
  r.addRoute("10.0.0.9", "192.168.1.2");
  r.addArp("192.168.1.99", "AA:BB:CC:DD:EE:99");

  std::cout << "=== Test Case 1: Normal Forwarding ===" << std::endl;
  // Create packet: Source, Destination, TTL=64, Payload...
  Packet p1 = {"192.168.1.50", "10.0.0.2", 64, "", "", "Hello Data"};
  r.forwardPacket(p1);

  std::cout << "=== Test Case 2: TTL Expired (Lifecycle Simulation) ===" << std::endl;
  // Create a packet nearing expiration (TTL=1)
  Packet p2 = {"192.168.1.50", "10.0.0.9", 1, "", "", "Old Packet"};
  r.forwardPacket(p2);

  std::cout << "=== Test Case 3: No Route ===" << std::endl;
  Packet p3 = {"192.168.1.50", "10.0.1.1", 64, "", "", "Lost Packet"};
  r.forwardPacket(p3);

  return 0;
}