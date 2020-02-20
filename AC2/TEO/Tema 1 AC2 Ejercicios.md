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
T_{mem} = N*m*t_{penlaty} = 10^4 * 0.25 * 60ns = 1,5*10^{-4} s
$$

> El tiempo de memoria será, el numero de accesos a memoria (1 en cada iteración), por la tasa de fallos por acceso por la penalización de un fallo.

Mejoras tecnológicas permiten implementar el procesador y las caches con un tiempo de ciclo de reloj de 1.5 ns. Ahora bien, la organización del procesador y del subsistema de memoria es idéntica a la del computador C1.

<u>Pregunta 3</u>: Calcule el tiempo de ejecución $T'_{ex}$ del programa en el nuevo computador y la ganancia.
$$
T'_{ex}=T'_{CPU}+T_{MEM}\\
T'_{CPU} = N * CPI_{CPU} * T_c *\frac{T'_c}{T_c}= T_{CPU}* T'_c\\
T'_{ex}=T_{CPU}*\frac{T'_c}{T_c}+T_{MEM}= (150 \mu s)*\frac{1.5ns}{2ns}+ 150 \space \mu s=112.5\mu s + 150 \mu s = 262.5 \mu s\\
G = \frac{T_{ori}}{T_{new}} = \frac{300\mu s}{262.5 \mu s} = 1.14
$$
> El tiempo de memoria no se ve alterado, solamente afecta al tiempo de CPU; por tanto, debemos calcular el nuevo tiempo de CPU, donde el nuevo tiempo de ciclo se debe aplicar.

<u>Ganancia Usando ley de Amdhal:</u>

![img](img1)
$$
F_m := \text{Fracción de tiempo original donde se usa la mejora} =\frac{T_2}{T_0}=\frac{150\mu s}{300 \mu s} = 0.5\\
G_m := \text{Ganancia de la mejora.} = \frac{T_2}{T_3} = \frac{150 \mu s}{150\mu s }*\frac{1.5ns}{2ns}=1+1/3\\
G_{amdahl} = \frac{1}{(1-F_m)+\frac{F_m}{G_m}} = \frac{1}{0.5+0.38} = 1.14
$$

> En este caso, T2 es el Tcpu y T1 es Tmem. Comprovamos que las G concuerdan.

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

Un procesador interpreta instrucciones de 3 tipos: enteras (ENT), accesos a memoria (MEM) y saltos (BR). La frecuencia de reloj del procesador es de 800 MHz. El primer nivel de la jerarquía de memoria está integrado en el mismo chip del procesador y consta de una cache de instrucciones y una cache de datos (CD). Para reducir la latencia media de accesos a memoria, el procesador dispone de una cache (segundo nivel) externa. 

En este ejercicio consideraremos que la cache de instrucciones y la cache de segundo nivel son ideales (no hay fallos) y que las instrucciones MEM son bloqueantes. La penalización por fallo en la cache de datos es de 12 ciclos. 

El procesador ejecuta un programa P. La siguiente tabla muestra la distribución de instrucciones y el CPI:

* ENT -> 40% CPI = 1
* MEM hit en CD -> 20% CPI = 2
* MEM miss en CD -> 20% CPI = 14
* BR -> 20% CPI = 2

<u>Pregunta 1</u>: Calcule el IPC medio, CPI, la cantidad de MIPS, fallos en CD por instrucción, fallos en CD por acceso a memoria al ejecutar el programa P.

$CPI = 0.4 * 1 + 0.2 * 2 + 0.2*14 + 0.2*2 = 4$

$IPC = CPI^{-1} = 0.25$

$MIPS = \frac{N}{ \Delta T} = \frac{N}{N*CPI*T_c}=IPC*\nu = 0.25*800MHz = 200 MIPS$

$F_{i}=?$

$F_a=?$

### Ejercicio 1.17

### Ejercicio 1.18

### Ejercicio 1.19

