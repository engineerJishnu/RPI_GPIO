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
// header files to be included.
//======================================================================
#include <iostream>
#include <unistd.h> // close()
#include <fcntl.h> // O_RDWR|O_SYNC
#include <sys/mman.h> // memory management declaration
#include <thread>

// functions 
void delay(int time);
//======================================================================
void logMessage(const char* message);
//======================================================================
#endif /* gpio_hpp */
