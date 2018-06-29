//  main.cpp
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
 
 BCM_GPIO               pin no
 ------------------------------
 17                     - 0
 18(PWM)                - 1
 27(REV2)/21(REV1)      - 2
 22                     - 3
 23                     - 4
 24                     - 5
 25                     - 6
 4(CLK)                 - 7
 7(SPI)                 - CS1    - LED1
 8(SPI)                 - CS0    - LED2
 9(SPI)                 - MISO
 10(SPI)                - MOSI
 11(SPI)                - SCLK
 2(I2C)                 - SDA0
 3(I2C)                 - SCL0
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
//==============================MAIN====================================
int main(int argc, char **argv)
{
    int rep;
    
    system("clear");
    
    //Set up gpio pointer for direct register access
    setup_io();
    // set GPIO pins as input & output
    
    INP_GPIO(1);    OUT_GPIO(1);
    // LOOP
    
    for (rep = 1; rep <= 50 ; rep++) {
        std::cout << "LED1 " << rep << std::endl;
        GPIO_SET = 1 << 1;
        system("sleep 0.5");
        GPIO_CLR = 1 << 1;
        system("sleep 0.1");
        
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
    munmap(gpio_map, BLOCK_SIZE); // (void *addr, size_t length)
    // removes memory map from addr to
    //addr+length. it return 0 for success and -1 for error.
    close(mem_fd); // NO need to keep mem_fd open after nmap
} // end of restore_io

