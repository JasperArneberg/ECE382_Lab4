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
    	clearDisplay(WHITE);

    ball myBall = createBall(XPOS_0,YPOS_0,XVEL_0,YVEL_0,4); //creates ball at (1,1) with velocity (1,1) and radius 4
    ball myBall2 = createBall(3,4,-1,1,4);
    ball myBall3 = createBall(3,2,-1,1,4);
    ball myBall4 = createBall(7,4,1,1,4);

    int paddlePos = PADDLEPOS_0;
    unsigned char colorMode = BLACK;	//initialize color variable

    while(1) {							//infinte loop

    	myBall = moveBall(myBall, paddlePos);
    	myBall2 = moveBall(myBall2, paddlePos);
    	myBall3 = moveBall(myBall3, paddlePos);
    	myBall4 = moveBall(myBall4, paddlePos);

    	paddlePos = movePaddle(paddlePos);

    	colorMode = checkColor(colorMode);
    	clearDisplay(colorMode);
       	drawBall(myBall.xpos,myBall.ypos,colorMode);
       	drawBall(myBall2.xpos,myBall2.ypos,colorMode);
       	drawBall(myBall3.xpos,myBall3.ypos,colorMode);
       	drawBall(myBall4.xpos,myBall4.ypos,colorMode);
       	drawPaddle(paddlePos,colorMode);


    	waitTime(DELAY);				//wait for a certain period of time
    }
}
