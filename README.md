# RPI_GPIO

GPIO programming for Raspberry Pi for GertBoard using C++ programming language.

GPIO mean "General Purpose Input/Output" and is a special pin present in 
the chip that can be set as input or output and used to move a signal 
high or low (in output mode) or to get the signal current status (in input mode).

Usually these pin are directly managed by kernel modules but there are 
an easy way to manage these pins also from user space. 

Modern Architecture allows CPU to operate in two modes......USER MODE and 
Kernel MODE. Therefore, the virtual memory can be marked as being part 
of USER SPACE or KERNEL SPACE. 

When running in USER MODE, CPU can access only memory marked as user space 
whereas running in KERNEL MODE, CPU can access both USER and KERNEL memory space.
