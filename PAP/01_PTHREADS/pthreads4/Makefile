.SUFFIXES: -pth -asm
CC       = gcc

LIBNUMA  = /scratch/nas/1/pap0/Soft/numactl

CFLAGS   = -Wall -Wextra -pedantic -O -std=c99 -march=native -I. -I$(LIBNUMA)/include -D_GNU_SOURCE
LFLAGS	 = -L. -L$(LIBNUMA)/lib -lpthread -lm -lnuma

.c-asm:
	$(CC) $(CFLAGS) -S -fopenmp $< -o $@ $(LFLAGS) 

.c-pth:
	$(CC) $(CFLAGS) -fopenmp $< -o $@ $(LFLAGS) 

clean:
	rm -f *-pth *-asm
