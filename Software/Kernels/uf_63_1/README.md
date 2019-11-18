This kernel, together with the hardware, is resistant against the following 'user process errors':

Illegal instruction execution. Beware that such an error in kernel mode results in a panic->TRAP

Interrupt blocking. If a process blocks interrupts longer then about 13 mS is it detected and terminated.

Illegal memory access. In user mode any access to non-existent memory is trapped and the process is terminated.

The hardware has also provisions to handle changes in the 6309 operation mode but at this moment no action is taken.

All processes are fully protected from each other and from the kernel space.

2019-11-18: Fix in idedrvr.t  Some (MAXTOR) drives raise DRQ whil accessed in PIO mode. Result is that when serviceing 
the  ide interrupt, getting the drive status results in a (unscheduled) DMA cycle. This may erase things like
IRQ vector in the kernel. resulting ultimately in a TRAP. Now disable all DMA when entering IDE interrupt handler.
