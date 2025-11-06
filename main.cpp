#include "Router.h"

int main()
{
  Router r;

  // 也可自行新增資料以測試
  r.addRoute("10.0.0.9", "192.168.1.2");
  r.addArp("192.168.1.99", "AA:BB:CC:DD:EE:99");

  r.forwardPacket("10.0.0.2"); // 走 192.168.1.1
  r.forwardPacket("10.0.0.9"); // 走 192.168.1.2
  r.forwardPacket("10.0.1.1"); // 沒有路由

  return 0;
}
