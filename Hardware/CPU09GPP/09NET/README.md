
 This is the new 09NET module

 
 ![09NET-board](./20240228_190554.jpg)
 
* works with CPU09GPP 
* works with UniFLEX kernel with 'sockets' added to kernel  ../NET/..
* wzdrvr/wzdev/socket should be in kernel boot image  ../NET/..

The module in combination with the CPU09GPP provides TCP/IP communications
for UniFLEX 6X09. The software however is tailored for the HD63C09 CPU.

The module provides up to 8 socket connections.

The network connection is UTP connector.

In the kernel a few Berkely (TCP/IP) calls are added:

socket(), connect(), bind() and listen(), accept(), read(), write(), close,
recvfrom(), sendto().
so that both client and server applications can be served.

Additionally recfrom() and sendto() calls (UDP) are also implemented

Also a socklib.r is being created, that allows the Mc Cosh C compiler to
build programs with networking capabilities.

2024-02-28:
(*) The photo is NOT from the latest board, but one will notice hardly any 
difference with the final board other than the Revision: 1.0

New GALS patterns for the networking board. (G1 and G3)
Holes for W5500 and 20MHz oscillator are enlarged.

Artwork and component positions completely re-done and fix incorporated.

