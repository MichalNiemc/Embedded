/*****************************************************************************
 *   ex1.c:  main C entry file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2006, Philips Semiconductor
 *   All rights reserved.
 *
******************************************************************************/

#include "LPC214x.h"                        /* LPC21xx definitions */
#include "type.h"

#define BUTTON0 (1<<4)
#define BUTTON1 (1<<5)
#define BUTTON2 (1<<6)
#define BUTTON3 (1<<7)

#define LED0 (1<<22)
#define LED1 (1<<23)
#define LED2 (1<<24)
#define LED3 (1<<25)

int licznik;

// zmienne do obslugi klawiatury 'Debouncing'
unsigned int buttonState;
unsigned int newButtonState, oldButtonState;

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
	IODIR1|=LED0|LED1|LED2|LED3;
	IOSET1=LED0|LED1|LED2|LED3;
	
	// Inicjalizacja zmiennych
	buttonState = newButtonState = oldButtonState = 0;
	buttonState = (BUTTON0 | BUTTON1 | BUTTON2 | BUTTON3);

	BS = 1111 0000
	IO = 0000 0000
	~IO = 1111 1111
	nBS = 1111 0000
	oBS = 0000 0000
	BS = 1111 0000
	oBS = 1111 0000
	nBs = 1111 0000
	IO = 0100 0000
	~IO = 1011 1111
	nBS = 1011 0000

	
	licznik=0;
	
	while( 1 ) 
	{
		// Czytaj¹c IOPIN musimy zamaskowac tylko te piny które nas interesuj¹
		newButtonState = (~IOPIN0 & (BUTTON0 | BUTTON1 | BUTTON2 | BUTTON3));
		// negacja IOPIN ('~'), pozwala miec w zmiennej wcisniety klawisz reprezentowany 1
		
		// jeœli stan klawiszy siê zmieni³ od ostatniego razu
		if (oldButtonState != newButtonState)
		{
		  // po krótkim czasie (20ms)...
		  delay(20000);               
		  // ... ponownie sprawdzamy stan ("debouncing")
		  buttonState = (~IOPIN0 & (BUTTON0 | BUTTON1 | BUTTON2 | BUTTON3));   
	
		  // sprawdzamy czy nowy stan jest stabilny
		  if(buttonState == newButtonState)
		  {
			// jeœli stan siê zmieni³ i klawisze zosta³y oczyszczone
			// 'debounced' (przez ponowne sprawdzenie po ustalonym czasie
			// mo¿na byæ pewnym ¿e to rzeczywiste wciœniecie klawisza
			// a nie zak³ócenie lub 'szpilka'
	
			//teraz obs³uga klawiatury
			if(buttonState & BUTTON0 ) //jeœli SW0 nie jest wciœniêty
			{
				licznik++;
			}
			if(buttonState & BUTTON1 ) //jeœli SW1 nie jest wciœniêty
			{
				licznik--;
			}
			if(buttonState & BUTTON2 ) //jeœli SW2 nie jest wciœniêty
			{
				licznik=0;
			}
			if(buttonState & BUTTON3 ) //jeœli SW3 nie jest wciœniêty
			{
				licznik=0x0F;
			}
			
			//wystaw stan licznika na diody
			IOSET1=LED0|LED1|LED2|LED3;//wygas wszystkie diody
			IOCLR1=(licznik<<22);//zapal te gdzie 1 w liczniku
		  }
	
		  // przepisanie nowego stanu
		  oldButtonState = buttonState;
		}
		
	}

	return 0;

}

/*****************************************************************************
**                            End Of File
*****************************************************************************/
