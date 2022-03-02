/*
 * File:   main.c
 * Author: garrett
 *
 * Created on January 30, 2022, 12:41 PM
 */


#include "xc.h"

#include "wait_head.h"
#include "stdint.h"
#include "lcd.h"
#include <stdio.h>


#pragma config ICS = PGx1          // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config FWDTEN = OFF        // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config GWRP = OFF          // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF           // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF        // JTAG Port Enable (JTAG port is disabled)


// CW2: FLASH CONFIGURATION WORD 2 (see PIC24 Family Reference Manual 24.1)
#pragma config I2C1SEL = PRI       // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF       // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = ON       // Primary Oscillator I/O Function (CLKO/RC15 functions as I/O pin)
#pragma config FCKSM = CSECME      // Clock Switching and Monitor (Clock switching is enabled, 
                                       // Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = FRCPLL      // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))

/*void __attribute__((__interrupt__, __auto_psv__)) _ADC1Interrupt(void) {
    IFS0bits.AD1IF = 0;
    putVal(ADC1BUF0);
    
}*/


int displayFlag=0;

char hourArr[]= {'0','1','2','3','4','5','6','7','8','9'};
int j=0;
 int i=0;
 int z=0;
 int x=0;

void wait(int k){
    
    for(x=0;x<k;x=x+1){
        wait_1ms();
    }
}


/*void __attribute__((__interrupt__, __auto_psv__)) _T3Interrupt(void) {
    _T3IF = 0; TMR3 = 0;
    displayFlag=1;
}*/





int main(void)
{
   CLKDIVbits.RCDIV = 0;
   AD1PCFG = 0x9fff; //all digital inputs and outputs
   I2C2BRG = 0x9D;
   I2C2CONbits.I2CEN = 1;
   _I2CSIDL = 0;
    IFS3bits.MI2C2IF=0;
    lcd_init();  
    //init_t2();
    
    
  
  CMCON = 0x07; // To turn off comparators
  //ADCON1bits = 0x06; // To turn off analog to digital converters
  TRISB = 0; // PORT B as output port
  PORTB = 0x0F;
     
        //startClock();
        //if(displayFlag==1){
         //setTime(curTime-1);
            
        //}    
    int i=0;
    
    int z=0;
    
    while(1)
    { 
        for(i=0;i<25;i=i+1){
            PORTB= 0b00001111;
            wait(1000);
            
            
            lcd_setCursor(2,0);
            if(i<10){
                
                lcd_printChar('0');
                lcd_setCursor(3,0);
                lcd_printChar(hourArr[i]);
            }
            else if(i>=10 && i<20){
                lcd_printChar('1');
                lcd_setCursor(3,0);
                lcd_printChar(hourArr[i%10]);
            }
            else{
                lcd_printChar('2');
                lcd_setCursor(3,0);
                lcd_printChar(hourArr[i%20]);
            }
         
            for(j=0; j<6 ; j=j+1){
                
               
                
                lcd_setCursor(4,0);
                lcd_printChar(':');
                lcd_setCursor(5,0);
                lcd_printChar(hourArr[j]);
                
               
                for(z=0;z<10;z=z+1){
                    wait(1000);
                    lcd_setCursor(6,0);
                    lcd_printChar(hourArr[z]);
                    if(z==9){
                        wait(10);
                        lcd_setCursor(6,0);
                        lcd_printChar('0');
                    }
                    
                }
                 
                //printing formatted string
          
                PORTB= 0b00001111;
            
                }
         
            
        }
        i=0;
         for(i=0;i<5;i=i+1){
             PORTB= 0b00001111;
            wait(10);
            
            
            lcd_setCursor(2,0);
            if(i<10){
                
                lcd_printChar('0');
                lcd_setCursor(3,0);
                lcd_printChar(hourArr[i]);
            }
           
         
            for(j=0; j<6 ; j=j+1){
                
               
                
                lcd_setCursor(4,0);
                lcd_printChar(':');
                lcd_setCursor(5,0);
                lcd_printChar(hourArr[j]);
                
               
                for(z=0;z<10;z=z+1){
                    wait(1000);
                    lcd_setCursor(6,0);
                    lcd_printChar(hourArr[z]);
                    if(z==9){
                        wait(1000);
                        lcd_setCursor(6,0);
                        lcd_printChar('0');
                    }
                    
                }
                 
                //printing formatted string
          
                PORTB= 0b00001111;
            
                }
         
            
        }
        
                
        
    
       
      
        /*if(displayFlag==1){
            lcd_setCursor(0,0);
            
            
            if(j<10){
                lcd_setCursor(6,0);
                lcd_printChar('2');
            }
            
            else if(j<21&&j>=10){
                lcd_setCursor(6,0);
                lcd_printChar('1');
                
            }
            
            else{
                lcd_setCursor(6,0);
                lcd_printChar('0');
            }
            
            tempTime=min[j];
            lcd_setCursor(7,0);
            lcd_printChar(tempTime);
            displayFlag=0;
           
        }
       
        
      
    
        
        */
    }
        
       
}
   