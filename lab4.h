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

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define		WHITE			0
#define		BLACK			1

#define		X_START			1
#define		Y_START			1



#endif /* LAB4_H_ */
