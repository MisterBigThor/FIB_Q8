#include <atag.h>
#include <uart.h>
#include <stdlib.h>

#ifdef _DEPLOY
uint32_t get_mem_size(atag_t * tag) {
   while (tag->tag != NONE) {
       if (tag->tag == MEM) return tag->mem.size;
       tag += tag->tag_size;
   }
   return 0; //expect never go here!
}
#else
uint32_t get_mem_size(atag_t * tag) {
    while (tag->tag != NONE) {
      if (tag->tag == MEM) return tag->mem.size;
      tag += tag->tag_size;
    }
   return 1024*1024*128; //hardcoded, the qemu don't support that
}
#endif
void display_atags(atag_t * tag){
    int i=0;
    while (tag->tag != NONE) {
      uart_puts(itoa(i));
      uart_puts("\r\n");
      uart_puts(uint32toa(tag->tag));
      uart_puts("\r\n");
      uart_puts(uint32toa(tag->tag_size));
      uart_puts("\r\n");
      tag += tag->tag_size;
      ++i;
    }
    return;
}
