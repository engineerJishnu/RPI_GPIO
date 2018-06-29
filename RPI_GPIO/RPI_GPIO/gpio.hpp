//
//  gpio.hpp
//  RPI_GPIO
//
//  Created by Jishnu Chakrabarti on 6/29/18.
//  Copyright © 2018 Jishnu Chakrabarti. All rights reserved.
//

#ifndef gpio_hpp
#define gpio_hpp
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
#define BCM2708_PERI_BASE        0x20000000     // starting from address
//======================================================================
// GPIO CONTROLLER Macros....
//======================================================================
#define GPIO_BASE                (BCM2708_PERI_BASE + 0x200000)
#define BLOCK_SIZE (4*1024)
#define PAGE_SIZE (4*1024)

//======================================================================
// I/O access
//======================================================================
volatile unsigned *gpio;
//======================================================================
// GPIO setup macros - process for the purpose of predefining.....
// Always use INP_GPIO(x) before using OUT_GPIO(x)
//======================================================================
//#define INP_GPIO(g)     *(gpio + ((g)/10)) &= ~(7<<(((g)%10)*3))
//#define OUT_GPIO(g)     *(gpio + ((g)/10)) |=  (1<<(((g)%10)*3))
//#define GPIO_SET        *(gpio + 7)  // Set GPIO high bits 0-31
//#define GPIO_CLR        *(gpio + 10) // Set GPIO low bits 0-31
//======================================================================

void setup_io();
void restore_io();
int INP_GPIO(int g);
int OUT_GPIO(int g);
void GPIO_SET();
void GPIO_CLR();


#endif /* gpio_hpp */
