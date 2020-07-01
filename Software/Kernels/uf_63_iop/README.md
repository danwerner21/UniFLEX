This is the newer version of the kernel files. They support the CPU09IOP IO processor.

/dev/tty00 ... /dev/tty08 are assigned for serial ports in the kernel address space (CPU09MON + 2x CPU09SR4)
/dev/tty09 ... /dev/tty24 are assigned for serial ports via the IOP (CPU09IOP + up to 4x CPU09SR4)

It is assumed that the utility 'update_all" is copied/linked to the name 'umake'

This kernel code can build for a kerel with IDE only with the script "do_make", result is uniflex-IDE
it can also build a kernel with IDE and IOP , provided you set the options in sysconfig.h correct, result is also uniflex-IDE.

After changes in the IOP ROM firmware code, kill the binary 'iop' and run umake

CPU09_UF_IOP.dsk.zip: diskimage with sources. 
On the root of the image are prebuild kernels: uniflex4 (IDE only) and uniflex5 (IDE + IOP)

All the files for a UniFLEX with full IOP support are now uploaded to this archive

Steps for building a complete kernel:
in mach_m1/sysconfig.h  set IDE 1, and IOP 1, no need to have others set
in mach_iop run umake
in kernel   run do_kernel
in mach_m1  run do_make
look at the result, on screen should not be any error
copy the new kernel to the root where it can be bootted, i.e. cp uniflex-IDE /uniflex2

in iop_cpu  kill iop and run umake
s1 iop >IOPHEX

upload this HEX file (Kermit)
srec2bin hexfile into binfile (Linux) for the programmer

After reset: look with Unibug at memory locations F200-F2FF, they should be mostly 00 except a few locations at the end.

Boot the IOP capable kernel, i.e. uniflex2. 

Try ttyset for the IOP serial ports, tty09 and up.

Try cat >/dev/tty09, type something  and look if data appears on that port.

edit ttylist to enable the ttys on the IOP

NOTE: if you have enabled tty's 9 and above and you boot a non_IOP kernel, 'init' will keep trying
to get those working (need to fix /etc/init). Edit /etc/ttylist to switch of those tty's and reboot.



