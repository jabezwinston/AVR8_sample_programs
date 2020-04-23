/*
 * ATTiny85ADC.c
 *
 * Created: 15-03-2020 10:54:34
 * Author : Stephen Kingston
 */ 

#include <avr/io.h>

#include <util/delay.h>
#include <avr/interrupt.h>

void ADCInit();
uint16_t ADCreading = 1024;
#define dataPin PB1
#define LATCH PB0
#define CLK PB3
#define OE PB5
int i, j, k;

const uint8_t numbers[] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
uint8_t digits[4] = {0, 0 ,0, 0};
	
#define SET_BIT(x,y)(x |=(1<<y))
#define CLR_BIT(x,y)(x &=~(1<<y))

void printDigit(uint8_t digit, uint8_t position);
void Display(uint16_t value);
void ADCInit();

int main(void)
{
	DDRB = (1 << PB0) | (1 << PB1) | (1 << PB3) | (1 << PB4) | (1 << PB5);
	ADCInit();
   	 while (1) 
    	{
			ADCSRA |= (1 << ADSC);
			while((ADCSRA & (1<<ADSC)));
			ADCreading = ADC;
			_delay_us(1);
			Display(ADCreading);
    	}
}

void ADCInit()
{
	// Enable ADC and set sampling rate with 128 pre-scaler & Vcc as internal reference voltage.
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
	//Setting PB2 as analog input
	ADMUX = (1 << MUX0);
}

void Display(uint16_t value)
{	
	for(k = 0; k <= 3; k++)
	{
		digits[i] = value%10;
		value = value/10;
		printDigit(numbers[digits[k]], (1 << k));
	}
}

void printDigit(uint8_t digit, uint8_t position)
{
	SET_BIT(PORTB,OE);
	_delay_us(1);

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j <= 7; j++)
		{
			if (i == 0)
			{
				if((position >> j) & 1)
					CLR_BIT(PORTB, PB1);
				else
					SET_BIT(PORTB,PB1);
			}
			if (i == 1)
			{
				if((digit >> j) & 1)
					SET_BIT(PORTB,PB1);
				else
					CLR_BIT(PORTB, PB1);
			}
			_delay_us(1);
			CLR_BIT(PORTB,CLK);
			_delay_us(1);
			SET_BIT(PORTB,CLK);
			_delay_us(1);
		}
	}

	CLR_BIT(PORTB,LATCH);
	_delay_us(1);
	SET_BIT(PORTB,LATCH);
	_delay_us(1);
	
	CLR_BIT(PORTB,OE);
	_delay_us(1);
}