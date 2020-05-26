#!/bin/bash
# following option makes sure the job will run in the current directory
#$ -cwd
# following option makes sure the job has the same environmnent variables as the submission shell
#$ -V
# following option to change shell
#$ -S /bin/bash

USAGE="\n USAGE: ./submit-mpi.sh nodes processses \n
        nodes         -> Number of nodes\n
        processes     -> Total number of processes\n"

if (test $# -lt 2 || test $# -gt 2)
then
        echo -e $USAGE
        exit 0
fi

export procs_per_node=`echo "${2} / ${1}" | bc`

#cat ${TMPDIR}/machines

echo "Heat execution with ${1} nodes and ${2} total processes (${procs_per_node} processes per node)"

mpirun.mpich -np ${2} -ppn ${procs_per_node} -machinefile ${TMPDIR}/machines ./heat-mpi test.dat
