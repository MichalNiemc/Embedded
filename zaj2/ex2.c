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
//ustawienie wybranych linii jako wyj�ciowe, pozosta�e b�d� jako wej�ciowe
	IODIR1|=(1<<20)|(1<<21)|(1<<22)|(1<<23)|(1<<24)|(1<<25);
	IOSET1=(1<<20)|(1<<21)|(1<<22)|(1<<23)|(1<<24)|(1<<25);
	
	while( 1 ) 
	{
		stan=IOPIN0; // zapisanie do zmiennej ca�ego portu
		
		if(stan & (1<<4)) //je�li SW0 nie jest wci�ni�ty
		{
			IOSET1=(1<<23);
		}
		else //je�li wci�ni�ty
		{
			IOCLR1=(1<<23);
		}

		if(stan & (1<<5)) //je�li SW1 nie jest wci�ni�ty
		{
			IOSET1=(1<<24);
		}
		else //je�li wci�ni�ty
		{
			IOCLR1=(1<<24);
		}

		if(stan & (1<<6)) //je�li SW2 nie jest wci�ni�ty
		{
			IOSET1=(1<<25);
		}
		else //je�li wci�ni�ty
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

