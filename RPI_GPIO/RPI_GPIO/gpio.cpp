//
//  gpio.cpp
//  RPI_GPIO
//
//  Created by Jishnu Chakrabarti on 6/29/18.
//  Copyright © 2018 Jishnu Chakrabarti. All rights reserved.
//

#include "gpio.hpp"

// body of functions

void delay(int time) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void logMessage(const char* message) {
    std::cout << message << std::endl;
}
