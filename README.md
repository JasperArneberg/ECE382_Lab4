ECE382_Lab4
===========

Lab 4: Etch-a-Sketch and Pong

C2C Jasper Arneberg  
T5 ECE 382  
Capt Trimble  

##Prelab

####Data Types
This table shows the minimum and maximum values of different data types in C.
| Size   | Signed/Unsigned | Type                 | Min value                  | Max value                  |
|--------|-----------------|----------------------|----------------------------|----------------------------|
| 8-bit  | unsigned        | unsigned char        | 0                          | 255                        |
| 8-bit  | signed          | char                 | -128                       | 127                        |
| 16-bit | unsigned        | unsigned short / int | 0                          | 65,535                     |
| 16-bit | signed          | short / int          | -32,768                    | 32,767                     |
| 32-bit | unsigned        | unsigned long        | 0                          | 4,294,967,295              |
| 32-bit | signed          | long                 | -2,147,483,648             | 2,147,483,647              |
| 64-bit | unsigned        | unsigned long long   | 0                          | 18,446,744,073,709,551,615 |
| 64-bit | signed          | long long            | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807  |

This table shows the typedef declarations. These can be used to solidify the connection between the data type and the number of bits that are stored.
| Type   | Meaning               | C typedef declaration             |
|--------|-----------------------|-----------------------------------|
| int8   | unsigned 8-bit value  | typedef unsigned char int8;       |
| sint8  | signed 8-bit value    | typedef char sint8;               |
| int16  | unsigned 16-bit value | typedef unsigned short int16;     |
| sint16 | signed 16-bit value   | typedef short sint16;             |
| int32  | unsigned 32-bit value | typedef unsigned long int32;      |
| sint32 | signed 32-bit value   | typedef long sint32;              |
| int64  | unsigned 64-bit value | typedef unsigned long long int64; |
| sint64 | signed 64-bit value   |                                   |

####Calling/Return Convention
This table was used to investigate how inputs and outputs are stored within a function.
| Iteration | a  | b  | c  | d  | e  |
|-----------|----|----|----|----|----|
| 1st       | 2  | 2  | 3  | 4  | 2  |
| 2nd       | 8  | 9  | 8  | 7  | 8  |
| 3rd       | 14 | 15 | 15 | 13 | 15 |
| 4th       | 20 | 21 | 20 | 19 | 20 |

This table shows where the values are stored when the C code is assembled.
| Parameter                     | Value Sought |
|-------------------------------|--------------|
| Starting address of func      | 0xcoba       |
| Ending address of func        | 0xc0c6       |
| Register holding w            | R12          |
| Register holding x            | R13          |
| Register holding y            | R14          |
| Register holding z            | R15          |
| Register holding return value | R12          |

####Cross language build constructs

What is the role of the extern directive in a .c file?  

The extern directive allows the complied program to reference functions that are defined in external files. The compiler compiles the code without seeing the other files, so this directive is crucial.  

What it the role of the .global driective in a .asm file?  

The .global directive allows specific functions to be referenced and called by externaTl files. This occurs when the linker links together two or more object files.

##Lab

####Required Functionality
The required functionality was to create an etch-a-sketch program. This was easily implemented by editing the code given by Dr. Coulston on his website. A third parameter, color, was added as an input to the drawBlock() subroutine. The new subroutine can be seen below:

```
;-------------------------------------------------------------------------------
;	Name:		drawBlock
;	Inputs:		R12 row to draw block
;				R13	column to draw block
;				R14 color of block (white or black)
;	Outputs:	none
;	Purpose:	draw an 8x8 block of black pixels at screeen cordinates	8*row,8*col
;				The display screen, for the purposes of this routine, is divided
;				into 8x8 blocks.  Consequently the codinate system, for the purposes
;				of this routine, start in the upper left of the screen @ (0,0) and
;				end @ (11,7) in the lower right of the display.
;	Registers:	R5	column counter to draw all 8 pixel columns
;-------------------------------------------------------------------------------
drawBlock:
	push	R5
	push	R12
	push	R13
	push 	R14

	rla.w	R13					; the column address needs multiplied
	rla.w	R13					; by 8in order to convert it into a
	rla.w	R13					; pixel address.
	call	#setAddress			; move cursor to upper left corner of block

	mov		#1, R12
	mov.w	#0x08, R5			; loop all 8 pixel columns

	tst		R14
	jz		white
black:
	mov		#0xFF, R13			; black
	jmp 	loopdB
white:	
	mov		#0x00, R13			; white

loopdB:
	call	#writeNokiaByte		; draw the pixels
	dec.w	R5
	jnz		loopdB

	pop		R14
	pop		R13
	pop		R12
	pop		R5

	ret							; return whence you came
```

