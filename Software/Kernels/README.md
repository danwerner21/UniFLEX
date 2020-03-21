Here are the UniFLEX kernel versions.

uf_63_1 is the first kernel in native 6309 mode. Some functions use 6309 instructions, but there is a lot to win.

Your kernel may support the following devices:

c 0 x   ttyxx  tty ports 00...08

c 1 0   smem  kernel memory

c 1 1   pmem  virtual memory

c 2 0   null  EOF on read, 'Blackhole' on write

c 2 1   zero  read '0' bytes, no write

c 2 2   random read pseudo random numbers, no write

c 3 x   wcx   character drivers for IDE disks 0...7

c 4 0   hwgetset  helper device for portbaud,  get/set baudrate on serial ports

c 5 x   ttyxx  tty ports 09 and up, via IOP

b 0 x   wx    block device  for IDE disks 0...7


All files are in UniFLEX text format, use 'ufless' to access them from linux.
The .tar image contains the whole source for the CPU09 UniFLEX kernel, in UniFLEX text format
