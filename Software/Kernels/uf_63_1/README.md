This kernel, together with the hardware, is resistant against the following 'user process errors':

Illegal instruction execution. Beware that such an error in kernel mode results in a panic->TRAP

Interrupt blocking. If a process blocks interrupts longer then about 13 mS is it detected and terminated.

Illegal memory access. In user mode any access to non-existent memory is trapped and the process is terminated.

The hardware has also provisions to handle changes in the 6309 operation mode but at this moment no action is taken.

All processes are fully protected from each other and from the kernel space.

