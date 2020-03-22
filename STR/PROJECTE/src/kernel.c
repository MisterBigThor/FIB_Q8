#include <stddef.h>
#include <stdint.h>
#include <uart.h>
#include <stdlib.h>
#include <atag.h>

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    (void) r0;
    (void) r1;
    (void) atags;

    uart_init();
    uart_puts("[GreenTreeOS][MAIN] : Hello World!\r\n");

    uart_puts("[GreenTreeOS][MAIN] : atags\r\n");
    uart_puts("\r\n");
    display_atags((atag_t *)atags);
    uart_puts("[GreenTreeOS][MAIN] : memory available->");
    uart_puts(uint32toa(get_mem_size((atag_t *)atags)));
    uart_puts("\r\n");
    /*
    char str[100];
    */


    while (1) {
        uart_putc(uart_getc());
        uart_putc('\n');
    }
}
