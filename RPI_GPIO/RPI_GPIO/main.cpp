//  main.cpp
// to compile g++ -o main main.cpp
// to run - sudo ./main
//  RPI_GPIO
//
//  Created by Jishnu Chakrabarti on 6/29/18.
//  Copyright © 2018 Jishnu Chakrabarti. All rights reserved.
//
/* Programming RAspberry Pi in C++ code in LOW LEVEL way where everything
 * is done by writing to the registers in the memory of the device.
 *
 RASPBERRY PI GPIO PIN MAPPING
 ------------------------------
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
 */
//======================================================================
// files to be included.
//======================================================================
#include <iostream>
#include <stdio.h>    // standard I/O
#include <stdlib.h>
#include <sys/mman.h> // memory management declaration
#include <fcntl.h>
#include <unistd.h> // sleep();
//======================================================================
// ARM PHYSICAL ADDRESSES BCM2835 - from BROADCOM MANUAL
//======================================================================
// The physical address range from 0x2000000 to 0x20FFFFFF for peripherals
// the bus addresses for set up to map onto the peripheral bus address
// range starting at 0x7E000000. Thus the peripheral advertised here at
// bus address 0x7Ennnnnn is available at physical address 0x20nnnnnn.
//======================================================================
//#define BCM2708_PERI_BASE     0x20000000 /* Pi 1 */
#define BCM2708_PERI_BASE       0x3F000000 /* Pi 2 & Pi 3 */
//======================================================================
// GPIO CONTROLLER Macros....
//======================================================================
#define GPIO_BASE                (BCM2708_PERI_BASE + 0x200000)
#define BLOCK_SIZE (4*1024)
#define PAGE_SIZE (4*1024)

//======================================================================
// GLOBAL VARIABLES
//======================================================================
int mem_fd;
int g;
void *gpio_map;
//======================================================================
// I/O access
//======================================================================
static volatile unsigned *gpio;
//======================================================================
// GPIO setup macros - process for the purpose of predefining.....
// Always use INP_GPIO(x) before using OUT_GPIO(x)
//======================================================================
#define INP_GPIO(g) *(gpio + ((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio + ((g)/10)) |=  (1<<(((g)%10)*3))
#define GPIO_SET   *(gpio + 7)  // Set GPIO high bits 0-31
#define GPIO_CLR   *(gpio + 10) // Set GPIO low bits 0-31
//======================================================================
void setup_io();
void restore_io();
void delay(int time);
//==============================MAIN====================================
int main()
{
    const int pinNo = 18;
    
    system("clear");
    std::cout << "Welcome to GPIO programming in C++" << std::endl;
    std::cout << "To stop the program press [CNTRL + C].." << std::endl;
    std::cout << "Press [ENTER] to start the program..." << std::endl;
    std::cin.get();
    
    //Set up gpio pointer for direct register access
    setup_io();
    
    // set GPIO pins as input & output
    
    INP_GPIO(pinNo);    OUT_GPIO(pinNo);
    
    // LOOP
    
    while(1) {
        std::cout << "LED1 ON" << std::endl;
        GPIO_SET = 1 << pinNo;
        //system("sleep 0.5");
        delay(500);
        GPIO_CLR = 1 << pinNo;
        delay(1000);
        
    }
    
    std::cout << "\nThe program ended.\n";
    restore_io();
    return 0;
} // end of main()

//======================================================================
// SET UP MEMORY REGIONS TO ACCESS GPIO.
//======================================================================
void setup_io()
{
    //open /dev/mem
    
    if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC)) < 0 ){
        std::cout << "can't open /dev/mem..." << std::endl;
        exit(-1);
    }
    //======================================================================
    //mmap GPIO
    //======================================================================
    gpio_map = mmap (
                     NULL,             // void *addr - Any address in our space will do
                     BLOCK_SIZE,         // int size_t len - MAP LENGHT - 4096
                     PROT_READ|PROT_WRITE,// int prot - Enable reading & writing in Map memory
                     MAP_SHARED,        // int flags - Shared with other process
                     mem_fd,            // int file - File to map
                     GPIO_BASE        // off_t offset - Offset to GPIO peripheral
                     );
    
    if(gpio_map == MAP_FAILED) {
        std::cout << "mmap error " << (long int)gpio_map << std::endl;
        exit(-1);
    }
    
    //======================================================================
    // Always use volatile pointer
    //======================================================================
    gpio = (volatile unsigned *) gpio_map;
} //setup_io

void restore_io() {
    munmap(gpio_map, BLOCK_SIZE); // munmap(void *addr, size_t length)
    // removes memory map from addr to
    //addr+length. it return 0 for success and -1 for error.
    close(mem_fd); // NO need to keep mem_fd open after nmap
} // end of restore_io

void delay(int time) {
    usleep(time * 1000);
}
