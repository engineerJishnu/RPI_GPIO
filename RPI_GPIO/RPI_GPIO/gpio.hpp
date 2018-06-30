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
#include <cstdio> // getchar()
#include <unistd.h> // close()
#include <fcntl.h> // O_RDWR|O_SYNC
#include <sys/mman.h> // memory management declaration
#include <thread>
#include <vector>

// functions 
void delay(int time);
//======================================================================
void logMessage(const char* message);
//======================================================================
//std::vector<int> vPins = {17,18,27,22,23,24,25};
void quick_led_demo();
#endif /* gpio_hpp */
