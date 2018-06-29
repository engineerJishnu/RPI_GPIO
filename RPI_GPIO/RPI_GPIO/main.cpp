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
#include "gpio.hpp"

//==============================MAIN====================================
int main(int argc, char **argv)
{
    system("clear");
    
    //Set up gpio pointer for direct register access
    setup_io();
    // set GPIO pins as input & output
    
    INP_GPIO(1);    OUT_GPIO(1);
    // LOOP
    
    for (int rep = 0; rep <= 50 ; rep++) {
        std::cout << "\t" << "LED1 = " << rep << std::endl;
        GPIO_SET = 1 << 1;
        system("sleep 0.5");
        GPIO_CLR = 1 << 1;
        system("sleep 0.1");
        
    }
    std::cout << "\nThe program ended." << std::endl;
    restore_io();
    return 0;
} // end of main()

