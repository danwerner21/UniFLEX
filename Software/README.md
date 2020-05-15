Here are the kernel versions, other special files and UniFLEX utilities

basic_uf_sys.dsk.zip is a image of a 10 MByte filesystem with some swap space. If unzipped first and then
put on an IDE disk starting at block 0, it may boot in an CPU09XXX system

[2020-05-15]
basic_uf_sys.dsk.zip is updated. The image expands to an over 15MByte filesystem. It is basically w0.dsk from Mike's SWPTCemu release, but with other boot kernels, another IPL loader and the /dev/entries corrected.
The shell in /bin understands cd instead of chd :-)
The source tree for kernel build sits in /src/usrc_63.
You can boot 3 different kernels:
* uniflex, an IDE kernel that supports tty00 up to tty08, and drives w0 up to w7
* uniflex2, same a above but additionally handles an IOP and tty09 up totty16
* uniflex9, thsi one drops directly into a shell, no /etc/init involved

Booting a kernel without the corresponding hardware may hang the boot as the kernel believes to see interrupts
from non-existent locations an keep servicing those......
