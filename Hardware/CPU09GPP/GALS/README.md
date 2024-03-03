Atmel contains the specifications for the Atmel ATF22V10 & ATF16V8 chips.

Translated from PALASM to CUPL. 

Check the 'CPU09GPP_GAL_Table' to make a selection.

After programming there is a question?
Does the fuse table do what it is programmed to do?

In the TL866II+, import the GPP_xxx.lgc files in the 'Logic IC Test' screen and Test the chip!
For the GPP_3 use GPP_3.lgc (this is a full test, no don't care inputs).
For the GPP_2 use both GPP_2-P1.lgc and GPP_2-P2.lgc (this tests use don't care inputs).
The GPP_1 has to many inputs to test on the TL866II+. 

Works for GAL...., ATF.... and PALCE... chips.
You can even test with a 5V or 3.3V supply.


Comments:
   The TL866II+ vector table can only handle 512 lines.
   Chips with many inputs must therefore be tested in parts
   and with a 'don't care' on inputs that are not used in the function under test.
   The test items are indicated with -P1, -P2 etc.
   If there is no -Px after the GAL name, it is a full test.
   A single equation test vector table for the GPP_1 contains more than 2000 lines.


Remarks:
   Tested by reading/writing to a GoTek and running software from a GoTek.
   Even BOOT the Master.FD-DD.DSK (F 7) and run programs (asmb, basic).



CdeJ

