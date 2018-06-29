# RPI_GPIO

    GPIO programming for Raspberry Pi for GertBoard using C++ programming language.

        BCM_GPIO Pinout of Raspberry Pi 
        -------------------------------
        3V3(1)           (2)  5V  

        GPIO(3)          (4)  5V    

        GPIO3(5)         (6)  GND   

        GPIO4(7)         (8)  GPIO14

        GND (9)          (10) GPIO15

        GPIO17(11)       (12) GPIO18

        GPIO27(13)       (14) GND   

        GPIO22(15)       (16) GPIO23

        3V3   (17)       (18) GPIO24

        GPIO10(19)       (20) GND   

        GPIO9 (21)       (22) GPIO25

        GPIO11(23)       (24) GPIO8 

        GND   (25)       (26) GPIO7 

        GPIO0 (27)       (28) GPIO1 

        GPIO5 (29)       (30) GND   

        GPIO6 (31)       (32) GPIO12

        GPIO13(33)       (34) GND   

        GPIO19(35)       (36) GPIO16

        GPIO2 (37)       (38) GPIO20

        GND   (39)       (40) GPIO21
        
        GPIO stands for "General Purpose Input/Output". It is a special pin found in 
        the chip that can be set as INPUT or OUTPUT and thus used to make a signal 
        HIGH or LOW (in output mode) or to get the current signal status (in INPUT mode).
        
        Get LED along with resistor say 330 ohms.
        Connect positive side of LED (longer leg) to BCM_GPIO pin no 18 and 
        the negative side (shorter leg) to 330 ohm resitor to GND pin of Raspberry Pi.
        
        so it's BCM_GPIO18 ---> longer leg - LED ---> shorter leg - LED ---> 330 ohms resistor ---> GND pin.
        
        file name - main.cpp
        
        for compiling and running the program - 
        (1) If you are in command line mode just type below
        commands. 
        (2) In case of GUI mode, you have start the
        terminal and type the below commands.
        
        to compile the program - g++ -o main main.cpp
        to run the program - sudo ./main        
        
        
