#ifndef STDLIB_H
#define STDLIB_H
#include <stdint.h>
void memcpy(void * dest, void * src, int bytes);

void bzero(void * dest, int bytes);

void swap(char *a, char *b);

char * itoa(int i);

char * uint32toa(uint32_t i);

#endif
