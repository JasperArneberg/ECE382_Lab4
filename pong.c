/**
 * This is the implementation file. All of the functions are defined here.
 */

#include "lab4.h"

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
ball moveBall(ball oldBall) {
	ball newBall = oldBall;								//keeps default values the same
	newBall.xpos = oldBall.xpos + oldBall.xvel;
	newBall.ypos = oldBall.ypos + oldBall.yvel;

	if (detectxmin(newBall.xpos)==true) {				//check for collision
		newBall.xpos = 0;								//reset to 0
		newBall.xvel = -newBall.xvel;					//switch velocity direction
	}

	if (detectxmax(newBall.xpos)==true) {
		newBall.xpos = WIDTH;							//reset to max position
		newBall.xvel = -newBall.xvel;
	}

	if (detectymin(newBall.ypos)==true) {
		newBall.ypos = 0;
		newBall.yvel = -newBall.yvel;
	}

	if (detectymax(newBall.ypos)==true) {
		newBall.ypos = HEIGHT;
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
