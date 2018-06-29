# RPI_GPIO

GPIO programming for Raspberry Pi for GertBoard using C++ programming language.

GPIO means "General Purpose Input/Output" and is a special pin present in 
the chip that can be set as INPUT or OUTPUT and used to move a signal 
HIGH or LOW (in output mode) or to get the signal current status (in INPUT mode).

Usually these pin are directly managed by kernel modules but there are 
an easy way to manage these pins also from user space. 

Modern Architecture allows CPU to operate in two modes......USER MODE and 
Kernel MODE. Therefore, the virtual memory can be marked as being part 
of USER SPACE or KERNEL SPACE. 

When running in USER MODE, CPU can access only memory marked as user space 
whereas running in KERNEL MODE, CPU can access both USER and KERNEL memory space.
