## Laboratori 1: OpenMP Paral·lelització del garbell d'Eratòstenes

En aquest laboratori volem paralelitzar el garbell d'Eratostenes, un algoritme que permet determinar els nombres primers fins a un determinat nombre 'N'.

L'objectiu d'aquest laboratior es millorar el seu temps d'execucció, utilitzant diverses eines de la llibreria d'openMP.

## Versió 1 del Garbell

Aquesta primera versió del garbell es tracta d'una implementació sencilla. Primerament un bucle inicialitza un *array* de chars de 'N' posicions, on seguidament apliquem l'algoritme i es van descartant els nombres que no son primers. Per últim, un tercer bucle va acumulant a una variable el nombre total de nombres primers.

L'execucció sense paral·lelisme (amb N = $10^8$ ) triga 5,30 segons. Seguidament probarem diferents estrategies de paral·lelisme per intentar baixar aquest valor:

#### 

La primera estrategia utilitza el constructor d'openMP 'FOR' dins una regió paral·lela. Apliquem aquest constructor en els 3 bucles. Em de tenir en compte que en el cas de la variable on acumulem el resultat hi em d'aplicar la clausula reduction per evitar la condició de carrera.

L'execucció triga 1.16 segons (amb N = $10^8$ i 6 threads). Podem provar de buscar un temps menor amb les diferents clausules de *scheduling* que proporciona openMP i veiem els seus temps:

* static scheduling: 1.17 segons

//Comentar version parallel for

//Comentar version taskloop, solucion para la falta del reduction

## Versió 2 del Garbell

La segona versió l'algoritme divideix els N possibles nombres primers en trossos que apliquen en paral·lel sobre l'*array*  el garbell. Primerament, explorem diversos tamanys de bloc per veure quin valor es mes adient:



En aquest cas, aplicarem els constructors for i task amb el tamany de bloc mes adient, calculat anteriorment.

//Comentar version parallel for

//Comentar version tasks



