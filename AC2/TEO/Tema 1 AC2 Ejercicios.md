### Ejercicio 1.1

El computador C1 con: Procesador de 500 MHz de frecuencia de reloj. Cache de datos de 32 KB, mapeo directo, bloque de 32B, 60 ns de penalización en caso de fallo. Cache de instrucciones ideal. 

Ejecuta el programa:

````c
int i;
float s;
float X[10000];
for(i = 0; i<10000; i++) 
    s = s+X[i];
````

que el compilador traduce en 5 instrucciones de lenguaje máquina. El programa tarda 300 microsegundos en ejecutarse.

<u>Pregunta 1</u>: Calcule: MFLOPS (millones de operaciones en coma flotante por segundo), MIPS, CPI.
$$
MFLOPS = \frac{N_{ops}FLOAT}{\Delta T}*10^{-6} = \frac{1*10^4}{300*10^{-6}} *10^{-6}= 33.3\space MFLOPS\\
MIPS = \frac{N_{ops}}{\Delta T}*10^{-6}=\frac{5*10^{-4}}{300*10^{-6}} = 166.6 MIPS \\
CPI = \frac{ciclos}{N} = \frac{\frac{T_{exec}}{Tc}}{N} = 3\\
T_{exec} = N*CPI*T_c \rightarrow CPI = \frac{T_{exec}}{N*T_c}
$$
<u>Pregunta 2</u>: Calcule la fracción (m) de accesos a datos que son fallo de cache y $T_{mem}$.
$$
m = \frac{fallos}{acesos} = \frac{2,5*10^3}{10^4} = 0.25 \\
T_{mem} = N*m*t_{penlaty} = 10^4 * 0.25 * 60ns = 1,5*10^{-4}
$$

> El tiempo de memoria será, el numero de accesos a memoria (1 en cada iteración), por la tasa de fallos por acceso por la penalización de un fallo.

Mejoras tecnológicas permiten implementar el procesador y las caches con un tiempo de ciclo de reloj de 1.5 ns. Ahora bien, la organización del procesador y del subsistema de memoria es idéntica a la del computador C1.

<u>Pregunta 3</u>: Calcule el tiempo de ejecución T'ex del programa en el nuevo computador y la ganancia.
$$
T'_{ex}=T'_{CPU}+T_{MEM}\\
T'_{CPU} = N * CPI_{CPU} * T'_c\\
T'_{ex}=T_{CPU}*\frac{T'_c}{T_c}+T_{MEM}\\
$$
> El tiempo de memoria no se ve alterado, solamente afecta al tiempo de CPU; por tanto, debemos calcular el nuevo tiempo de CPU, donde el nuevo tiempo de ciclo se debe aplicar.

**//todo: acabar calculos + leyde amdhala**

### Ejercicio 1.2

En un procesador las instrucciones Load y Store representan un 26% de las instrucciones siendo 2.3 el CPI. Todas las demás instrucciones tienen 1.5 de CPI.

<u>Pregunta 1</u>: Calcule el CPI del procesador original.

$CPI^0 = \sum\frac{N_i*CPI_i}{N}= \sum Ci*CPI_i= 0.26*2.3 + 0.74*1.5=1.71 $

En la próxima generación del procesador, debido a un cambio en el proceso tecnológico, se puede disponer de más transistores y se plantean dos opciones en la forma de utilizar estos transistores adicionales. 

1. Incrementar el tamaño de la cache de primer nivel, lo cual reduce en un 20% el CPI de las instrucciones Load y Store, porque no se incrementa la latencia y la tasa de fallos es menor. 
2.  Utilizar los transistores en mejorar todos los componentes del procesador en el chip, lo cual permite reducir el periodo del reloj en un 10%.

<u>Pregunta 2:</u> Calcule el CPI de la 1ª opción de diseño. 

$CPI^1=0.26*2.3*0.8+0.74*1.5 = 1.58$

<u>Pregunta 3:</u> Calcule el tiempo de ejecución en la 2ª opción de diseño. 

$T^2_{exec} = T_{exec}*0.9$

<u>Pregunta 4:</u> ¿Cuál de las dos opciones permite obtener un procesador con mayor rendimiento? 

$ \frac{T_1}{T_2} = \frac{N*CPI_1*T_c}{N*CPI_0*T_c*0.9} = \frac{CPI_1}{CPI_0*0.9}=\frac{1.58}{1.71*0.9} = >1$

<u>Pregunta 5:</u> ¿Cuál es la ganancia, respecto del procesador original, de la mejor opción?

$G = (\frac{T_{ori}}{T_{new}}-1)*100 = \frac{N*CPI_0*T_c}{N*CPI_0*T_c*0.9} = \frac{1}{0.9} = 1.11$

La ganancia es del 11%.

### Ejercicio 1.8

### Ejercicio 1.17

### Ejercicio 1.18

### Ejercicio 1.19

