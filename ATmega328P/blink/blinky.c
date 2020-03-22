/*
 * Blinks LED on connected to pin 13 (PB5 on Atmega328P)
 * Have a look at ATmega328_ArduinoUno_pinmap.jpg
 *
 * Authors : Jabez Winston C, Hariharan K
 *
 */

#define F_CPU 16e6  // Arduino Uno's ATmega328P runs at 16MHz 

#include<avr/io.h>
#include<util/delay.h>

int main()
{
DDRB|=(1<<5); //Set PB5 as output by setting 5th bit DDRB register  

	while(1)
	{
	PORTB|=(1<<5);  //Set pin 13 (PB5)- High
	_delay_ms(100); //Wait for 100 ms
	PORTB&=~(1<<5); //Set pin 13 (PB5)- Low
	_delay_ms(100); //Wait for 100ms
	}
return 0;	
//Refer Atmega328P datasheet for details regarding DDRB and PORTB
}