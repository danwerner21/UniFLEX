
As already announced a few times, in recent weeks I was able to 
implement TCP/IP and UDP networking in UniFLEX 6309.

The implementation uses a CPU09GPP+09NET hardware to provide up
to 8 sockets. That may be enough for this environment.

Additionally a socklib.t / socklib.t.r is created which supports
the new socket() calls as weel some addtional functions.

    bzero((char) *address, count);

Clear a block of (user) memory.

    unsigned long inet_addr((char) *p);

Parse an IPV4 address in ascii and return an unisgned long.
Error checking is done on the format.


netserver: is a server that allows to be accessed from another system
via the netblk device. It is a convenient way of transferring data 
quickly between UniFLEX systems.

System A:
netserver -p 30000 -f w0.dsk    __or__      (disk is file)
netserver -p 30000 -f /dev/w01              (disk is device)

System B:
setnbdev -p 30000 -i <IP_of_systemA>

Now on system B you can access the contents of the 'disk'
on System A as was it local via /dev/netblk0

Lin4UF.c is a version of 'netserver' that runs on a Linux system.


