#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "millis.h"

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


//SETUP https://wokwi.com/projects/363071204090063873

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
#define GREEN 0
#define YELLOW 1
#define RED 2
#define BUTTON 2

int main(void)
{
    

    BIT_SET(DDRB, GREEN);
    BIT_SET(DDRB, YELLOW);
    BIT_SET(DDRB, RED);
    BIT_CLEAR(DDRD, BUTTON); 

    while(1){
        if (BIT_CHECK(PIND, BUTTON)){
            _delay_ms(1000);
            BIT_CLEAR(PORTB, RED);
            BIT_SET(PORTB, YELLOW);
            _delay_ms(2000); 
            BIT_CLEAR(PORTB,YELLOW);
            BIT_SET(PORTB, GREEN);
            _delay_ms(5000);  
            BIT_CLEAR(PORTB, GREEN); 
            BIT_SET(PORTB, YELLOW); 
            _delay_ms(2000); 
            BIT_CLEAR(PORTB, YELLOW); 
        }
        BIT_SET(PORTB, RED); 
    }
	return 0;
}