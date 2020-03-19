This is a monitor program that can be used to run the RAM version of the firmware.

IOP_ROM.t is the source file
IOPMONLIST is the assembly listing
IOPROM.S1 is the hex file with gaps filled.

The IOPMON has a couple of commands:

r: show registers
p: print / punch (S1) memory area's
l: load an S1 file
m: memory examine and change
g: got address

The others commands may not work. I believe they are left-overs.  For the intended application of this monitor
program they are irrelevant. I ignored them. The command prompt is '***'.

The IOP application hex image should be prceeded by a 'l' character, this places the monitor in the
'load' program mode, it stays there until an S9 record is read.

The IOP applcaition is started with:
g 405a

If a register dump is shown there is an interrupt active. To overcome this look at the stack pointer value.
Do m <stackpointervalue>   and give SPACE 'd0' thsi should change the CC value in DO.
Check with the 'r' command if this is right. Next, g 405a should now work, that is, no reaction any further.
  
The monitor ACIA is expected to be at $8000, thus the first acia in the first CPU09SR4 via the IO processor.
Badurate is preset at 38400.

  
