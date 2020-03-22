#include <stddef.h>
#include <stdint.h>


// Loop <delay> times in a way that the compiler won't optimize away
static inline void delay(int32_t count){
    asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
            : "=r"(count): [count]"0"(count) : "cc");
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    (void) r0;
    (void) r1;
    (void) atags;

    uart_init();
    uart_puts("[GreenTreeOS] : Hello World!\r\n");

    while (1) {
        uart_putc(uart_getc());
        uart_putc('\n');
    }
}