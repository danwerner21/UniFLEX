This is the newer version of the kernel files. They support the CPU09IOP IO processor.

/dev/tty00 ... /dev/tty08 are assigned for serial ports in the kernel address space (CPU09MON + 2x CPU09SR4)
/dev/tty09 ... /dev/tty24 are assigned for serial ports via the IOP (CPU09IOP + up to 4x CPU09SR4)

It is assumed that the utility 'update_all" is copied/linked to the name 'umake'

This kernel code can build for a kerel with IDE only with the script "do_ide", result is uniflex-IDE
it can also build a kernel with IDE and IOP with the script "do_iop", result is uniflex-IOP.
Next copy uniflex-IOP to /uniflexX where X represents a decimal digit.

After changes in the kernel iop driver code, first run umake in the ./mach_iop directory and next "do_iop"
in the ./mach_m1 directory

After changes in the IOP firmware code, kill the binary 'iop' and run umake

CPU09_UF_IOP.dsk.zip: diskimage with sources. 
On the root of the image are prebuild kernels: uniflex4 (IDE only) and uniflex5 (IDE + IOP)

The IOP processor firmware, in it's current state, builds for use in RAM. I'm waiting my prom programmer and soon
I will be able to test a full (E)(P)ROM version. I will publish all the modifification in the driver files. Currently I have an extra ACIA on the IOP side which is not found and initialised  by the IOP. It serves a MikBug type monitor program and the
monitor can accept an S1 hex file with the (RAM) firmware. Next the monitor should start it.

All the files for a UniFLEX with full IOP support arenow uploaded to this archive

Steps for building a complete kernel:
in mach_iop run umake
in kernel   run do_kernel
in mach_m1  run do_iop
copy the new kernel to the root where it can be bootted

in iop_cpu  kill iop and run umake
s1 iop >IOPHEX
copy IOPHEX to a PC (kermit) and list it back into the monitor ACIA on the IOP side.

After RESET: start the iop firmware first, currently @405a
next boot the IOP compatible kernel
edit ttylist to enable the ttys on the IOP

NOTE: if you have enabled tty's 9 and above and you boot a non_IOP kernel, init will keep trying
to get those working (need to fix /etc/init). Edit /etc/ttylist to switch of those tty's and reboot.
