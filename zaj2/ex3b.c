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
//ustawienie wybranych linii jako wyj�ciowe, pozosta�e b�d� jako wej�ciowe
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
		// Czytaj�c IOPIN musimy zamaskowac tylko te piny kt�re nas interesuj�
		newButtonState = (~IOPIN0 & (BUTTON0 | BUTTON1 | BUTTON2 | BUTTON3));
		// negacja IOPIN ('~'), pozwala miec w zmiennej wcisniety klawisz reprezentowany 1
		
		// je�li stan klawiszy si� zmieni� od ostatniego razu
		if (oldButtonState != newButtonState)
		{
		  // po kr�tkim czasie (20ms)...
		  delay(20000);               
		  // ... ponownie sprawdzamy stan ("debouncing")
		  buttonState = (~IOPIN0 & (BUTTON0 | BUTTON1 | BUTTON2 | BUTTON3));   
	
		  // sprawdzamy czy nowy stan jest stabilny
		  if(buttonState == newButtonState)
		  {
			// je�li stan si� zmieni� i klawisze zosta�y oczyszczone
			// 'debounced' (przez ponowne sprawdzenie po ustalonym czasie
			// mo�na by� pewnym �e to rzeczywiste wci�niecie klawisza
			// a nie zak��cenie lub 'szpilka'
	
			//teraz obs�uga klawiatury
			if(buttonState & BUTTON0 ) //je�li SW0 nie jest wci�ni�ty
			{
				licznik++;
			}
			if(buttonState & BUTTON1 ) //je�li SW1 nie jest wci�ni�ty
			{
				licznik--;
			}
			if(buttonState & BUTTON2 ) //je�li SW2 nie jest wci�ni�ty
			{
				licznik=0;
			}
			if(buttonState & BUTTON3 ) //je�li SW3 nie jest wci�ni�ty
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
