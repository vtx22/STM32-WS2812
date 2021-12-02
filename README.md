# STM32 WS2812 LED Library
C++ Library for interfacing the WS2812 LEDs with a STM32 like the STM32F103C8 using SysTick

# Installation
Add the LED.cpp and the LED.hpp in your source / include folder

# Basic Usage
To use the LED library follow the steps.

1. Include the Library with 

        #include "LED.hpp"
2. Specify the number of LEDs in the LED.hpp file
    
        static const uint8_t _neoLEDS = 8;
3. Create a new LED object in your code, e.g.

        LED led = LED();
If you want to use the implemented animation functions you need to supply some kind of clock with a Hardware Timer or simply by using the main. See the next chapter for more information.

4. Use the implemented functions, e.g.
        
        led.setAllNeopixels(0xFF, 0x00, 0x00);
# Usage of Animations
Using animations requires you to count up a number in a fixed interval of your choice. This number is used by the led functions to refresh / update the animation.
Example: Using the animateSine function with htim2:

1.  Configure and start a hardware timer of your choice, e.g htim2:
    The STM32F103C8T6 can run with 72MHz. Using a prescaler of 14400 - 1 yields a tick frequency of 5kHz. 
2.  In the main, we call the animateSine function every 10 Timer ticks (=500Hz refresh rate) to increase the _updateCount
        
        uint8_t color[3] = {128, 0, 0};
        if(TIM2->CNT >= 10)
	      {
		        led._updateCNT++;
		        TIM2->CNT = 0;
		        led.animateSine(color, 0.02, 220, 0.8);
	      }
    The following code should result in a red SineWave pattern on the LED strip.
