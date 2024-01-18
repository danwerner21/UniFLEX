
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


