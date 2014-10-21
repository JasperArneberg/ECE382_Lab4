ECE382_Lab4
===========

Lab 4: Etch-a-Sketch and Pong

C2C Jasper Arneberg  
T5 ECE 382
Capt Trimble  

##Prelab

####Data Types
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
| Iteration | a  | b  | c  | d  | e  |
|-----------|----|----|----|----|----|
| 1st       | 2  | 2  | 3  | 4  | 2  |
| 2nd       | 8  | 9  | 8  | 7  | 8  |
| 3rd       | 14 | 15 | 15 | 13 | 15 |
| 4th       | 20 | 21 | 20 | 19 | 20 |

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

The extern directive allows teh complied program to reference functions that are defined in external files. The compiler compiles the code without seeing the other files, so this directive is crucial.  

What it the role of the .global driective in a .asm file?  

The .global directive allows specific functions to be referenced and called by externaTl files. This occurs when the linker links together two or more object files.

##Lab

####Required Functionality
The required functionality was easily implemented by editing the code given by Dr. Coulston on his website. A third parameter, color, was added as an input.

![alt text](https://github.com/JasperArneberg/ECE382_Lab4/blob/master/imgae.png?raw=true "image")

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


##Documentation
I used http://www.tablesgenerator.com/markdown_tables to generate markdown tables efficiently. 
