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

