/*
 * Seven_Segment.c
 *
 * Created: 8/12/2021 11:36:17 AM
 *  Author: Speed
 */ 
#include "../MCAL/DIO/Bit_Functions.h"
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"
void Seven_Segment_Inetialization()
{
	DIO_SetPinDirection(PORTC_,PIN0,OUTPUT);
	DIO_SetPinDirection(PORTC_,PIN1,OUTPUT);
	DIO_SetPinDirection(PORTC_,PIN2,OUTPUT);
	DIO_SetPinDirection(PORTC_,PIN3,OUTPUT);
}
void Seven_Segment_Set_Value(unsigned char num)
{
	DIO_SetPinValue(PORTC_,PIN0,GETBIT(num,0));
	DIO_SetPinValue(PORTC_,PIN1,GETBIT(num,1));
	DIO_SetPinValue(PORTC_,PIN2,GETBIT(num,2));
	DIO_SetPinValue(PORTC_,PIN3,GETBIT(num,3));
}