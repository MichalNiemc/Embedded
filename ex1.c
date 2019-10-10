/*****************************************************************************
 *   ex1.c:  main C entry file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2006, Philips Semiconductor
 *   All rights reserved.
 *
******************************************************************************/

#include "LPC214x.h"                        /* LPC21xx definitions */
#include "type.h"

void delay(volatile unsigned int time)
{
	while(time--);
}

/*****************************************************************************
**   Main Function  main()
******************************************************************************/
//PAMIETAÆ O POD£¥CZENIU P0.14 W CELU WGRANIA BOOTLOADERA(POTEM OD£¥CZYÆ) //CHYBA, POTEM JESZCZE SPYTAÆ
int main (void)
{
//ustawienie wybranych linii
	IODIR1|=(1<<23)|(1<<24)|(1<<25); //ustawienie lini jako wejœcia
	IOSET1=(1<<23)|(1<<24)|(1<<25);  //ustawienie stanu wysokiego na liniach
	
	while( 1 ) //nieskoñczona pêtla
	{
		IOSET1=(1<<24)|(1<<25);		
		IOCLR1=(1<<23)|(1<<20);
		delay(1000000);
		IOSET1=(1<<23)|(1<<25);
		IOCLR1=(1<<24);
		delay(1000000);
		IOSET1=(1<<23)|(1<<24);
		IOCLR1=(1<<25);
		delay(1000000);
		IOSET1 = (1 << 22);
		IOCLR1 = (1 << 23) | (1 << 24);
		delay(1000000);
		IOSET = (1 << 21);
		IOCLR = (1 << 22);
		delay(1000000);
		IOSET = (1 << 20);
		IOCLR = (1 << 21);
		delay(1000000);
	}

	return 0;

}

/*****************************************************************************
**                            End Of File
*****************************************************************************/

