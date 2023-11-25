/******************************************************************************
 *
 * Module: main application
 *
 * File Name: main.c
 *
 * Description: source file for the main application
 *
 * Author: Ahmed Reda
 *
 *******************************************************************************/
#include "Ultrasonic.h"
#include "lcd.h"
#include "icu.h"
#include <avr/io.h>
int main (void)
{
	SREG |= (1<<7);
	uint16 distance = 0;
	Ultrasonic_init();
	LCD_init();
	LCD_displayString("Distance =   cm");
	while (1)
	{
		distance =  Ultrasonic_readDistance();
		LCD_moveCursor(0,10);
		if ((distance >=0) && (distance <10))
			{
				LCD_displayCharacter(' ');
				LCD_displayCharacter(' ');
				LCD_intgerToString(distance);
			}
			else if ((distance>=10) && (distance <100))
			{
				LCD_displayCharacter(' ');
				LCD_intgerToString(distance);
			}
			else if (distance >= 100)
			{
				LCD_intgerToString(distance);
			}

	}


}
