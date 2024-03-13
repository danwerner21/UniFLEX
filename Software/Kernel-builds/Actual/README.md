
This is a near realtime version of my kernel build 

There may (there are!) bugs in the newer networking code, be fore-warned!!!!

But if you want to follow the progress it is a nice place and I wil regularely 
update the contents. It includes also some expermintal excersises.

On Linx:     nc -l  -p 32100 |tar xvf -

On UniFLEX:  tar cvf - usrc_63 |w2sock

It took about 2 and a half minute to transfer 479 files and directories with
a total size of about 3.8 MB, which is a nice speed. We are spoiled by nowadays
blazing speeds that some machines show.

For me it is very rewarding, as the alternatives are much worse.

The current sysconfig.h is setup for: IDE, LOOP, NET, GPPDBG

2024-02-15:

Remodelled the socket calls a bit. Now rcvfrom and sendto (UDP) both work and
can handle 5 parameters in the call.

assembler

    ldd sfdn
    sys sendto,*buffer,count,*sockaddr,sockaddrlen

C
    sendto(sfdn, buffer, count, *server, serveraddrlen);

    ldd sfdn
    sys recvfrom,*buffer,count,*sockaddr,*sockaddrlen

C
    recvfrom(sfdn, buffer, count, *server, *serveraddrlen);


