/**
 * This is the main.c file. The main loop is contained here.
 */

#include <msp430.h>
#include "lab4.h"

void main(void) {
    // === Initialize system ================================================
    	IFG1=0; /* clear interrupt flag1 */
    	WDTCTL=WDTPW+WDTHOLD; /* stop WD */

    	init();
    	initNokia();
    	clearDisplay();

    ball myBall = createBall(XPOS_0,YPOS_0,XVEL_0,YVEL_0,4); //creates ball at (1,1) with velocity (1,1) and radius 4
    ball myBall2 = createBall(3,4,-1,1,4);

    while(1) {							//infinte loop
    	myBall = moveBall(myBall);		//put breakpoint here to observe ball movement
    	myBall2 = moveBall(myBall2);

    	clearDisplay();
       	drawBall(myBall.xpos,myBall.ypos);
       	drawBall(myBall2.xpos,myBall2.ypos);

    	waitTime(DELAY);				//wait for a certain period of time
    }
}
