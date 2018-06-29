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

        Pinout of Raspberry Pi GPIO
        ---------------------------
        3V3(1)          (2)  5V  

        GPIO(3)         (4)  5V    

        GPIO3(5)        (6)  GND   

        GPIO4(7)        (8)  GPIO14

GND         (9)         (10) GPIO15

GPIO17    (11)       (12) GPIO18

GPIO27    (13)       (14) GND   

GPIO22    (15)       (16) GPIO23

3V3           (17)       (18) GPIO24

GPIO10    (19)       (20) GND   

GPIO9      (21)       (22) GPIO25

GPIO11    (23)       (24) GPIO8 

GND         (25)       (26) GPIO7 

GPIO0      (27)       (28) GPIO1 

GPIO5      (29)       (30) GND   

GPIO6      (31)       (32) GPIO12

GPIO13    (33)       (34) GND   

GPIO19    (35)       (36) GPIO16

GPIO26    (37)       (38) GPIO20

GND         (39)       (40) GPIO21
