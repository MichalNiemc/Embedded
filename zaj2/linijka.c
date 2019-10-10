#include "LPC214x.h"
#include "type.h"

#define BUTTON0 (1<<4)
#define BUTTON1 (1<<5)
#define BUTTON2 (1<<6)

#define LED0 (1<<20)
#define LED1 (1<<21)
#define LED2 (1<<22)
#define LED3 (1<<23)
#define LED4 (1<<24)
#define LED5 (1<<25)

void delay(volatile unsigned int time)
{
	while(time--);
}
0000 0000 0000 0000 0000 0000

int main (void)
{
	IODIR1 |= LED0 | LED1 | LED2 | LED3 | LED4 | LED5;
	IOSET1 = LED0 | LED1 | LED2 | LED3 | LED4 | LED5;
	
	int szybkosc = 1000000; //standardowo na poczatek 1 s
	int i, j;
	unsigned int zapalone = 0;
	//unsigned int start = 0;

	unsigned int buttonState;
	unsigned int newButtonState, oldButtonState;

	buttonState = newButtonState = oldButtonState = 0;
	buttonState = (BUTTON0 | BUTTON1 | BUTTON2;


	while( 1 ) 
	{
		for (i = 20; i <= 25; i++)
		{
			if (i == 25)
			{
				j = 20;
			}
			else
			{
				j = i + 1;
			}

			newButtonState = (~IOPIN0 & (BUTTON0 | BUTTON1 | BUTTON2);
			if (oldButtonState != newButtonState)
			{
				delay(20000); // czekamy 20ms
				buttonState = (~IOPIN0 & (BUTTON0 | BUTTON1 | BUTTON2);

				if (buttonState == newButtonState)
				{
					if (buttonState & BUTTON0)
					{
						szybkosc = szybkosc + 100000; //zmniejszenie szybkosci poruszania o 100ms
					}

					if (buttonState & BUTTON1)
					{
						szybkosc = szybkosc - 100000; //zwiekszenie szybkosci poruszania o 100ms
					}
					/*
					if (buttonState & BUTTON2)
					{
						start = ~start;
					}
					*/
				}
			}

			oldButtonState = buttonState;

			//if (start) {
			delay(szybkosc);
			IOSET1 = LED0 | LED1 | LED2 | LED3 | LED4 | LED5;
			IOCLR1 = (1 << i) | (1 << j);
			//}
		}
	}
	return 0;
}
