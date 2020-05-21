CC = gcc

CFLAGS   = -Wall -O -std=c99 -march=native -I. -D_GNU_SOURCE -Wno-unused-value
CFLAGS_SO = -fPIC --shared
TARGETS  = libminiomp.so
all: $(TARGETS) 

libminiomp.so: libminiomp.h libminiomp.c env.c intrinsic.c parallel.c synchronization.c single.c loop.c task.c taskloop.c map.c list.c
ifdef dbg
	$(CC) $(CFLAGS_SO) $(CFLAGS) -g -D _DEBUG=1 $+ -o $(MINIOMP)/lib/$@ -lpthread
else
	$(CC) $(CFLAGS_SO) $(CFLAGS)  $+ -o $(MINIOMP)/lib/$@ -lpthread

endif

clean:
	rm -rf $(MINIOMP)/lib/$(TARGETS)