####B Functionality
A bouncing block program was created for B functionality. To accomplish this, the same structure that was used in Assignment 6 was carried over into this one.
```
typedef struct {
	int xpos;
	int ypos;
	int xvel;
	int yvel;
	int radius;
} ball;
```

The ball structure made it extremely easy to have multiple balls bouncing on the screen. It is important to note that the radius parameter had no use in this implementation, but it could be used to draw differently sized balls later on if desired. That's why it was left in as part of the structure.

The createBall() and moveBall() functions were used multiple times when implementing this functionality. These functions allowed for modular and reusable code that made everything very organized.

####A Functionality
The A functionality required creating the game of pong. Since the bouncing ball was already implemented, the only step remaining was to incorporate the paddle. The paddle was drawn using two calls to drawBlock(), and the position was tracked with the variable paddlePos. The most difficult section of code is shown below within the moveBall() function. This code tested to see whether or not the paddle was underneath the ball. If the paddle was absent, the game restarted.
```
	if (detectxmax(newBall.xpos)==true) {
		if (oldBall.ypos == paddlePos || oldBall.ypos == (paddlePos + 1)) {
			newBall.xpos = WIDTH-1;							//reset to max position - 1
			newBall.xvel = -newBall.xvel;
		} else {
			newBall.xpos = 0;							//start game over
		}
	}
```

####Bonus Functionality: Multiple Balls
Using the ball structure, multiple balls were initialized onto the screen. The balls were called myBall1 and myBall2 as can be seen in main.c. It would be easy to add in more balls if desired.

####Bonus Functionality: Spherical Ball Shape
In order to enhance the visual experience for the viewer, the ball was drawn as a sphere instead of a block. This was accomplished using a new subroutine entitled drawBall() in the nokia.asm file. This subroutine was modeled off drawBlock() and can be seen below:
```
;-------------------------------------------------------------------------------
;	Name:		drawBall
;	Inputs:		R12 row to draw block
;				R13	column to draw block
;	Outputs:	none
;	Purpose:	This subroutine is very similar to drawBlock, except it draws a
;				spherical ball instead of an 8x8 block.
;	Registers:	R5	column counter to draw all 8 pixel columns
;-------------------------------------------------------------------------------
drawBall:
	push	R5
	push	R12
	push	R13

	rla.w	R13					; the column address needs multiplied
	rla.w	R13					; by 8in order to convert it into a
	rla.w	R13					; pixel address.
	call	#setAddress			; move cursor to upper left corner of block

	mov		#1, R12
	clr		R5					; used for 8 loops

loopBall:
	cmp		#0,		R5
	jz		col07
	cmp		#7,		R5
	jz		col07
	cmp		#1,		R5
	jz		col16
	cmp		#6,		R5
	jz		col16

col2345:						;columns 2,3,4,5
	mov.w	#0xFF,	R13			;11111111
	jmp		draw_time

col07:							;columns 0 and 7
	mov.w	#0x3C,	R13			;00111100
	jmp		draw_time

col16:							;columns 1 and 6
	mov.w	#0x7E,	R13			;01111110
	jmp		draw_time

draw_time:
	call	#writeNokiaByte		; draw the pixels

	inc		R5
	cmp		#8,		R5
	jnz		loopBall

	pop		R13
	pop		R12
	pop		R5

	ret							; return whence you came
```

####Bonus Functionality: Color Inversion
The program was enhanced to invert colors with the press of the auxilliary button (SW 3). This was implemented by adding in a color parameter, colorMode, to the drawBlock(), drawBall(), clearScreen(), and drawPaddle() methods.

####Debugging
The following code was used to make the program wait a specified period of time. Originally, the code did not wait nearly as long as it should.
```
//wait for a certain period of time
int i = 1000000;
while (i > 0) {
i--;									//decrement
}
```

The error was that the variable i was stored as an int. This has max value of 32,767. To fix this problem, i was stored as a long, which has a max value of over 2 billion, high enough for this functionality.

```
//wait for a certain period of time
long i = 1000000;
while (i > 0) {
i--;									//decrement
}
```

Originally, drawBall() did not draw an acutal sphere. It was determined that the problem lay in this part of the subroutine:
```
col16:							;columns 1 and 6
	mov.w	#0x7D,	R13			;01111110
	jmp		draw_time
```

After a long period of thinking, it was finally realized that the hex value for 01111110 was 0x7E instead of 0x7D. Once this was corrected, the program ran as expected.

```
col16:							;columns 1 and 6
	mov.w	#0x7E,	R13			;01111110
	jmp		draw_time
```

##Documentation
I used http://www.tablesgenerator.com/markdown_tables to generate markdown tables efficiently. 
