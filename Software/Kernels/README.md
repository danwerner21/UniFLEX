Here are the UniFLEX kernel versions.

uf_63_1 is the first kernel in native 6309 mode. Some functions use 6309 instructions, but there is a lot to win.

uf_63_1 supports the following devices:

c 0 x   ttyx  tty ports 0...4

c 1 0   smem  kernel memory

c 1 1   pmem  virtual memory

c 2 0   null  EOF on read, 'Blackhole' on write

c 2 1   zero  read '0' bytes, no write

c 2 2   random read pseudo random numbers, no write

c 3 x   wcx   character drivers for IDE disks 0...7

b 0 x   wx    block device  for IDE disks 0...7
