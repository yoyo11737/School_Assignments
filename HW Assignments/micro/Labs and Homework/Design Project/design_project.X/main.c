
#include "mcc_generated_files/mcc.h"
#define PRESSED     0

//Matrix for word gathering
uint8_t matrix_word[] = {
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


//Matrices for words that need to be displayed
uint8_t set[] = {28, 14, 29, 36};
uint8_t entr[] = {14, 23, 29, 27};
uint8_t open[] = {24, 25, 14, 23};
uint8_t deny[] = {13, 14, 23, 34};
uint8_t lock__[] = {21, 24, 12, 20};
uint8_t new[] = {23, 14, 32, 36};

void digitShow(uint8_t value)
{// goes to the required value location in the matrix then runs through the whole length of the 7 segment display.
    //NOTE this code has been changed for common cathode the original code was ~*p++; 
    //the '~' is bitwise NOT in this instance it made all highs we had in the matrix low and the lows high this allowed for common anode to work
    uint8_t *p=&matrix_word[value*7];
    SEG_A_LAT = *p++;
    SEG_B_LAT = *p++;
    SEG_C_LAT = *p++;
    SEG_D_LAT = *p++;
    SEG_E_LAT = *p++;
    SEG_F_LAT = *p++;
    SEG_G_LAT = *p++;
    
}

void main(void)
{
    uint8_t digit__, last__, zero = 0;
    // initialize the device
    SYSTEM_Initialize();

    //Control accumulators
    int btn_count = 0, prgm_count = 0;
    int set_btn = 1, entr_btn = 1, open_btn = 1, deny_btn = 1, lock = 1, new_display = 0, lock_display = 0;
    int digit[4];
    int digit_tmp[4];
    
    //Set digits high
    C1_SetHigh();
    C2_SetHigh();
    C3_SetHigh();
    C4_SetHigh();
    SEG_DP_LAT = 0;
    
	//Program loop
    while (1)
    {
        //loop to display "new"
        
        while(set_btn == 1 && new_display == 1){
         
         C1_SetHigh();
         digitShow(new[3]);
         __delay_ms(1);
         C4_SetLow();
         __delay_ms(5);
         
         C4_SetHigh();
         digitShow(new[2]);
         __delay_ms(1);
         C3_SetLow();
         __delay_ms(5);
         
         C3_SetHigh();
         digitShow(new[1]);
         __delay_ms(1);
         C2_SetLow();
         __delay_ms(5);
         
         C2_SetHigh();
         digitShow(new[0]);
         __delay_ms(1);
         C1_SetLow();
         __delay_ms(5);
         
         if(BTN_GetValue() == PRESSED){
             new_display = 0;
             __delay_ms(350);
         }
        }
        
		//Clearing the display
        C1_SetHigh();
        C2_SetHigh();
        C3_SetHigh();
        C4_SetHigh();
        
		//These conditionals go through the first stage of the lock, getting the initial code and keeping it set.
        if(BTN_GetValue() == PRESSED && btn_count == 0 && prgm_count == 0 && lock == 1){
            digit[0] = (ADCC_GetSingleConversion(POT)>>4) % 10;
            digit_tmp[0] = digit[0];
            btn_count++;
            LED1_SetHigh();
            __delay_ms(300);
        }
        if(BTN_GetValue() == PRESSED && btn_count == 1 && prgm_count == 0 && lock == 1){
            digit[1] = (ADCC_GetSingleConversion(POT)>>4) % 10;
            digit_tmp[1] = digit[1];
            btn_count++;
            LED2_SetHigh();
            __delay_ms(300);
        }
        if(BTN_GetValue() == PRESSED && btn_count == 2 && prgm_count == 0 && lock == 1){
            digit[2] = (ADCC_GetSingleConversion(POT)>>4) % 10;
            digit_tmp[2] = digit[2];
            btn_count++;
            LED3_SetHigh();
            __delay_ms(300);
        }
        if(BTN_GetValue() == PRESSED && btn_count == 3 && prgm_count == 0 && lock == 1){
            digit[3] = (ADCC_GetSingleConversion(POT)>>4) % 10;
            digit_tmp[3] = digit[3];
            btn_count++;
            LED4_SetHigh();
            __delay_ms(50);
        } 
        //lopp to display "set"
        
        while(set_btn == 1 && prgm_count == 1){
         
         C1_SetHigh();
         digitShow(set[3]);
         __delay_ms(1);
         C4_SetLow();
         __delay_ms(5);
         
         C4_SetHigh();
         digitShow(set[2]);
         __delay_ms(1);
         C3_SetLow();
         __delay_ms(5);
         
         C3_SetHigh();
         digitShow(set[1]);
         __delay_ms(1);
         C2_SetLow();
         __delay_ms(5);
         
         C2_SetHigh();
         digitShow(set[0]);
         __delay_ms(1);
         C1_SetLow();
         __delay_ms(5);
         
         if(BTN_GetValue() == PRESSED){
             set_btn = 0;
             __delay_ms(350);
         }
        }
        
		//Clearing the display
        C1_SetHigh();
        C2_SetHigh();
        C3_SetHigh();
        C4_SetHigh();
        
        
		//This conditional goes through the second part of the lock, which is the part where the user input the code,
		//whether it's wrong or right has no effect on the program as of yet
        if(BTN_GetValue() == PRESSED && btn_count == 0 && prgm_count == 1){
            digit[0] = (ADCC_GetSingleConversion(POT)>>4) % 10;
            btn_count++;
            LED1_SetHigh();
            __delay_ms(300);
        }
        if(BTN_GetValue() == PRESSED && btn_count == 1 && prgm_count == 1){
            digit[1] = (ADCC_GetSingleConversion(POT)>>4) % 10;
            btn_count++;
            LED2_SetHigh();
            __delay_ms(300);
        }
        if(BTN_GetValue() == PRESSED && btn_count == 2 && prgm_count == 1){
            digit[2] = (ADCC_GetSingleConversion(POT)>>4) % 10;
            btn_count++;
            LED3_SetHigh();
            __delay_ms(300);
        }
        if(BTN_GetValue() == PRESSED && btn_count == 3 && prgm_count == 1){
            digit[3] = (ADCC_GetSingleConversion(POT)>>4) % 10;
            btn_count++;
            LED4_SetHigh();
            __delay_ms(50);
        } 
        
        //loop to display "lock"
        
        while(lock_display == 1){
         
         C1_SetHigh();
         digitShow(lock__[3]);
         __delay_ms(1);
         C4_SetLow();
         __delay_ms(5);
         
         C4_SetHigh();
         digitShow(lock__[2]);
         __delay_ms(1);
         C3_SetLow();
         __delay_ms(5);
         
         C3_SetHigh();
         digitShow(lock__[1]);
         __delay_ms(1);
         C2_SetLow();
         __delay_ms(5);
         
         C2_SetHigh();
         digitShow(lock__[0]);
         __delay_ms(1);
         C1_SetLow();
         __delay_ms(5);
         
         if(BTN_GetValue() == PRESSED){
             lock_display = 0;
             __delay_ms(350);
         }
        }
        
		//Clearing the display
        C1_SetHigh();
        C2_SetHigh();
        C3_SetHigh();
        C4_SetHigh();
        
        //loop to display "entr"
        while(entr_btn == 1 && prgm_count == 2){
         
         C1_SetHigh();
         digitShow(entr[3]);
         __delay_ms(1);
         C4_SetLow();
         __delay_ms(5);
         
         C4_SetHigh();
         digitShow(entr[2]);
         __delay_ms(1);
         C3_SetLow();
         __delay_ms(5);
         
         C3_SetHigh();
         digitShow(entr[1]);
         __delay_ms(1);
         C2_SetLow();
         __delay_ms(5);
         
         C2_SetHigh();
         digitShow(entr[0]);
         __delay_ms(1);
         C1_SetLow();
         __delay_ms(5);
         
         if(BTN_GetValue() == PRESSED){
             entr_btn = 0;
         }
        }
        
		//Clearing the display
        C1_SetHigh();
        C2_SetHigh();
        C3_SetHigh();
        C4_SetHigh();
        
		//This is the conditional statement that controls the flow of the program as well as the input handling of the users data.
        if(BTN_GetValue() == PRESSED && btn_count == 0 && prgm_count == 2){
            if(digit[0] == digit_tmp[0] && digit[1] == digit_tmp[1] && digit[2] == digit_tmp[2] && digit[3] == digit_tmp[3]){
                __delay_ms(200);
				//loop to display "open"
                while(open_btn == 1){
                    
                    C1_SetHigh();
                    digitShow(open[3]);
                    __delay_ms(1);
                    C4_SetLow();
                    __delay_ms(5);

                    C4_SetHigh();
                    digitShow(open[2]);
                    __delay_ms(1);
                    C3_SetLow();
                    __delay_ms(5);

                    C3_SetHigh();
                    digitShow(open[1]);
                    __delay_ms(1);
                    C2_SetLow();
                    __delay_ms(5);

                    C2_SetHigh();
                    digitShow(open[0]);
                    __delay_ms(1);
                    C1_SetLow();
                    __delay_ms(5);

                    if(BTN_GetValue() == PRESSED){
                        open_btn = 0;
                        __delay_ms(25);
                    }
                   }

				   //Clearing the display
                   C1_SetHigh();
                   C2_SetHigh();
                   C3_SetHigh();
                   C4_SetHigh();
                   
				   //This conditional is how we control the "reset" function of the program. If the user wants to reset the pin, all they have to do is set the potentiometer
				   //to the 0 position (all the way counter clock wise) and press the button.
                   if(((ADCC_GetSingleConversion(POT)>>4) % 10) == zero){
					   //Completly reset everything to "restart" the program loop, whilst sending "new" to the display
                        btn_count = 0;
                        prgm_count = 0;
                        set_btn = 1;
                        entr_btn = 1;
                        open_btn = 1;
                        deny_btn = 1;
                        lock = 1;
                        new_display = 1;
                        __delay_ms(200);
                   }else{//If they don't press the button with the potentiometer at 0, it continues and sends "lock" to the display
                        //Reset the relative values so as to maintain the fact that the user wants the lock to remain locked
						btn_count = 0;
                        prgm_count = 1;
                        set_btn = 2;
                        entr_btn = 1;
                        open_btn = 1;
                        deny_btn = 1;
                        lock = 0;
                        lock_display = 1;
                        __delay_ms(200);
                   }
                   
                   
            }
            else{
                __delay_ms(200);
				//loop to display "deny"
                while(deny_btn == 1){
                    
                    C1_SetHigh();
                    digitShow(deny[3]);
                    __delay_ms(1);
                    C4_SetLow();
                    __delay_ms(5);

                    C4_SetHigh();
                    digitShow(deny[2]);
                    __delay_ms(1);
                    C3_SetLow();
                    __delay_ms(5);

                    C3_SetHigh();
                    digitShow(deny[1]);
                    __delay_ms(1);
                    C2_SetLow();
                    __delay_ms(5);

                    C2_SetHigh();
                    digitShow(deny[0]);
                    __delay_ms(1);
                    C1_SetLow();
                    __delay_ms(5);

                    if(BTN_GetValue() == PRESSED){
                        deny_btn = 0;
                        __delay_ms(25);
                    }
                   }

				   //Clearing the display
                   C1_SetHigh();
                   C2_SetHigh();
                   C3_SetHigh();
                   C4_SetHigh();
                   
				   //Resetting the relative values so as to maintain the fact tht the user still needs to enter the correct pin
                   btn_count = 0;
                   prgm_count = 1;
                   set_btn = 2;
                   entr_btn = 1;
                   open_btn = 1;
                   deny_btn = 1;
                   lock = 0;
                   __delay_ms(200);
            }
        }
		//This is the first part of the lock system, initializing the lock with the user entered pin
        else if(BTN_GetValue() == PRESSED && btn_count == 4 && prgm_count == 0){
            digit[0] = 0;
            digit[1] = 0;
            digit[2] = 0;
            digit[3] = 0;
            btn_count = 0;//increments the button press counter
            prgm_count++;//increments the program counter
			//This resets the LEDs
            LED1_SetLow();
            LED2_SetLow();
            LED3_SetLow();
            LED4_SetLow();
            __delay_ms(1000);
        }
		//This is the second part of the lock system, where the user enters a pin, whether it is the right or wrong pin doesn't matter here
        else if(BTN_GetValue() == PRESSED && btn_count == 4 && prgm_count == 1){
            btn_count = 0;//Reset the button count to 0
            prgm_count++;//increments the program counter
			//This resets the LEDs
            LED1_SetLow();
            LED2_SetLow();
            LED3_SetLow();
            LED4_SetLow();
            __delay_ms(1000);
        }
        
		//This is the logic behind getting the the potentiometer to select the values needed.
		//It works by taking advantage of the division and modulus operators, taking the ADCC potentiometer data bitshifted and then taking the modulus of it gives a remainder 
		//and dividing it gives a rounded up value.
        digit__ = (ADCC_GetSingleConversion(POT)>>4) % 10;
        last__ = (ADCC_GetSingleConversion(POT)>>4) / 10;
        
		//This is just to control the flow of which digits on the display get lit up and which don't. 
		//I chose the two digits on the right to keep things close (the display and the potentiometer)
        C3_SetHigh();
        C4_SetLow();
        digitShow(digit__);
        __delay_ms(2);
        C4_SetHigh();
        digitShow(last__);
        C4_SetHigh();
        C3_SetLow();
        digitShow(last__);
        __delay_ms(2);
        C3_SetHigh();
        digitShow(digit__);
        
        
    }
}