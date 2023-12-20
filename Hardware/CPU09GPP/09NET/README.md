
 This is the new 09NET module

 
 ![09NET-board](./20231220_092242.jpg)
 
* works with CPU09GPP
* works with UniFLEX kernel with 'sockets' added to kernel
* wzdrvr should be in boot image

The module in combination with the CPU09GPP provides TCP/IP communications
for UniFLEX 6X09. The software however is tailored for the HD63C09 CPU.

The mdule provides up to 8 socket connections.
The network connection is UTP
In the kernel a few Berkely calls are added:

socket(), connect, bind() and listen(), so that both client and server
applications can be served.

Also a socklib.r is being created, that allows the Mc Cosh C compiler to
build programs with networking capabilities.
