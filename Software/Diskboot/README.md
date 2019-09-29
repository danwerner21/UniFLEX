This is the code for the boot sector. It has to reside on block 0 of the IDE disk (first block).
It's purpose is to load the OS into memory.

I made a few changes in the code with respect to the SWTPC/GIMIX versions from the past. 

1)   I moved the bootsector code to $0800 in kernel space, that is well above the initial tables that the ROM
     have set up. This area is wiped as soon as the kernel code is started.
     
2)   I added provisions for a delay in the boot process (~ 1.5 sec) In this time one can enter a figure of 0 up to 9
     or give CR or just wait. The entered figure is appended to the basic boot filename. That allows for to boot
     and test different kernel versions quickly.
     
3)   At the end of the bootsector space (upper 16 bytes) there is a simple but efficient partition table.
     The boot process would copy this table over to the kernel at the proper place.
     
     
