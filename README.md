# UniFLEX
an UniFLEX  compatible hardware/software project on Eurocards

Some of us know it, your first love remains forever. In the early 80's I came involved with 6809 UniFLEX from T.S.C. Because
the SWTPC hardware was not suitable for 24-7 I got to design an Eurocard based system that was for a large part on the SWTPC design but had some additions, kernel bug fixes, extra kernel drivers and kernel extensions. (i.e. named pipes)

The resulting hardware has run UniFLEX for many years without failure, that is the hardware never failed but the 5 1/4 Winchester
disks did, they barely reached one year with 24-7 operation.
In that time the SASI interface was used but now we have/had IDE/PATA and SATA.

Some months ago it started itching and I started to re-design the CPU board as the first one. The original one had a DATRAM that would allow to re-map memory for processes in 4K blocks, but the DATRAM could only hold one process map. Context switching was
expensive. My new design has a dual ported RAM that will store the maps for 64 processes all at once. Context switching is disable/enable a latch now. Furthermore the CPU board has a crash protection. No user process is able to bring down the OS.
I choose to use no SMT components but DIP20, DIP40, DIP14, DIP16 etc. In the (unlikely) event that someone likes it and want to 
build and experiment with the hard- and software, I feel it is better not to challenge the soldering skills too much.

I will post all design files and schematics for the boards in the near future when I have completed the tests. 

The next board will be the MON-itor board, it contains up to 1 MByte static RAM, 2K ROM, an ACIA for console via RS232, a PIA for printer, timer control and memory trap. It also provides the main address decoding for te system. The memory trap will catch addressing of non-existing memory for read and write. Any access to it results in an abort of the responsible process and give a core dump. When reading from 'non-existent' memory, the resulting data is $3F, this will produce a trap also.

In the works is further an IDE interface, DMA driven. The design is finished and a board can be made. I expect not that it will
work the first time. We will see. 

I plan (for myself) also to build a Floppy/DMA interface. I have plenty of floppies from that era with a lot of software.
That floppy controller with WD2793 and 68B44 will e able to read (and write) a large mix of diskette formats (8"/5 1/4", 3 1/2")
in various sides and densities. The kernel driver is clever enough to detect most of the formats (even 40 track in an 80 track dive with double step)

I think of building an harddisk-image file that one can drop on an IDE disk and after that would be able to boot UniFLEX.

In the various archives there is still a lot of software for UniFLEX available. A 2MHz system can deliver a nice performance and digging into the corners of software and hardware has learned me so much about OS and hardware solutions.

With my system in th 80s and 90's we had ported OS9 level1 to UniFLEX :-) It would run as a task. Also Motorola MDos from the Exorciser was ported and would run under UniFLEX.

We ported the FLEX debugger to UniFLEX and gave it some extra features like a system-call trap. It is in my archives.
A number of Unix utilities were ported too (with adaptations for i.e permissions) at, atrun, basename, cat, cmp, cron, crypt, ls, pstat, cu, login, su, find, grep, uniq, units, and a lot more ran very well. One guy here made a port of C-Kermit, it is in my archives.

#############################################################################################

Why would I do this all? First it is fun, it was in those days too. Second, I am getting older (70) and I have a lot of information about these systems in documentation and in knowlegde. I would like to get it immortal. Here on the Internet, for anyone to explore and experience the fun and excitement while doing that. 
#############################################################################################

As more people get involved we could add some simple networking, SD card interface and so on. And yes the boards will have GAL's to minimize discrete logic. That was the reason for my Perlblast project. I will make all deisgn files for the GAL's available too.

I hope I may complete this project in time :-))



