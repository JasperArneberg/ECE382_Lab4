/*******************************************
  * Title: Lab 4: Etch-a-Sketch and Pong
  * Author: C2C Jasper Arneberg
  * Created: 21 Oct 2014
  * Description: This header file defines buttons and
  * other constants for implementation in the main.c or
  * pong.c files.
*******************************************/

#ifndef LAB4_H_
#define LAB4_H_

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);
extern void drawBall(unsigned char row, unsigned char col);

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

#define 	HEIGHT 			11
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
ball moveBall(ball oldBall);

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

#endif /* LAB4_H_ */
