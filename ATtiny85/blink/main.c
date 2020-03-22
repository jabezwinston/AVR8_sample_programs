/*
 *  Author : Jabez Winston C
 *  
 *  Blink ATtiny85 board LED
 */

#include <avr/io.h>
#include <util/delay.h>

int main ()
{
    DDRB = (1<<1);

    while (1)
    {
        PORTB ^= (1<<1);
        _delay_ms(100);
    }

    return 0;
}