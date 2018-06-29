//
//  gpio.cpp
//  RPI_GPIO
//
//  Created by Jishnu Chakrabarti on 6/29/18.
//  Copyright © 2018 Jishnu Chakrabarti. All rights reserved.
//

#include "gpio.hpp"

//======================================================================
// SET UP MEMORY REGIONS TO ACCESS GPIO.
//======================================================================
void setup_io()
{
    //open /dev/mem
    
    if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC)) < 0 ){
        printf ("cant open /dev/mem are you in root?if not use sudo.\n");
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
        printf("mmap error %d\n", (int) gpio_map);
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
