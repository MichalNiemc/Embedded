/*****************************************************************************
 *   ex1.c:  main C entry file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2006, Philips Semiconductor
 *   All rights reserved.
 *
******************************************************************************/

#include "LPC214x.h"                        /* LPC21xx definitions */
#include "type.h"

int stan;
int licznik;

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
	IODIR1|=(1<<22)|(1<<23)|(1<<24)|(1<<25);
	IOSET1=(1<<22)|(1<<23)|(1<<24)|(1<<25);
	
	licznik=0;
	
	while( 1 ) 
	{
		stan=IOPIN0;
		
		if(stan & (1<<4)) //je�li SW0 nie jest wci�ni�ty
		{
			
		}
		else //je�li wci�ni�ty
		{
			licznik++;
		}
		if(stan & (1<<5)) //je�li SW1 nie jest wci�ni�ty
		{
			
		}
		else //je�li wci�ni�ty
		{
			licznik--;
		}
		if(stan & (1<<6)) //je�li SW2 nie jest wci�ni�ty
		{
			
		}
		else //je�li wci�ni�ty
		{
			licznik=0;
		}
		if(stan & (1<<7)) //je�li SW3 nie jest wci�ni�ty
		{
			;
		}
		else //je�li wci�ni�ty
		{
			licznik=0x0F;
		}
		
		//wystaw stan licznika na diody
		IOSET1=(1<<22)|(1<<23)|(1<<24)|(1<<25);//wygas wszystkie diody
		IOCLR1=(licznik<<22);//zapal te gdzie 1 w liczniku
		
	}

	return 0;

}

/*****************************************************************************
**                            End Of File
*****************************************************************************/

