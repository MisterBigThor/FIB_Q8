
#include <stdint.h>
#include <atag.h>
#include <list.h>
#ifndef MEM_H
#define MEM_H

#define PAGE_SIZE 4096
#define KERNEL_HEAP_SIZE (1024*1024)

//flags for the page:
struct page_flags_t{
		uint8_t allocated: 1;			// This page is allocated to something
		uint8_t kernel_page: 1;			// This page is a part of the kernel
		uint8_t kernel_heap_page: 1;	// This page is a part of the kernel
		uint32_t reserved: 29;
};

//metadata append to a page.
struct page_t {
		uint32_t vaddr_mapped;		// The virtual address that maps to this page
		struct page_flags_t flags;
		struct list_head anchor;	//LIST anchor
};

typedef struct heap_segment{
    struct heap_segment * next;
    struct heap_segment * prev;
    uint32_t is_allocated;
    uint32_t segment_size;  // Includes this header
} heap_segment_t;
//constructor of the memory managment.
void mem_init(atag_t * atags);

//Alloc a new page.
void * alloc_page(void);

//free a page.
void free_page(void * ptr);


#endif
