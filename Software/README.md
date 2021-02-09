Here are the kernel versions, other special files and UniFLEX utilities

basic_uf_sys.dsk.zip is a image of a 10 MByte filesystem with some swap space. If unzipped first and then
put on an IDE disk starting at block 0, it may boot in an CPU09XXX system

[2020-05-15]
basic_uf_sys.dsk.zip is updated. The image expands to an over 15MByte filesystem. It is basically w0.dsk from Mike's SWPTCemu release, but with other boot kernels, another IPL loader and the /dev/entries corrected.
The shell in /bin understands cd instead of chd :-)
The source tree for kernel build sits in /src/usrc_63.
You can boot 3 different kernels:
* uniflex, an IDE kernel that supports tty00 up to tty08, and drives w0 up to w7
* uniflex2, same a above but additionally handles an IOP and tty09 up to tty16
* uniflex9, this one drops directly into a shell, no /etc/init involved

Booting a kernel without the corresponding hardware may hang the boot as the kernel believes to see interrupts
from non-existent locations and can't reset these so it is stuck in this loop ...... 
(i.e. booting a IOP-aware kernel without IOP present.)

[USERIO]   2020-05-22
I am researching the concept of 'user-IO'. This is a solution where one can add/remove IO boards to a designated backplane and 
this without desturbing the running kernel. My idea is having a hardware setup as is for the IOP. So a (second) CPU09IOP, but
with completely different ROM and a matching driver in the kernel. The IO side is, for now, completely without interrupts.
The swapping of IO boards is a kind of hot-swap.

From the UniFLEX side a process can open '/dev/userio' for read or read/write. As the IO range is 256 bytes (00-FF) the process
should 'seek' to the desired location and then 'read' or 'write' bytes of data. Of course the speed of response will not be 
very high, but suitable for most control purposes. The other response factor is how busy the kernel is at that moment.

When I have progressed I will publish some numbers here. At this moment the kernel driver begins to function.

[2021-02-09]

basic_uf_sys2A.dsk has dbgio drivers built-in. These drivers may assist in debugging a CPU09GPP type application. I also
updated the SPM09 monitor ROM code

you can boot the following kernels:
uniflex or uniflex   an IDE/DBG kernel
uniflex2             an IDE/IOP/DBG kernel
uniflex4             an IDE/IOP/FLP/DBG kernel
uniflex9             drops straight in /bin/sh

The drivers are now more resillient against hardware not present for the booted kernel.
Also the lastest source tree is present.

