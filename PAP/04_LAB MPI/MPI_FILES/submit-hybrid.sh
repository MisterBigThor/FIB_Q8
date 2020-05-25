#!/bin/bash
# following option makes sure the job will run in the current directory
#$ -cwd
# following option makes sure the job has the same environmnent variables as the submission shell
#$ -V
# following option to change shell
#$ -S /bin/bash

USAGE="\n USAGE: ./submit-hybrid.sh processses threads\n
        processes     -> Number of processes\n
        threads       -> Number of threads per process\n"

if (test $# -lt 2 || test $# -gt 2)
then
        echo -e $USAGE
        exit 0
fi

export OMP_NUM_THREADS=$2

#cat $TMPDIR/machines

echo "Heat execution with $1 processes and $2 threads per process"

mpirun.mpich -np $1 -ppn 1 -machinefile $TMPDIR/machines ./heat-hybrid test.dat
