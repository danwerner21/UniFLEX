These are the firmware files for the IOP.  Best start always is: kill all .r files and next umake to build the new image.
With tail LIST 10000 is it possible to see if the build went without errors.

s1 iop >HEXFILE, deliveres a S1 HEX file for ROM programming.

To check if the IOP is working, give RESET, and look with UniBug at the locations f200-f2ff. All bytes should be zero except
a few on the last line: tasks, terminals and transactions.

Next boot an IOP capable kernel. Before enable the ports with editing /etc/ttylist, one can do
ls -lR / >/dev/tty09 or any port via the IOP.

