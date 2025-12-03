// src/Router.cpp
#include "Router.h"
#include <iostream>
using namespace std;

Router::Router()
{
  // Initialize Routing Table and ARP Table
  routing.addRoute("10.0.0.2", "192.168.1.1");
  routing.addRoute("10.0.0.3", "192.168.1.2");
  arp.addEntry("192.168.1.1", "AA:BB:CC:DD:EE:01");
  arp.addEntry("192.168.1.2", "AA:BB:CC:DD:EE:02");

  // Set the router's own MAC address
  myMac = "AA:BB:CC:DD:EE:01";
}

void Router::addRoute(const string &dstIp, const string &nextHopIp)
{
  routing.addRoute(dstIp, nextHopIp);
}

void Router::addArp(const string &ip, const string &mac)
{
  arp.addEntry(ip, mac);
}

// [Core Modification] Simulate TCP/IP Lifecycle and Encapsulation
void Router::forwardPacket(Packet &packet)
{
  cout << "\n[Router] Ingress: Packet destined for " << packet.dstIp << endl;
  cout << "         Current TTL: " << packet.ttl << endl;

  // --- 1. TCP/IP Lifecycle Check (TTL Aging) ---
  // Simulate Network Layer lifecycle: Drop packet if TTL expires
  if (packet.ttl <= 1)
  {
    cout << "x Dropped: TTL expired (Lifecycle ended)." << endl;
    return; // Packet lifecycle ends
  }
  packet.ttl--; // Perform TTL decrement

  // --- 2. Layer 3 Routing Lookup ---
  string nextHopIp;
  if (!routing.lookup(packet.dstIp, nextHopIp))
  {
    cout << "x Dropped: No Route found for " << packet.dstIp << endl;
    return;
  }
  cout << "-> L3 Routing Decision: Next hop is " << nextHopIp << endl;

  // --- 3. Layer 2 ARP Resolution ---
  string nextHopMac;
  if (!arp.resolve(nextHopIp, nextHopMac))
  {
    cout << "x Dropped: ARP Resolution failed for " << nextHopIp << endl;
    return;
  }

  // --- 4. Encapsulation (System-level Operation) ---
  // Simulate router rewriting Layer 2 Header:
  // Update Source MAC to the router itself, Destination MAC to the next-hop device
  packet.srcMac = this->myMac;
  packet.dstMac = nextHopMac;

  cout << "[Forwarding] Packet forwarded successfully!" << endl;
  cout << "             L2 Header Updated -> SrcMAC: " << packet.srcMac
       << " | DstMAC: " << packet.dstMac << endl;
  cout << "             L3 Header Updated -> TTL: " << packet.ttl << endl;
}