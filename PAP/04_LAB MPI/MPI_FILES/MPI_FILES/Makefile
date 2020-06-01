CC       = gcc
MPICC    = mpicc.mpich

CFLAGS   = -Wall -std=c99 -O3 -fno-inline -march=native
CINCL    = -I.
CLIBS    = -L. -lm

TARGETS	= heat heat-mpi heat-hybrid
all: $(TARGETS)

misc.o: misc.c
	$(CC) $(CFLAGS) $(CINCL) -c $+ -o $@

heat: heat.c solver.c misc.o
	$(CC) $(CFLAGS) $(CINCL) $+ $(CLIBS) -o $@

heat-mpi: heat-mpi.c solver-mpi.c misc.o
	$(MPICC) $(CFLAGS) $(CINCL) $+ $(CLIBS) -o $@

heat-hybrid: heat-hybrid.c solver-hybrid.c misc.o
	$(MPICC) $(CFLAGS) -fopenmp $(CINCL) $+ $(CLIBS) -o $@

clean:
	rm -rf misc.o $(TARGETS) *.o* *.e* *.po* *.pe* *.pcf *.prv *.row TRACE* set-0
