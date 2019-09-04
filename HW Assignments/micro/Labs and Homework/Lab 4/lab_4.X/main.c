/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18855
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"



uint8_t matrix[]={
    //a  b  c  d  e  f  g
    1, 1, 1, 1, 1, 1, 0, //0
    0, 1, 1, 0, 0, 0, 0,//1
    1, 1, 0, 1, 1, 0, 1, //2
    1, 1, 1, 1, 0, 0, 1, //3
    0, 1, 1, 0, 0, 1, 1, //4
    1, 0, 1, 1, 0, 1, 1, //5
    1, 0, 1, 1, 1, 1, 1, //6
    1, 1, 1, 0, 0, 0, 0, //7
    1, 1, 1, 1, 1, 1, 1, //8
    1, 1, 1, 1, 0, 1, 1, //9
    1, 1, 1, 0, 1, 1, 1, //a10
    0, 0, 1, 1, 1, 1, 1, //b11
    0, 0, 0, 1, 1, 0, 1, //c12
    0, 1, 1, 1, 1, 0, 1, //d13
    1, 0, 0, 1, 1, 1, 1, //e14
    1, 0, 0, 0, 1, 1, 1, //f15
    1, 0, 1, 1, 1, 1, 0, //g16
    0, 1, 1, 0, 1, 1, 1, //h17
    0, 0, 0, 0, 1, 1, 0, //i18
    0, 1, 1, 1, 1, 0, 0, //j19
    1, 0, 1, 0, 1, 1, 1, //K20
    0, 0, 0, 1, 1, 1, 0, //l21
    1, 1, 0, 1, 0, 1, 0, //m22
    0, 0, 1, 0, 1, 0, 1, //n23
    0, 0, 1, 1, 1, 0, 1, //o24
    1, 1, 0, 0, 1, 1, 1, //p25
    1, 1, 1, 0, 0, 1, 1, //q26
    0, 0, 0, 0, 1, 0, 1, //r27
    1, 0, 1, 1, 0, 1, 1, //s28
    0, 0, 0, 1, 1, 1, 1, //t29
    0, 0, 1, 1, 1, 0, 0, //u30
    0, 1, 0, 1, 0, 1, 0, //v31
    0, 1, 1, 1, 1, 1, 1, //w32
    1, 0, 0, 1, 0, 0, 1, //x33
    0, 1, 1, 1, 0, 1, 1, //y34
    1, 1, 0, 1, 1, 0, 1, //z35
    0, 0, 0, 0, 0, 0, 0  //SPACE36
};

void digitShow(uint8_t value)
{// goes to the required value location in the matrix then runs through the whole length of the 7 segment display.
    //NOTE this code has been changed for common cathode the original code was ~*p++; 
    //the '~' is bitwise NOT in this instance it made all highs we had in the matrix low and the lows high this allowed for common anode to work
    uint8_t *p=&matrix[value*7];
    A_LAT = *p++;
    B_LAT = *p++;
    C_LAT = *p++;
    D_LAT = *p++;
    E_LAT = *p++;
    F_LAT = *p++;
    G_LAT = *p++;
    
}

int my_name[] = {13, 10, 21, 29, 24, 23, 36, 22, 12, 12, 21, 10, 18, 23, 36, 13, 10, 21};
int my_znum[] = {35, 2, 3, 4, 9, 1, 0, 3, 2, 36, 2, 3, 4};

void main(void)
{
    uint8_t digit; //ADCC_GetSingleConversion(POT)>>5;
    
    // initialize the device
    SYSTEM_Initialize();
    
    DP_LAT = 0;
    
    A1_SetHigh();
    A2_SetHigh();
    A3_SetHigh();
    A4_SetHigh();
    
    while(1){
        digit = ADCC_GetSingleConversion(POT) >> 5;
        if(CLC1_OutputStatusGet() == 1){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < digit; j++){
        if(CLC1_OutputStatusGet() == 0){
         break;
        }
        digit = ADCC_GetSingleConversion(POT) >> 5;
        A1_SetHigh();
         digitShow(my_znum[i]);
         __delay_ms(1);
         A4_SetLow();
         __delay_ms(5);
         
         A4_SetHigh();
         digitShow(my_znum[i + 1]);
         __delay_ms(1);
         A3_SetLow();
         __delay_ms(5);
         
         A3_SetHigh();
         digitShow(my_znum[i + 2]);
         __delay_ms(1);
         A2_SetLow();
         __delay_ms(5);
         
         A2_SetHigh();
         digitShow(my_znum[i + 3]);
         __delay_ms(1);
         A1_SetLow();
         __delay_ms(5);
            }//end of j for loop
        }//end of i for loop
        }//end of if button == 0
        else if(CLC1_OutputStatusGet() == 0){
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < digit; j++){
        if(CLC1_OutputStatusGet() == 1){
         break;
        }
        digit = ADCC_GetSingleConversion(POT) >> 5;
        A1_SetHigh();
         digitShow(my_name[i]);
         __delay_ms(1);
         A4_SetLow();
         __delay_ms(5);
         
         A4_SetHigh();
         digitShow(my_name[i + 1]);
         __delay_ms(1);
         A3_SetLow();
         __delay_ms(5);
         
         A3_SetHigh();
         digitShow(my_name[i + 2]);
         __delay_ms(1);
         A2_SetLow();
         __delay_ms(5);
         
         A2_SetHigh();
         digitShow(my_name[i + 3]);
         __delay_ms(1);
         A1_SetLow();
         __delay_ms(5);
            }//end of j for loop
        }//end of i for loop
        }
    }
    }
    

/**
 End of File
*/