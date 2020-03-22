#include <stdlib.h>
#include <uart.h>

void memcpy(void * dest, void * src, int bytes) {
    char * d = dest, * s = src;
    while (bytes--) {
        *d++ = *s++;
    }
}

void bzero(void * dest, int bytes) {
    char * d = dest;
    while (bytes--) {
        *d++ = 0;
    }
}

void swap(char *a, char *b){
    char aux = *a;
    *a = *b;
    *b = aux;
    return;
}

char * itoa(int i) {
    static char intbuf[12];
    int j = 0, isneg = 0;

    if (i == 0) {
        intbuf[0] = '0';
        intbuf[1] = '\0';
        return intbuf;
    }

    if (i < 0) {
        isneg = 1;
        i = -i;
    }

    while (i != 0) {
       intbuf[j++] = '0' + (i % 10);
       i /= 10;
    }

    if (isneg)
        intbuf[j++] = '-';

    intbuf[j] = '\0';
    j--;
    i = 0;
    while (i < j) {
        swap(&intbuf[i], &intbuf[j]);
        i++;
        j--;
    }

    return intbuf;
}

//convert unsigned int32 to char *
char * uint32toa(uint32_t i){
    static char intbuf[33]; //need 32 bits + '\0'
    int j = 0;
    if (i == 0) { //case i == 0 --> return a '0' and '\0'
        intbuf[0] = '0';
        intbuf[1] = '\0';
        return intbuf;
    }
    while (i != 0) {
        intbuf[j++] = '0' + (i % 10);
        i /= 10;
    }
    intbuf[j] = '\0';
    j--;
    i = 0;
    while ((int)i < j) {
        swap(&intbuf[i], &intbuf[j]);
        i++;
        j--;
    }

    return intbuf;

}
