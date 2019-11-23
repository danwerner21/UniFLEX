# UniFLEX
an UniFLEX  compatible hardware/software project on Eurocards

Some of us know it, your first love remains forever. In the early 80's I came involved with 6809 UniFLEX from T.S.C. The
SWTPC hardware proved not to be suitable for 24-7, mainly due to the Molex connectors. I got to design an Eurocard based system (CS System) that was influenced for a part on the SWTPC design but had some additions as a DMA SASI interface card, kernel bug fixes, extra kernel drivers and kernel extensions. (i.e. named pipes)

The resulting hardware has run UniFLEX for many years without failure, that is the hardware never failed but the 5 1/4 Winchester disks did, they barely reached one year with 24-7 operation.
In that time the SASI interface was used but now we have/had IDE/PATA and SATA.

Some months ago it started itching and I started to re-design the CPU board as the first one. The original one had a DATRAM that would allow to re-map memory for processes in 4K blocks, but the DATRAM could only hold one process map. Context switching was
expensive. My new design has a dual ported RAM that will store the maps for 64 processes all at once. Context switching is disable/enable a latch now. Furthermore the CPU board has a crash protection. No user process is able to bring down the OS.
The first iteration learned that some things had to change, most particulary the hardware that detects whether the CPU was running as 6809 or 6309. But the intial tests showed that the princicple works. With a HD63C09 it runs smoothly at 4 MHz bus clock!

I choose to use no SMT components but DIP20, DIP40, DIP14, DIP16 etc. In the (unlikely) event that someone likes it and want to 
build and experiment with the hard- and software, I feel it is better not to challenge soldering skills too much.
(OK, only very very few ones, which you normally would not need to have ;-( )

A friend gave me his CS System that he ran professionally up to 1995! It still works, even the SASI Hard disk and it helps me now to recover the missing pieces in knowledge and it is fun to use it again.

I will post all design files and schematics for the boards in the near future when I have completed the tests. 

The next board will be the MON-itor board, it contains up to 1 MByte static RAM, 8K ROM, an ACIA for console via RS232, a PIA for timer control, memory trap and support for the 'lights' status from the UniFLEX kernel. 8 LED's show entering and leaving of critical sections in the kernel. Lastly some IO pins allow for the 2 highest ROM addresses to select. It also provides the main address decoding for te system. The memory trap will catch addressing of non-existing memory for read and write (BLACKHOLE). Any access to it results in an abort of the responsible process and give a core dump. When reading from 'non-existent' memory, the resulting data is $3F, this will produce a trap also. I believe I have figured out a reliable way to use a HD63X09 in native mode for the OS and immume for changes in the operating mode by a user processes (modem access.....) with minor overhead.

In the works is further an IDE interface, DMA driven. The design is finished and a board can be made. I expect not that it will
work the first time. We will see. 2019-04-22: I found that I need to uses other latches in the data path to IDE. Made small
boards that can piggy-back on the orginal sockets and when they arrive I will continue testing. But it looks good.

I plan (for myself) also to build a Floppy/DMA interface. I have plenty of floppies from that era with a lot of software.
That floppy controller with WD2793 and 68B44 will enable to read (and write) a large mix of diskette formats (8"/5 1/4", 3 1/2")
in various sides and densities. The kernel (mine) driver is clever enough to detect most of the formats (even 40 track in an 80 track dive with double step)

I think of building an harddisk-image file that one can drop on an IDE disk and after that would be able to boot UniFLEX.
2019-04-22: I have a working implementation of 'Fuse' under Linux, where I can mount an UniFLEX disk image and access everything with commandline tools and with 'mc' (midnight commander clone). In Fuse I can create, read, write files and also create directories. Next will be rmdir. It has NO protection to concurrent access however, but for building/maintaining a UniFLEX filesystem under Linux it is sufficient. Another tool is makeuffs, that create a valid UniFLEX diskimage under Linux.

In the various archives there is still a lot of software for UniFLEX available. A 2MHz system can deliver a nice performance and digging into the corners of software and hardware has learned me so much about OS and hardware solutions.
I am very curious how the 4MHz HD63C09 in native mode would do. :-)

With my system in the 80s and 90's we had ported OS9 level1 to UniFLEX :-) It would run as a task. Also Motorola MDOS from the Exorciser was ported and would run under UniFLEX.

We ported the FLEX 6809 debugger to UniFLEX and gave it some extra features like a system-call trap. After invocation it would move itself to the top of the 64K space. I tried it recently and it was pleasure working with it.
A number of Unix utilities were ported too (with adaptations for i.e permissions) at, atrun, basename, cat, cmp, cron, crypt, ls, pstat, cu, login, su, find, grep, uniq, units, and a lot more ran very well. One guy here made a port of C-Kermit, it is in my archives.

#############################################################################################

Why would I do this all? First it is fun, as it was in those days too. Second, I am getting older (70) and I have a lot of information and knowledge about these systems. I would like to get it immortal. Here on the Internet, for anyone to explore and experience the fun and excitement while doing that. It is also a BIG tribute to the T.S.C. guys who created this incredible nice
software.
#############################################################################################

As more people get involved we could add some simple networking, SD card interface and so on. And yes the boards will have GAL's to minimize discrete logic. That was the reason for my Perlblast project. I will make all design files for the GAL's available too.

I hope I get enough years to complete this project :-)) It would be a nice learning tool for CS education. The boards are robust
against careless handling which makes it very suitable for handling by students. The whole system, as everything and anything
is open, can be thouroughly examined, modified and extended. It contains many aspects of computing: virtual memory, DMA, IO,
process protection, Interrupts.
It worked for me and others very well in that sense.

One last word of advise: If you plan to build this project, invest in a good soldering iron, if you have it not already!!
