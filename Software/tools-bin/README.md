Here some native UniFLEX programs which are very handy.


************************************************************************************************

'use2'  a slightly modified version of the use screen editor, this one runs also via the IOP.
It needs a correct /etc/termcap file entry  for it to work.


************************************************************************************************

'formatfd' is a UniFLEX diskette formatter. It's capabilities should match that of the 
flpdrvr.t in the kernel tree and that of gppflpdrv.t in the gpp_flp branch
 

************************************************************************************************

tar   is a UniFLEX executable that handles _uncompressed_ tar archive files.
tar: usage  tar [-]{txruc}[vwfblm][0-7[lmh]] [tapefile] [blocksize] file1 file2..


************************************************************************************************
                                    format

Format a disk for system use.

SYNTAX

     /etc/format [ +Bdfl LmMnPqrv J

Options

B              Write boot sector only. Do not format disk.
d=<devicename> Format the device file name>.
f=blocs>       Establish blocks> fdn Blocks.
l=file name>   Take bad sector addresses from file name>.
L              Take bad sector addresses from terminal.
m=<model code> Use <model code> for disk parameters.
M              Take disk parameters from terminal.
n              Do not prompt for information on disk volume.
p              Prompt for disk parameters.
q              Use quiet mode.
r=(swap>       Reserve <swap> cylinders for swap space.
V              Verify disk after fomnatting.
D              Destroy, just erase the disk
O              unbiased sectors, no filesystem (msdos exchange)
S              unbiased sectors, UniFLEX filesystem
I              Use Interleaved sector arrangement on track

************************************************************************************************

'flexmulti' is a program simular to the 'flex' utility on UniFLEX. But this version can read
a multitude of diskette formats in a real floppy drive. 
 'flexmulti.s1' is the S1 hex formatted version of 'flexmulti'

************************************************************************************************

'losetup' is the (first) version of the tool for the new loop device.

losetup /dev/loopx  <disk_image_file>

will make the <disk_image_file> available as a block device under UniFLEX. All blockdevice
tools (diskrepair, blockcheck, fdncheck, devcheck, mkfs, mount, umount) can be applied on this 
device.

It is also possible to use a FLEX diskimage, but that CAN NOT BE MOUNTED. The tool 'flexloopx'
however can access the files in the image. flexloop0 will show the directory of the FLEX-image
made avialable on /dev/loop0.

************************************************************************************************

'rm' is a more user friendly version of the 'kill' program. It can do recursive removel of
files AND directories. 

This 'rm' version need also the 'rmdir' program to function.

************************************************************************************************


'mount' and 'umount' are essentially Unix variants. They maintain the '/etc/mtab' file to register
the status of mounted devices.


************************************************************************************************

* UniFLEX Disk Format Program
*
* usage: ++ mkfsu +nsdrfqB
* where:
*    mkfs2 - The name of the format program.
*
*    options:
*      +n - Don't prompt the user for the volume information
*      +d - Specify the [block] device to be formatted
*           Given as "+d=XXXX"
*      +r - Specify the number of swap blocks !!
*           Given by "+r=NNNNNN", where NN is a decimal number
*      +f - Specify the number of FDN blocks
*           Given by "+f=NN", where NN is a decimal number
*      +q - Don't issue the verification prompt.
*      +B - Don't actually format the disk - Only rewrite
*           the boot sector.
*      +s - Specify the total number of disk blocks for this
*           filesystem.


************************************************************************************************
