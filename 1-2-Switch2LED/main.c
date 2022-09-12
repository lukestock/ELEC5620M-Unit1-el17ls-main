/**
 * main.c
 *
 *  Created on: 12 Feb 2021
 *      Author: Harry Clegg
 *      		You
 */

// Include drivers.
// Please note the compiler will not be able to find this driver until you have
// configured the project settings as described in the Unit 1.1 Notes.
#include "HPS_Watchdog/HPS_Watchdog.h"

// ToDo: Define any peripheral base addresses here. For example:
volatile unsigned int *key_ptr = (unsigned int *) 0xFF200050; // KEYS 0-3 (push buttons).
volatile int *SW_ptr = (int *) 0xFF200040; // SWITCHES 0-10
volatile int *LEDR_ptr = (int *) 0xFF200000; // LEDS 0-10

/**
 * main
 *
 * The entry function for this task. This function should mirror the state of
 * the 10 switches on the 10 LEDs exactly, e.g. if SW3 is high, then LED3 should
 * also be high.
 *
 * If you want, you can extend this program such that if any of the key buttons
 * (KEY 0-3) are pressed, the state of the LEDs is the inverse of the switches,
 * e.g. if SW3 is high, then LED3 should be low.
 */
void main(void) {

    // ToDo: Declare any variables you need and perform initialisation here

    while (1) {
        // ToDo: Implement your loop logic here.
    	if (*key_ptr & 0xF) {
    		*LEDR_ptr = ~*SW_ptr;
    	}
    	else {
    		*LEDR_ptr = *SW_ptr;
    	}

        // Reset the Watchdog Timer so the processor doesn't reset.
        HPS_ResetWatchdog();
    }
}
