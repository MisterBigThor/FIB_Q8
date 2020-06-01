qsub -pe mpich 1 -l execution2 submit-mpi.sh 1 4 & watch qstat
