#define F_CPU 16e6  // Arduino Uno's ATmega328P runs at 16MHz 

#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB|=(1<<5);

	while(1)
	{
	PORTB|=(1<<5);
	_delay_ms(100);
	PORTB&=~(1<<5);
	_delay_ms(100);
	}
}