/*******************************************
  * Title: Lab 4: Etch-a-Sketch and Pong
  * Author: C2C Jasper Arneberg
  * Created: 21 Oct 2014
  * Description: This header file defines all buttons, functions, and
  * constants for implementation in the main.c or pong.c files.
  *
  * The code for the Etch-a-Sketch can be found in etch.c. This program
  * turns the LCD into a drawing tool. The auxilliary button switches
  * the color between white and black.
  *
  * The code for Pong can be found in pong.c and main.c. Thse files turn the
  * LCD into the classical game of Pong. The player controls the paddle
  * using the left and right paddles integrated with the nokia LCD.
*******************************************/

#ifndef LAB4_H_
#define LAB4_H_

extern void init();
extern void initNokia();
extern void clearDisplay(unsigned char color);
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);
extern void drawBall(unsigned char row, unsigned char col, unsigned char color);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define		WHITE			0
#define		BLACK			1

#define		XPOS_0			1
#define		YPOS_0			1
#define		XVEL_0			1
#define		YVEL_0			1
#define 	PADDLEPOS_0		0

#define 	HEIGHT 			11					//dimension of display
#define 	WIDTH 			7
#define 	true 			1					//takes place of boolean
#define 	false 			0
#define		DELAY			500000

/**
 * This ball structure contains five parameters. Nested structures were
 * originally used, but it added unnecessary complexity.
 */
typedef struct {
	int xpos;
	int ypos;
	int xvel;
	int yvel;
	int radius;
} ball;

/**
 * This function initializes a ball structure.
 */
ball createBall(int xpos, int ypos, int xvel, int yvel, int radius);

/**
 * This function "moves" a ball according to its velocity.
 */
ball moveBall(ball oldBall, int paddlePos);

/**
 * These functions check for collisions.
 */
char detectxmin(int x);
char detectxmax(int x);
char detectymin(int y);
char detectymax(int y);

/**
 * This function waits a certain number of loops.
 */
void waitTime(long loops);

void drawPaddle(int y, unsigned char color);

int movePaddle(int y);

char checkPaddle(ball myBall, int paddlePos);

char checkColor(char colorMode);

#endif /* LAB4_H_ */
