## UniBug

Here is the code for the UniBug ROM that is to e used with the CPU09 system. It is in a CR/LF delimiter format.

The ROM provides a few basic functions. It provides the basic serial comminication with the console port.

<pre>
The supported commands are:
C,  configure. Checks the RAM pages and size and the fuctioning of the system timer
E, examine memory. Enable hex/ascii dump of memory area's
M, examine and change. Provide a simple single memory location show, next, previous and change function
V, set mapper page D. When followed by a 2 digit hex character that page is mapped in at $D000-$DFFF.
J, jump to execute. Will start a program at the 4 hex value typed after the 'J'. 
D, disk boot. After typing the 'D', the program waits for about 2 seconds, In that time a '0' or '1' may be typed
   as drive select from which it will boot.
</pre>

The ROM code provides the context switching between processes and kernel on interrupt.

UNIBUG.S1 if the hex file as it comes from the assembler, but in Linux text format. 
UBUG_H.S1 is the same file but gaps in the code are filled with FF, so this is the exact
code what should go into the (E)PROM.
