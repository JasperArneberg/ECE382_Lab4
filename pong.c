/**
 * This is the implementation file. All of the functions are defined here.
 */

#include "lab4.h"
#include <msp430.h>

/**
 * This function creates a ball with all of the necessary parameters.
 */
ball createBall(int xpos, int ypos, int xvel, int yvel, int radius) {
	ball newBall;
	newBall.xpos = xpos;
	newBall.ypos = ypos;
	newBall.xvel = xvel;
	newBall.yvel = yvel;
	newBall.radius = radius;
	return newBall;
}

/**
 * This function returns a ball with updated ball structure.
 */
ball moveBall(ball oldBall, int paddlePos) {
	ball newBall = oldBall;								//keeps default values the same
	newBall.xpos = oldBall.xpos + oldBall.xvel;
	newBall.ypos = oldBall.ypos + oldBall.yvel;

	if (detectxmin(newBall.xpos)==true) {				//check for collision
		newBall.xpos = 1;								//reset to 1
		newBall.xvel = -newBall.xvel;					//switch velocity direction
	}


	if (detectxmax(newBall.xpos)==true) {
		if (oldBall.ypos == paddlePos || oldBall.ypos == (paddlePos + 1)) {
			newBall.xpos = WIDTH-1;							//reset to max position - 1
			newBall.xvel = -newBall.xvel;
		} else {
			newBall.xpos = 0;							//reset
		}
	}


	if (detectymin(newBall.ypos)==true) {
		newBall.ypos = 1;
		newBall.yvel = -newBall.yvel;
	}

	if (detectymax(newBall.ypos)==true) {
		newBall.ypos = HEIGHT-1;
		newBall.yvel = -newBall.yvel;
	}

	return newBall;
}

/**
 * The following four functions check to see if the ball is about to have a collision,
 * and they all return true if a collision is occurring.
 */
char detectxmin(int x) {
	if (x < 0) {
		return true;
	}
	return false;
}

char detectxmax(int x) {
	if (x > WIDTH) {
		return true;
	}
	return false;
}

char detectymin(int y) {
	if (y < 0) {
		return true;
	}
	return false;
}

char detectymax(int y) {
	if (y > HEIGHT) {
		return true;
	}
	return false;
}

/**
 * This function waits a specific amount of time
 */
void waitTime(long loops) {
	long i = loops;
	while (i > 0) {
	i--;                                    //decrement
	}
	return;
}

/**
 * This function draws a paddle for a given y coordinate from 0 to HEIGHT
 */
void drawPaddle(int y, unsigned char color) {
	drawBlock(WIDTH+1,y,color);
   	drawBlock(WIDTH+1,y+1,color);
}

/**
 * This function moves the paddle in response to a button press
 */
int movePaddle(int pos) {
	if (LEFT_BUTTON == 0) {
		pos--;
	}
	if (RIGHT_BUTTON == 0) {
		pos++;
	}
	return pos;
}

/**
 * This function ensures that there is a paddle where the ball is bouncing.
 */
char checkPaddle(ball myBall, int paddlePos) {
	char result = true;
	if (detectxmax(myBall.xpos) == true) {
		if (myBall.ypos != paddlePos && myBall.ypos != paddlePos + 1) {
			result = false;
		}
	}
	return result;
}

/**
 * This function changes the color mode if the AUX button is pressed.
 */
char checkColor(char colorMode) {
	char result = colorMode;
		if (AUX_BUTTON == 0) {
			if (colorMode == BLACK) {
				result = WHITE;
			} else {
				result = BLACK;
			}
		}
	return result;
}
