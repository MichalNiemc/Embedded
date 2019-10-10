/*****************************************************************************
 *   ex2.c:  main C entry file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2006, Philips Semiconductor
 *   All rights reserved.
 *
******************************************************************************/

#include "LPC214x.h"                        /* LPC21xx definitions */
#include "type.h"

int stan;

void delay(volatile unsigned int time)
{
	while(time--);
}

/*****************************************************************************
**   Main Function  main()
******************************************************************************/
int main (void)
{
//ustawienie wybranych linii jako wyjœciowe, pozosta³e bêd¹ jako wejœciowe
	IODIR1|=(1<<20)|(1<<21)|(1<<22)|(1<<23)|(1<<24)|(1<<25);
	IOSET1=(1<<20)|(1<<21)|(1<<22)|(1<<23)|(1<<24)|(1<<25);
	
	while( 1 ) 
	{
		stan=IOPIN0; // zapisanie do zmiennej ca³ego portu
		
		if(stan & (1<<4)) //jeœli SW0 nie jest wciœniêty
		{
			IOSET1=(1<<23);
		}
		else //jeœli wciœniêty
		{
			IOCLR1=(1<<23);
		}

		if(stan & (1<<5)) //jeœli SW1 nie jest wciœniêty
		{
			IOSET1=(1<<24);
		}
		else //jeœli wciœniêty
		{
			IOCLR1=(1<<24);
		}

		if(stan & (1<<6)) //jeœli SW2 nie jest wciœniêty
		{
			IOSET1=(1<<25);
		}
		else //jeœli wciœniêty
		{
			IOCLR1=(1<<25);
		}

		if (stan & (1 << 7))
		{
			IOSET = (1 << 22);
		}
		else
		{
			IOCLR = (1 << 7);
		}

		if (stan & (1 << 8))
		{
			IOSET = (1 << 21);
		}
		else
		{
			IOCLR = (1 << 8);
		}

		if (stan & (1 << 9))
		{
			IOSET = (1 << 20);
		}
		else
		{
			IOCLR = (1 << 9);
		}
		
	}

	return 0;

}

/*****************************************************************************
**                            End Of File
*****************************************************************************/

