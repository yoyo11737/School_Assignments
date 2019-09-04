/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18855
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA4
#define POT_LAT                  LATAbits.LATA4
#define POT_PORT                 PORTAbits.RA4
#define POT_WPU                  WPUAbits.WPUA4
#define POT_OD                   ODCONAbits.ODCA4
#define POT_ANS                  ANSELAbits.ANSA4
#define POT_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POT_GetValue()           PORTAbits.RA4
#define POT_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POT_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POT_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POT_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set BTN aliases
#define BTN_TRIS                 TRISAbits.TRISA5
#define BTN_LAT                  LATAbits.LATA5
#define BTN_PORT                 PORTAbits.RA5
#define BTN_WPU                  WPUAbits.WPUA5
#define BTN_OD                   ODCONAbits.ODCA5
#define BTN_ANS                  ANSELAbits.ANSA5
#define BTN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define BTN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define BTN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define BTN_GetValue()           PORTAbits.RA5
#define BTN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define BTN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define BTN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define BTN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define BTN_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define BTN_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define BTN_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define BTN_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set E aliases
#define E_TRIS                 TRISBbits.TRISB0
#define E_LAT                  LATBbits.LATB0
#define E_PORT                 PORTBbits.RB0
#define E_WPU                  WPUBbits.WPUB0
#define E_OD                   ODCONBbits.ODCB0
#define E_ANS                  ANSELBbits.ANSB0
#define E_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define E_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define E_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define E_GetValue()           PORTBbits.RB0
#define E_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define E_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define E_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define E_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define E_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define E_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define E_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define E_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set D aliases
#define D_TRIS                 TRISBbits.TRISB1
#define D_LAT                  LATBbits.LATB1
#define D_PORT                 PORTBbits.RB1
#define D_WPU                  WPUBbits.WPUB1
#define D_OD                   ODCONBbits.ODCB1
#define D_ANS                  ANSELBbits.ANSB1
#define D_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define D_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define D_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define D_GetValue()           PORTBbits.RB1
#define D_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define D_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define D_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define D_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define D_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define D_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define D_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define D_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set DP aliases
#define DP_TRIS                 TRISBbits.TRISB2
#define DP_LAT                  LATBbits.LATB2
#define DP_PORT                 PORTBbits.RB2
#define DP_WPU                  WPUBbits.WPUB2
#define DP_OD                   ODCONBbits.ODCB2
#define DP_ANS                  ANSELBbits.ANSB2
#define DP_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define DP_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define DP_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define DP_GetValue()           PORTBbits.RB2
#define DP_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define DP_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define DP_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define DP_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define DP_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define DP_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define DP_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define DP_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set C aliases
#define C_TRIS                 TRISBbits.TRISB3
#define C_LAT                  LATBbits.LATB3
#define C_PORT                 PORTBbits.RB3
#define C_WPU                  WPUBbits.WPUB3
#define C_OD                   ODCONBbits.ODCB3
#define C_ANS                  ANSELBbits.ANSB3
#define C_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define C_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define C_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define C_GetValue()           PORTBbits.RB3
#define C_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define C_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define C_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define C_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define C_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define C_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define C_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define C_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set G aliases
#define G_TRIS                 TRISBbits.TRISB4
#define G_LAT                  LATBbits.LATB4
#define G_PORT                 PORTBbits.RB4
#define G_WPU                  WPUBbits.WPUB4
#define G_OD                   ODCONBbits.ODCB4
#define G_ANS                  ANSELBbits.ANSB4
#define G_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define G_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define G_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define G_GetValue()           PORTBbits.RB4
#define G_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define G_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define G_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define G_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define G_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define G_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define G_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define G_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set A1 aliases
#define A1_TRIS                 TRISBbits.TRISB5
#define A1_LAT                  LATBbits.LATB5
#define A1_PORT                 PORTBbits.RB5
#define A1_WPU                  WPUBbits.WPUB5
#define A1_OD                   ODCONBbits.ODCB5
#define A1_ANS                  ANSELBbits.ANSB5
#define A1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define A1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define A1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define A1_GetValue()           PORTBbits.RB5
#define A1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define A1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define A1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define A1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define A1_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define A1_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define A1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define A1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set A aliases
#define A_TRIS                 TRISCbits.TRISC2
#define A_LAT                  LATCbits.LATC2
#define A_PORT                 PORTCbits.RC2
#define A_WPU                  WPUCbits.WPUC2
#define A_OD                   ODCONCbits.ODCC2
#define A_ANS                  ANSELCbits.ANSC2
#define A_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define A_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define A_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define A_GetValue()           PORTCbits.RC2
#define A_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define A_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define A_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define A_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define A_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define A_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define A_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define A_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set B aliases
#define B_TRIS                 TRISCbits.TRISC3
#define B_LAT                  LATCbits.LATC3
#define B_PORT                 PORTCbits.RC3
#define B_WPU                  WPUCbits.WPUC3
#define B_OD                   ODCONCbits.ODCC3
#define B_ANS                  ANSELCbits.ANSC3
#define B_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define B_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define B_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define B_GetValue()           PORTCbits.RC3
#define B_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define B_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define B_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define B_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define B_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define B_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define B_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define B_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set A2 aliases
#define A2_TRIS                 TRISCbits.TRISC4
#define A2_LAT                  LATCbits.LATC4
#define A2_PORT                 PORTCbits.RC4
#define A2_WPU                  WPUCbits.WPUC4
#define A2_OD                   ODCONCbits.ODCC4
#define A2_ANS                  ANSELCbits.ANSC4
#define A2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define A2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define A2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define A2_GetValue()           PORTCbits.RC4
#define A2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define A2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define A2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define A2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define A2_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define A2_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define A2_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define A2_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set A3 aliases
#define A3_TRIS                 TRISCbits.TRISC5
#define A3_LAT                  LATCbits.LATC5
#define A3_PORT                 PORTCbits.RC5
#define A3_WPU                  WPUCbits.WPUC5
#define A3_OD                   ODCONCbits.ODCC5
#define A3_ANS                  ANSELCbits.ANSC5
#define A3_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define A3_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define A3_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define A3_GetValue()           PORTCbits.RC5
#define A3_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define A3_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define A3_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define A3_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define A3_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define A3_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define A3_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define A3_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set F aliases
#define F_TRIS                 TRISCbits.TRISC6
#define F_LAT                  LATCbits.LATC6
#define F_PORT                 PORTCbits.RC6
#define F_WPU                  WPUCbits.WPUC6
#define F_OD                   ODCONCbits.ODCC6
#define F_ANS                  ANSELCbits.ANSC6
#define F_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define F_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define F_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define F_GetValue()           PORTCbits.RC6
#define F_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define F_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define F_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define F_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define F_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define F_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define F_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define F_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set A4 aliases
#define A4_TRIS                 TRISCbits.TRISC7
#define A4_LAT                  LATCbits.LATC7
#define A4_PORT                 PORTCbits.RC7
#define A4_WPU                  WPUCbits.WPUC7
#define A4_OD                   ODCONCbits.ODCC7
#define A4_ANS                  ANSELCbits.ANSC7
#define A4_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define A4_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define A4_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define A4_GetValue()           PORTCbits.RC7
#define A4_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define A4_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define A4_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define A4_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define A4_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define A4_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define A4_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define A4_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/