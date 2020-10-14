As this sourcefile contains macros for relamsb, this must be assembled with relasmb.

I created a small UniFLEX diskimage with makeuffs and mount that under Fuse. Put the
source files on it, unmount and mount it with SWTPCemu. There use the relasmb.
relasmb +ls unibugall.t >unibugall.list, next s1 unibugall.r >unibugall.S1
Stop SWTPCemu, remount the image with Fuse, retrieve the .s1/.S1 file for the
programmer.


