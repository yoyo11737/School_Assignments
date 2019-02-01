/*
 * File:   main.c
 * Author: shankar@fau.edu
 *
 * Created on 12/7/2018 4:54:49 PM UTC
 * "Created in MPLAB Xpress"
 */
// Choose UQFN28 in MCC Pin Module
// Chose RA0 and RA1 as initially high
// see a left to right moving LED display
// Single step; also use break point on LED2_Toggle()
// repeat with LED_Toggle() function prototype

#include <xc.h>
#include "mcc_generated_files/mcc.h"
void main(void) {
    SYSTEM_Initialize();
    while(1) {
    
        puts("Hello Again");
    }
}
