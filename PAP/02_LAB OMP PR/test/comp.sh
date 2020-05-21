#! /bin/bash

USAGE="\n comp.sh nameFile threads \n
	comprueba la salida del ejecutable con las dos librerias"

if(test $# -lt 2 || test $# -gt 2)
then
	echo -e $USAGE
	exit 0
fi

make $1-omp
make $1-gomp
echo "compilation done"
./run-omp.sh $1-omp $2
echo "==============="
./run-omp.sh $1-gomp $2
