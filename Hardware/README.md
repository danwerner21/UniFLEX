This folder contains the hardware components of my CPU09 system.

If you like to tinker with hardware and UniFLEX or FLEX this system
may be attractive for you. The designs are made such that the boards
will not get damaged quickly and the withstand some level of abuse :-)

For a minimal system you need:
* CPU09BP       this is the system backplane and accomodates up to 7 slots
* CPU09MM3      CPU and memory management
* CPU09MON      provides RAM (1MB), ROM (2K), timer, console port
* CPU09ID6      DMA driven IDE interface, up to 2 drives

Further extentions include:
* CPU09SR4          4 ACIA serial ports, baudrate selection per port
* CPU09GPP          general purpose IO processor, RAM, ROM, timer, IO expansion connector 1K range
* CPU09GPP/09FLP    separate IO processor, with additional WD2793 floppy disk interface
* CPU09IOP          serial IO processor, serves up to 12 ports (3 CPU09SR4)
* CPU09FLX          carrier board for 09FLP, intended for direct IO based floppy access (FLEX)
* CPU09EXP          experimenters board, fully buffered with large prototype area

In development are:
* CPU09VID          512x472 B/W video board.
* CPU09GPP/09ECN    Econet compatible (hardware) interface
* CPU09GPP/09SPI    SD-card / W5500 network interface
* CPU09KDB          kernel space debugger interface
* CPUXXCMI          board for 6802/6809 CPU, 65K RAM, 2K ROM, console port (FLEX)

With a CPUXXCMI, CPU09FLX/09FLP you would have a simple full blown FLEX compatible system

The hardware provides a good UniFLEX capable system, with integrated user/system separation
and protection, no user process can bring down the OS.


Essentials skills: good in soldering!

