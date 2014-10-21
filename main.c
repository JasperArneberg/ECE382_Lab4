/**
 * This is the main.c file. The main loop is contained here.
 */

#include <msp430.h>
#include "lab4.h"

void main(void) {
    // === Initialize system ================================================
    	IFG1=0; /* clear interrupt flag1 */
    	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
    	char button_press = FALSE;
    	char color = BLACK;

    	init();
    	initNokia();
    	clearDisplay();

    ball myBall = createBall(X_START,Y_START,1,2,3); //creates ball at (0,0) with velocity (1,2) and radius 3

    while(1) {							//infinte loop
    	myBall = moveBall(myBall);		//put breakpoint here to observe ball movement
       	drawBlock(myBall.xpos,myBall.ypos,BLACK);

    	//wait for a certain period of time
    	long i = 1000000;
    	while (i > 0) {
    	i--;                                    //decrement
    	}
    }
}
