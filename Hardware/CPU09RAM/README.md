CPU09RAM

2023-01-17 under construction, not yet tested

The CPU09RAM is an Eurocard size board with logic and space for up to 8 pieces 
of AS6C4008-55PCN on it, giving a total of 4194304 bytes of volatile storage.

The board provides:
    * up to 4 MB of RAM storage
    * will be located at FEC00...FEFFF in the address range
    * provides RAM access in 512 Byte pages
    * has address latches to select any of the max 8192 available pages
    * has dipswitches that can be read out to inform the driver
    * no DMA, but the HD63X09 has a block move instruction which is very efficient
    * transfer speed over 125 KByte/sec
    * options, with switches, 1 or 2 disk images. 

I created a simple UniFLEX block/char driver for it. The initialization code is 
capable of detecting the size of the RAM devices present, provided that the devices
are placed from the first to the last in adjacent order.

The first device is to be U4 and the last device U11. 2 16V8 GAL's serve for 
address decoding, bus signal buffering and device selection.

The 2 x 4 position dipswitches can be used to signal the driver and initialization
code to act on it. i.e. Skip size check on power-on reset or skip re-building
the filesystems.

As the memory is volatile, the contents are lost on power off. But the RAM disk
can be very helpful when you run from an SD-card. Copy your work over to the RAM disk,
run edit and assembly on the RAM disk contents and save results back to SD-card 
when done. This will prevent the SD-card to wear-out much less.

The design process is interesting to mention. It started as a pop-up board for
a CPU09GPP. That board could hold 4 AS6C4008-55PCN devices. I wrote some code for 
the GPP part and could use flpdrvr.t at the kernel side. It worked well.
Next was moving the pop-up board to a CPU09FLX board. Immediately I regretted
that I had not put all address lines A0...A9 on that board, so I added the
missing lines with wires. Now I had to write a new block driver for it, but
that turned out not to be complicated. It is fast too.
When I looked to the combo of CPU09FLX and 09RAMDSIK I realized that a single
board was possible and also the best solution. which I now did. 

As for options I can imagine: 
    * one disk to the full  available size. (512KB min and 4 MB max)
    * one 1MB disk for mounting on /tmp and the remainder for general use
    * don't touch contents at /reset
    *


