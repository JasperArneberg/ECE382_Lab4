//-------------------------------------------------------------------------------
//	Name:		Dr. Chris Coulston
//	Term:		Fall 2014
//	MCU:		MSP430G2553
//	Lecture:	22
//	Date:		16 October 2014
//	Note:		Demonstration of how to combine C and assembly lanugage.
//-------------------------------------------------------------------------------
#include <msp430g2553.h>
#include "lab4.h"

void main() {

	unsigned char	x, y, button_press, color;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;
	color = BLACK;

	init();
	initNokia();
	clearDisplay();
	x=X_START;										//initialize
	y=Y_START;
	drawBlock(y,x,color);

	while(1) {



		long i = 1000000;
		while (i > 0) {
			i--;									//decrement
		}
		drawBlock(y,x,BLACK);
		y++;
		x++;

	}
}
