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
	x=4;		y=4;
	drawBlock(y,x,color);

	while(1) {

			if (UP_BUTTON == 0) {
				while(UP_BUTTON == 0);
				if (y>=1) y=y-1;
				button_press = TRUE;
			} else if (DOWN_BUTTON == 0) {
				while(DOWN_BUTTON == 0);
				if (y<=6) y=y+1;
				button_press = TRUE;
			} else if (LEFT_BUTTON == 0) {
				while(LEFT_BUTTON == 0);
				if (x>=1) x=x-1;
				button_press = TRUE;
			} else if (RIGHT_BUTTON == 0) {
				while(RIGHT_BUTTON == 0);
				if (x<=10) x=x+1;
				button_press = TRUE;
			}

			if (AUX_BUTTON==0) {
				while(AUX_BUTTON == 0);
				if (color==WHITE) {
					color = BLACK;
				} else {
					color = WHITE;
				}
			}

			if (button_press) {
				button_press = FALSE;
				drawBlock(y,x,color);
			}
		}
}
