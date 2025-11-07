# mini_router
非常好 👍 — 這樣補充非常專業，也更符合你這個 mini-router 專案的教學性質。
下面是更新後的 **README（英文）完整版**，在 *Learning Goals* 區段我已明確加上 **L2 / L3 protocol concepts**（並自然融入前文語氣）：

---

## 🧭 Mini Router Simulator

A lightweight C++ project that simulates how a simple router forwards packets based on a **Routing Table** and an **ARP Table**.
This project is designed for learning basic networking and practicing object-oriented programming (OOP) in C++.

### Features

* **Routing Table** — stores destination IP → next hop IP mappings
* **ARP Table** — stores IP → MAC address mappings
* **Router** — uses both tables to simulate packet forwarding
* **Modular OOP design** — each class is defined and implemented separately
* **Console-based simulation** for clear step-by-step visualization


### Packet Flow Diagram

```
 ┌───────────┐      ┌────────────┐      ┌──────────────┐
 │  Sender   │ ---> │   Router   │ ---> │ Next Hop MAC │
 │ (10.0.0.2)│      │            │      │AA:BB:CC:DD:EE│
 └───────────┘      └────────────┘      └──────────────┘
       |                    |
       | Routing Table       \
       | 10.0.0.2 → 192.168.1.1
       | ARP Table
       | 192.168.1.1 → AA:BB:CC:DD:EE:01
```

**Process Overview:**

1. The router receives a packet with a destination IP.
2. It looks up the **next hop IP** in the Routing Table (Layer 3 – Network).
3. Then it resolves the **MAC address** for that next hop using the ARP Table (Layer 2 – Data Link).
4. If both lookups succeed, the packet is “sent” (printed to console).


### Example Output

```
[Router] Receiving packet destined for 10.0.0.2
-> Next hop: 192.168.1.1
Packet sent to MAC: AA:BB:CC:DD:EE:01

[Router] Receiving packet destined for 10.0.0.9
-> Next hop: 192.168.1.2
Packet sent to MAC: AA:BB:CC:DD:EE:02

[Router] Receiving packet destined for 10.0.1.1
No route found for 10.0.1.1
```

### Build & Run

Make sure you have a C++17-compatible compiler (e.g. `g++` or `clang++`).

```bash
# Compile
make

# Run
make run

# Clean build files
make clean
```

### Learning Goals

* Understand how routers perform **Layer 3 (Network)** routing and **Layer 2 (Data Link)** address resolution
* Learn the roles of **Routing Tables** (L3) and **ARP Tables** (L2) in packet delivery
* Practice **OOP design**, **encapsulation**, and **multi-file structure** in C++
* Get hands-on experience with **network protocol simulation** concepts
* Build confidence in writing maintainable, modular system code
