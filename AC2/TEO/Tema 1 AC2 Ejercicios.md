[TOC]

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

![img](rsc\img1)
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

Un procesador interpreta instrucciones de 3 tipos: enteras (ENT), accesos a memoria (MEM) y saltos (BR). La frecuencia de reloj del procesador es de 800 MHz.

El primer nivel de la jerarquía de memoria está integrado en el mismo chip del procesador y consta de una cache de instrucciones y una cache de datos (CD). Para reducir la latencia media de accesos a memoria, el procesador dispone de una cache (segundo nivel) externa. En este ejercicio consideraremos que la cache de instrucciones y la cache de segundo nivel son ideales (no hay fallos) y que las instrucciones MEM son bloqueantes.

La penalización por fallo en la cache de datos es de 12 ciclos. El procesador ejecuta un programa P. La siguiente tabla muestra la distribución de instrucciones y el CPI:

* ENT -> 40% CPI = 1
* MEM hit en CD -> 20% CPI = 2
* MEM miss en CD -> 20% CPI = 14
* BR -> 20% CPI = 2

<u>Pregunta 1</u>: Calcule el IPC medio, CPI, la cantidad de MIPS, fallos en CD por instrucción, fallos en CD por acceso a memoria al ejecutar el programa P.

$CPI = 0.4 * 1 + 0.2 * 2 + 0.2*14 + 0.2*2 = 4$

$IPC = CPI^{-1} = 0.25$

$MIPS = \frac{N}{ \Delta T} = \frac{N}{N*CPI*T_c}=IPC*\nu = 0.25*800MHz = 200 MIPS$

$F_{i}=0.2$

$F_a=\frac{fallos}{Acesos} = \frac{0.2}{1+0.4} = 0.14$

Mejoras tecnológicas permiten integrar la cache de segundo nivel en el chip (reduciendo la latencia de acceso) y aumentar la frecuencia de reloj a 1 GHz. En el nuevo diseño se mantiene la microarquitectura original. La potencia consumida por el chip es de 50 w (vatios). La batería que alimenta el chip tiene una capacidad energética de 25 wh (vatios x hora). Al ejecutar el programa P en el nuevo diseño se obtiene un CPI medio igual a 3.

<u>Pregunta 2:</u> Calcule el número máximo de instrucciones de P para que el procesador pueda ejecutar completamente el programa sin recargar la batería. 

$E = P * \Delta T = J*S; \space P (J/s) = \frac{E}{\Delta T } = \frac{1J}{1s} $

$E_b = 25 W*Hora * 3600 s = 90*10^3 J$

$E_c = P*T= 50W*(1GHz)^{-1} = 50 nJ$

> Calculamos la energia de un ciclo, usando el tiempo de ciclo

$Ciclos =\frac{E_b}{E_c} = 1,8*10^9 ciclos\rightarrow Instr = \frac{ciclos}{CPI} = 6*10^{11} instruciones$

> Dividimos la energia de la bateria entre la de un ciclo, obteniendo los ciclos y entonces con el CPI podremos sabes el numero de instrucciones.

<u>Pregunta 3:</u> Calcule el CPI de las instrucciones MEM que fallan en CD y deduzca la penalización (en ciclos) por fallo.

$CPI = 3 = \sum CPI_i*F_i =1.2+0.2*x \rightarrow x=9$ ciclos

Como se tardan 2 ciclos en caso de acierto, **la penalización es de 7 ciclos**.

### Ejercicio 1.17

En las siguientes figuras se muestra el IPC y la potencia consumida a medida que se interpretan instrucciones de un programa, en un procesador que funciona a una frecuencia de 2 Ghz.

![img](rsc\img1)

<u>Pregunta 1:</u> Calcule el tiempo de ejecución del programa.

$T_{exe} = (\sum \frac{1}{IPC_i}*N_i)*T_c = (\frac{1}{0.8}*1*10^9 + \frac{1}{1.2}*1*10^9 + \frac{1}{1.6}*1*10^9)*(2GHz)^{-1} = 4.06 s$

<u>Pregunta 2:</u> Calcule la potencia de conmutación media. Recuerde que la potencia es la energía por unidad de tiempo.

$P= \frac{E}{T}= \frac{\sum P_i*T_i}{T_{exe}}$ 

$P_1*T_1 = 60W * ((0.8^{-1}*10^9)*2GHz^{-1}) =0.625 * 60W = 37.5 J*s = E_1$

$P_2*T_2 = 80W*((1.6^{-1})*10^9*2GHz^{-1}) = 5/16*80W = 25J*s = E_2$

$P_3*T_3 = 70W*((1.2^{-1}*10^9)*2GHz^{-1})= 0.42*70W = 29.17J*s = E_3 $

$P = 22.5 W$

> Para calcular la potencia, necesitaremos la energia por tramos, usando el Ti que se calcula siguiendo la formula de la pregunta 1.

<u>Pregunta 3:</u> Calcule el tiempo de ejecución cuando se utiliza
escalado tensión-frecuencia para mantener la potencia consumida
dentro del límite de 80 W en cada región.

<u>Pregunta 4:</u> Calcule la potencia de conmutación media en el
escenario descrito.

### Ejercicio 1.18

Un procesador convencional tiene un primer nivel de cache de datos de 32 Kbytes 2-asociativa, siendo el tamaño de bloque de 16 bytes. La cache de datos es bloqueante y la latencia de acceso a memoria son 4 ciclos. Por otro lado, supondremos que la cache de instrucciones es ideal; es decir, no se producen fallos de cache.

En este procesador se efectúa el cálculo especificado en el siguiente código:

### Ejercicio 1.19



### Ejercicio 1.3

Deduzca 1) la cantidad de MIPS, 2) el CPI medio y 3) el tiempo total para cada una de las tres preguntas siguientes.

<u>Pregunta 1:</u> Procesador con reloj de 900 MHz que ejecuta 1000 iteraciones de un bucle de 12 instrucciones y tarda 18 ciclos en cada iteración. 

$MIPS = \frac{Instruciones}{Tiempo} * 10^{-6} = \frac{1000*12}{18 ciclos*(900MHz)^{-1}}*10^{-6} = $

$CPI_m = \frac{Ciclos}{Instr} = \frac{18 \space ciclos}{12 \space instructiones} = 1.5$

$T= N*CPI*Tc = (1000*12) * 1.5 * (900MHz)^{-1} =$

<u>Pregunta 2:</u> Procesador con reloj de 450 MHz que ejecuta 2000 iteraciones de un bucle de 12 instrucciones y tarda 18 ciclos en cada iteración.



<u>Pregunta 3:</u> Procesador con reloj de 900 MHz que ejecuta 2000 iteraciones de un bucle de 12 instrucciones y tarda 36 ciclos en cada iteración.

Sabemos que un procesador emplea la mitad de su tiempo en hacer accesos a cache. Queremos reducir el tiempo total del procesador en un 20% del original.

<u>Pregunta 4:</u> Deduzca cuanto más rápida debería ser la nueva cache para conseguirlo, expresando la respuesta como el valor del cociente: tiempo cache vieja / tiempo cache nueva