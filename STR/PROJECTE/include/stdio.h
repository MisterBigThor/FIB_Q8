#ifndef STDIO_H
#define STDIO_H

/*
TBI:
-> char * redefinition of +.


*/

/*
Gets a char from the UART:
*/
char getc(void);

/*
Puts a char to the UART
*/
void putc(char c);

/*
Puts a String to the UART
*/
void puts(const char * s);

/*
Reads a string from the UART
*/
void gets(char * buf, int buflen);

#endif
