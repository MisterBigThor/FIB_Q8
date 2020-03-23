#include <stddef.h>
#include <stdint.h>
#include <uart.h>
#include <stdlib.h>
#include <atag.h>
#include <mem.h>


void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    (void) r0;
    (void) r1;
    (void) atags;


    uart_init();
    uart_puts("[GreenTreeOS][MAIN] : Hello World!\r\n");

    //uart_puts("[GreenTreeOS][MAIN] : atags\r\n");
    //display_atags((atag_t *)atags);
		uart_puts("[GreenTreeOS][MAIN] : Initializing Memory Module\n");
    mem_init((atag_t *)atags);
    uart_puts("[GreenTreeOS][MAIN] : memory available->");
    uart_puts(uint32toa(get_mem_size((atag_t *)atags)));
    uart_puts("\r\n");

		uart_puts("Try to allocate a page:\r\n");
		int * p = alloc_page();
		uart_puts("Sizeof?: ");
		uart_puts(itoa(sizeof(p)));
		uart_puts("\r\nSet value 4:\r\n");
		p[0] = 4;
		uart_puts(itoa(p[0]));


    while (1) {
        uart_putc(uart_getc());
        uart_putc('\n');
    }
}
