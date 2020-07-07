Here are the UniFLEX kernel versions.

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

On the image CPU09_UF_IOP.dsk.zip there are 3 bootable kernels. 'uniflex' and 'uniflex4' are kernels for SR4 IO.
'uniflex5' support SR4 IO _and_ the IOP. If you boot the last one without the CPU09IOP hardware present, the kernel may hang
in the interrupt handler as it 'sees' the interrupt flag set, but is un-able to reset it.

UF_IOP_200509.dsk.zip is the recent status. It has the most recent driver source tree in it as the latest version of portbaud.
bootable kernels" uniflex (IDE basic version), uniflex2 (with IOP drivers in it)


2020-07-07:  usrc_63 is the most recent kernel tree. By settings options in .../mach_m1/sysconfig.h the user can select
             the desired kernel version. i.e. with or without IOP. 

It is advised to only boot a kernel which your hardware configuration (at boot time) supports,  other the boot may
'hang' because the kernel can't handle the interrupts that it sees on it's IO locations.

uf20200707.dsk.zip contains a few bootable kernels:
- uniflex               IDE kernel, supports CPU09SR4 boards
- uniflex1              same, backup of former
- uniflex2              IDE kernel with IOP support, IOP supports CPU09SR4 boards
- uniflex9              IDE kernel which drops straight in /bin/sh

Note: edit /ect/ttylist after booting, disable tty09...tty12 if you don't have IOP and reboot after



