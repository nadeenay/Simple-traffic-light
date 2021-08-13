/*
 * keypad_Interfacing.c
 *
 * Created: 8/11/2021 6:44:53 PM
 *  Author: Speed
 */
#define F_CPU 1600000
#include "../MCAL/DIO/Bit_Functions.h"
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"
#include <util/delay.h> 
void Traffic_Light()
{   //lights of the  traffic
	DIO_SetPinDirection(PORTA_,PIN5,OUTPUT);
	DIO_SetPinDirection(PORTB_,PIN5,OUTPUT);
	DIO_SetPinDirection(PORTD_,PIN5,OUTPUT);
	
	//start with the red led 
	DIO_SetPinValue(PORTA_,PIN5,LOW);
	DIO_SetPinValue(PORTB_,PIN5,LOW);
	DIO_SetPinValue(PORTD_,PIN5,LOW);
	
	
	Seven_Segment_Inetialization();
	Seven_Segment_Set_Value(0);
	unsigned char i;
	while(1)
	{
		for(i=0;i<=9;i++)	
		{
			Seven_Segment_Set_Value(i);
			_delay_ms(3000);
			if(i==3)
			{
				DIO_SetPinValue(PORTA_,PIN5,HIGH);
				DIO_SetPinValue(PORTB_,PIN5,LOW);
				DIO_SetPinValue(PORTD_,PIN5,LOW);	
			}
			else if(i==6)
			{
				DIO_SetPinValue(PORTA_,PIN5,LOW);
				DIO_SetPinValue(PORTB_,PIN5,HIGH);
				DIO_SetPinValue(PORTD_,PIN5,LOW);
				
			}
			else if(i==9)
			{
				DIO_SetPinValue(PORTA_,PIN5,LOW);
				DIO_SetPinValue(PORTB_,PIN5,LOW);
				DIO_SetPinValue(PORTD_,PIN5,HIGH);
				
			}
			
			}
		}
}