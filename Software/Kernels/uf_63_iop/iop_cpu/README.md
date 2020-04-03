These are the firmware files for the IOP.  Best start always is: kill all .r files and next umake to build the new image.
With tail LIST 10000 is it possible to see if the build went without errors.

s1 iop >HEXFILE, deliveres a S1 HEX file for ROM programming. Under Linux there is this 'srec2bin' utility which converts
the .S1 file, with a specified offset, into a bare binary file. Handy when you use the TL866 programmer.

To check if the IOP is working, give RESET, and look with UniBug at the locations f200-f2ff. All bytes should be zero except
a few on the last line: tasks, terminals and transactions.

Next boot an IOP capable kernel. Before enable the ports with editing /etc/ttylist, one can do
ls -lR / >/dev/tty09 or any port via the IOP. This would prove that the IOP is working properly. Now, by default, all IOP port are initialised @ 38400 baud. I yet need to develop code for the IOP and for 'portbaud', to change the ports baudrate settings.


