#include "Router.h"

int main()
{
  Router r;

  // Add additional routes and ARP entries
  r.addRoute("10.0.0.9", "192.168.1.2");
  r.addArp("192.168.1.99", "AA:BB:CC:DD:EE:99");

  r.forwardPacket("10.0.0.2"); // Next hop: 192.168.1.1
  r.forwardPacket("10.0.0.9"); // Next hop: 192.168.1.2
  r.forwardPacket("10.0.1.1"); // No route found

  return 0;
}
