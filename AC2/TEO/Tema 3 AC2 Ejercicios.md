[TOC]

### Ejercicio 3.1

En la parte izquierda de la siguiente figura se muestra el código de la operación suma de dos vectores elemento a elemento en un lenguaje de alto nivel. En la parte derecha se muestra una traducción a lenguaje máquina.

El tamaño de un dato son 8 bytes. El registro r9 se ha inicializado con el número de iteraciones y los registros r2, r4 y r6 se han inicializado con la dirección base de los vectores C, B y A respectivamente.

<u>Pregunta 1:</u> En un procesador que interpreta las instrucciones de forma serie, calcule los ciclos de ejecución de una iteración del bucle. Para ello suponga que la latencia de todas las instrucciones son 6 ciclos.

$Ciclos = Instruciones * Latencia = 9 * 6 = 54 \space Ciclos$

<u>Pregunta 2:</u> En el procesador segmentado con control de riesgos descrito en este capítulo, calcule los ciclos de ejecución por iteración. Así mismo, indique los ciclos perdidos por tipo de riesgo y calcule el CPI.

> Debemos ver el grafo de dependencias para contar los ciclos perdidos y el cronograma:
>
> 
>
> Vemos que la instrucción c depenede de a y b (perderá 2 ciclos de RD), la instrucción h depende de la instruccion i (perderá 2 ciclos de RD). Además, la instruccion i representa un RS, donde se perderan 4 ciclos(considero que no forma parte de este ciclo).
>
> Entonces, los ciclos de una iteración son 18, Se pierden 4 ciclos en Riesgos de Datos. El CPI resultante es $CPI =\frac{Ciclos}{Instruciones} = \frac{14+4}{9} = 2$

<u>Pregunta 3:</u> Suponga que las frecuencias de funcionamiento del procesador serie y segmentado son iguales. Calcule la ganancia de una interpretación segmentada respecto de una interpretación serie al ejecutar una iteración del bucle.

> $G= \frac{T_{ori}}{T_{new}}=\frac{N*CPI*T_c}{N*CPI^{seg}*T_c} = \frac{CPI}{CPI_{seg}}=\frac{6}{2} = 3$

Una nueva versión del procesador segmentado tiene una frecuencia de funcionamiento 1.5X mayor. En estas condiciones, es necesario todo el ciclo de reloj para escribir o leer un registro del banco de registros.

<u>Pregunta 4:</u> En esta versión del procesador, calcule los ciclos de ejecución por iteración. Así mismo, indique los ciclos perdidos por tipo de riesgo y calcule el CPI.

> En este caso, los ciclos por riesgo de datos perdidos seran 3 por cada RD, dado lugar a 6 ciclos perdidos por RD en cada iteración. El $CPI = \frac{14+6}{9} = 2.22$
>
> En este caso, la ganancia es de 2.22 veces

<u>Pregunta 5:</u> Calcule la ganancia de la nueva versión del procesador segmentado respecto de la versión previa.

> $G= \frac{T_{ori}}{T_{new}}=\frac{N*CPI*T_c}{N*CPI*1.5*T_c} = \frac{CPI}{CPI*1.5}=\frac{2}{2.22*1.5} = 2/3.33 = 0.6$ 
>
> En este caso, se pierde tiempo con esta nueva versión. (1-0.6)*100 = 40% de perdida

### Ejercicio 3.7 (85)



### Ejercicio 3.10

### Ejercicio 3.3

### Ejercicio 3.5

### Ejercicio 3.16

### Ejercicio 3.14

### Ejercicio 3.21

### Ejercicio 3.15 

### Ejercicio 3.22

