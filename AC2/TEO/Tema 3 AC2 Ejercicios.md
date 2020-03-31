[TOC]

### Ejercicio 3.1

En la parte izquierda de la siguiente figura se muestra el código de la operación suma de dos vectores elemento a elemento en un lenguaje de alto nivel. En la parte derecha se muestra una traducción a lenguaje máquina.

El tamaño de un dato son 8 bytes. El registro r9 se ha inicializado con el número de iteraciones y los registros r2, r4 y r6 se han inicializado con la dirección base de los vectores C, B y A respectivamente.

<u>Pregunta 1:</u> En un procesador que interpreta las instrucciones de forma serie, calcule los ciclos de ejecución de una iteración del bucle. Para ello suponga que la latencia de todas las instrucciones son 6 ciclos.

$Ciclos = Instruciones * Latencia = 9 * 6 = 54 \space Ciclos$

<u>Pregunta 2:</u> En el procesador segmentado con control de riesgos descrito en este capítulo, calcule los ciclos de ejecución por iteración. Así mismo, indique los ciclos perdidos por tipo de riesgo y calcule el CPI.

> Debemos ver el grafo de dependencias para contar los ciclos perdidos y el cronograma:
>
> <img src="rsc\eje37.jpeg" style="zoom: 33%;"/>
>
> <img src="rsc\eje38.jpeg" style="zoom:67%;" />
>
> Vemos que la instrucción c depenede de a y b (perderá 2 ciclos de RD), la instrucción h depende de la instruccion i (perderá 2 ciclos de RD). Además, la instruccion i representa un RS, donde se perderan 4 ciclos(considero que no forma parte de este ciclo).
>
> Entonces, los ciclos de una iteración son 18, Se pierden 4 ciclos en Riesgos de Datos. El $CPI =\frac{Instruciones+CiclosPerdidos}{Instruciones} = \frac{9+4}{9} = 1.44$

<u>Pregunta 3:</u> Suponga que las frecuencias de funcionamiento del procesador serie y segmentado son iguales. Calcule la ganancia de una interpretación segmentada respecto de una interpretación serie al ejecutar una iteración del bucle.

> $G= \frac{T_{ori}}{T_{new}}=\frac{N*CPI*T_c}{N*CPI^{seg}*T_c} = \frac{CPI}{CPI_{seg}}=\frac{6}{1.44} = 4.17$

Una nueva versión del procesador segmentado tiene una frecuencia de funcionamiento 1.5X mayor. En estas condiciones, es necesario todo el ciclo de reloj para escribir o leer un registro del banco de registros.

<u>Pregunta 4:</u> En esta versión del procesador, calcule los ciclos de ejecución por iteración. Así mismo, indique los ciclos perdidos por tipo de riesgo y calcule el CPI.

> En este caso, los ciclos por riesgo de datos perdidos seran 3 por cada RD, dado lugar a 6 ciclos perdidos por RD en cada iteración.  El total de ciclos sera de 20
>
> El $CPI=\frac{9+6}{9}=1.67$

<u>Pregunta 5:</u> Calcule la ganancia de la nueva versión del procesador segmentado respecto de la versión previa.

> $G= \frac{T_{ori}}{T_{new}}=\frac{N*CPI*T_c}{N*CPI*1.5*T_c} = \frac{CPI}{CPI*1.5}=\frac{1.44}{1.67*1.5} = 0.57$ 
>
> En este caso, se pierde tiempo con esta nueva versión. (1-0.57)*100 = 43% de perdida

### Ejercicio 3.7

Un procesador, que interpreta las siguientes instrucciones(INT, Load, Store, BR) esta segmentado en 6 etapas (CP, B, DL, ALU, M, ES).

El banco de registros permite la escritura y la lectura, en este orden, de un mismo registro en un ciclo de reloj. El camino de datos dispone de recursos suficientes para que no se produzcan riesgos estructurales.

![image-3.7](rsc\eje377)

<u>Pregunta 1:</u> Indique las entradas de los multiplexores del camino de datos que hay que seleccionar para cada tipo de instrucción en los ciclos 4, 5 y 6 del proceso de interpretación. Por ejemplo, para una instrucción Store, donde la marca x denota indistinto:

| Ciclo               | 4      | 4      | 4      | 5      | 6      | 6      |
| ------------------- | ------ | ------ | ------ | ------ | ------ | ------ |
| **Instruccion/MUX** | **m3** | **m4** | **m5** | **m6** | **m1** | **m2** |
| Store               | 5      | 6      | 9      | X      | 0      | 2      |
| Load                | 5      | 6      | 9      | 11     | 0      | 2      |
| Int                 | 5      | 7      | 9      | 10     | 0      | 2      |
| BR                  | 4      | 6      | EV     | 10     | 1      | EV     |

Supongamos que el retardo de propagación (en ps) de los componentes mostrados en el camino de datos es: Sumador(150), ALU(200), EV(100), MD(350), mx(100), ri(50).

<u>Pregunta 2:</u> Calcule el tiempo de etapa máximo y mínimo de CP, ALU y M. Considerando sólo las etapas CP, ALU y M, calcule el tiempo de ciclo de reloj.

> $MAX_{CP} = MIN_{CP} = 2*(T_{MUX})+T_S + ri = 400ps$
>
> $MAX_{ALU}= 2*(T_{MUX})+T_{ALU} + T_{EV} + ri= 550ps$
>
> $MIN_{ALU} = 2*(T_{MUX})+T_{ALU} + ri = 450ps$
>
> $MAX_M= MIN_M = T_{MD} + t_{MUX}+ ri= 500ps$
>
> El tiempo de ciclo deberá ser el máximo de los tiempos calculados: 550ps.

En la etapa DL se detectan los riesgos de datos y de secuenciamiento. Cuando se detecta un riesgo de datos, la lógica de control bloquea la interpretación de las instrucciones que estan en las etapas DL, B i CP mientras perdura el riesgo. 

En caso de riesgo de secuenciamiento, la lógica de control descarta las instrucciones buscadas hasta que se actualiza el Contador de Programa con la dirección de la siguiente instrucción. 

El procesador ejecuta un programa que localiza el elemento máximo de una lista.

````asm
1$: load r2, 8(r0) 	;r2 ← mem[r0+8]
cmpgt r3, r2, r1 	;r3 ← (r2 > r1)
beq r3, 2$ 			;si (r3=0) salta a 2$
add r1, r2, r10 	;r1 ← r2
add r5, r0, r10 	;r5 ← r0
2$: load r0, 0(r0) 	;r0 ← mem[r0+0]
bne r0, 1$ 			;si (r0≠0) salta a 1$

;Valores iniciales:
;r0 = dirección del primer elemento de la lista
;r1 = 0; r10 = 0
````



<u>Pregunta 3:</u> Muestre el cronograma de ejecución de las instrucciones de una iteración entera del bucle y de la primera instrucción de la siguiente iteración, en el caso en que p->dat > max. Identifique los ciclos perdidos en el cronograma e indique cuál es el motivo.

> Hay dos riesgos de secuenciamiento (C y G) que hacen perder 8 ciclos.
>
> Hay 3 riesgos de datos(B, C y G)  que hacen perder 6 ciclos

![](rsc\eje39.jpeg)

<u>Pregunta 4:</u> Calcule el CPI medio suponiendo que la condición p->dat > max se cumple en el 10% de las iteraciones.

> $CPI=0.1*CPI_{salto}+0.9*CPI_{NoSalto} = 0.1*\frac{8+14}{8}+0.9*\frac{6+12}{6} = 2.97$

### Ejercicio 3.10

En la siguiente figura se muestra la segmentación en etapas del proceso de interpretación de las instrucciones en un procesador.

![](rsc\eje310.jpg)

El conjunto de instrucciones del procesador puede interpretarse sin que se produzcan riesgos estructurales. En el mismo ciclo se puede escribir y leer, en este orden, un registro del banco de registros. Las instrucciones de secuenciamiento actualizan el registro CP en la etapa ES.

<u>Pregunta 1:</u> Dibuje un diagrama temporal que muestre la interpretación de una iteración del bucle. En el diagrama temporal debe mostrarse la inyección de instrucciones nop cuando se gestiona un riesgo. Indique los ciclos perdidos por cada tipo de riesgo y calcule el CPI de una iteración.

![image-20200331195416287](rsc\cronograma3101)

> Se pierden 3 ciclos por riesgo de datos y 4 por riesgo de secuenciamiento.
>
> El $CPI = \frac{4+3+4}{4} = 2.75$

El computador donde se ejecuta el programa funciona a una frecuencia de 500 Mhz y consume una potencia de 30 W (vatios). La batería que alimenta al procesador suministra 1 A . H (amperios por hora) a 5 voltios.

<u>Pregunta 2:</u> Calcule la energía de la batería. 

> $E = P * \Delta T, P = V*I$
>
> $E_B = 1 A*H *\frac{3600s}{1 hora}* 5 V= 18.000J$

<u>Pregunta 3:</u> Calcule la energía consumida por el procesador en un ciclo.

> $E_{procesador}^{ciclo} = Potencia * T_c = 30W(\frac{J}{S})*(500MHz)^{-1} = 6*10^{-8}J$

<u>Pregunta 4:</u> ¿Cuántas iteraciones del bucle se pueden ejecutar antes de que la carga de la batería se reduzca a la mitad?. Exprese el resultado en millones de iteraciones.

> $Iteraciones = \frac{0.5*E_B}{E_{P}^{C}*CPI} = \frac{9.000}{6*10^{-8}*2.75} = \space Millones \space It.$

### Ejercicio 3.3(80)

En un procesador segmentado con 7 etapas (CP, BUS, D/L, ALU, ET, DT, ES), el proceso de interpretación de instrucciones se ha segmentado de la forma que se muestra en la siguiente figura.

![img3.3t1](rsc\3.380.jpg)

La única diferencia con el procesador segmentado lineal descrito en el capítulo 3 es la segmentación del acceso a memoria de datos. Los posibles riesgos de datos debidos a registros y riesgos de secuenciamiento se gestionan de la misma forma que en el capítulo 3, dando lugar a que el inicio de la fase de ejecución de las instrucciones sea en orden de programa. 

El procesador dispone en el primer nivel de la jerarquía de memoria de una cache para instrucciones y una cache para datos. Nosotros supondremos que un acceso a cualquiera de las dos cache de primer nivel siempre es un acierto. Tanto el acceso al campo etiqueta como al campo dato de un contenedor de cache requiere un ciclo. En una instrucción load los campos etiqueta y dato de un contenedor se leen en paralelo (ciclo 5) y en el siguiente ciclo el dato leído se escribe en el banco de registros (ciclo 6). 

En el caso de una instrucción store es necesario en primer lugar acceder al campo etiqueta para comprobar si el dato está almacenado en cache antes de actualizar el campo dato. Como es necesario un ciclo para acceder a cada campo de información de un contenedor de cache y hay que efectuarlo secuencialmente son necesarios dos ciclos (ciclos 5 y 6). Supondremos que no existen riesgos estructurales cuando se interpretan de forma solapada varias instrucciones. En particular supondremos que la cache de datos dispone de un puerto de lectura y un puerto de escritura. Estos puertos de acceso son independientes y una acción de lectura o escritura en cualquiera de los campos del contenedor requiere todo el ciclo de la señal de reloj.

<u>Pregunta 1:</u> Analice los posibles riesgos de datos al acceder a la memoria de datos. 

> Los tres tipos de riesgos de datos en memoria de datos pueden ser de tres tipos, vamos a analizarlos:
>
> (refactor for:
>
> ​	• una instrucción store siempre escribe antes de que lea una instrucción load más joven. 
>
> ​	• una instrucción load siempre lee antes de que escriba una instrucción store más joven. 
>
> ​	• una instrucción store siempre escribe antes de que escriba una instrucción store más joven.)
>
> * Dependencia Vertadera (**R1**= R2+R3, R5 = **R1**+R5)
>
>   Como en la anterior segmentación, es posible que el banco de registros no tenga el valor correcto en el banco de registros para alimentar a la instrucción joven que lo precisa.
>
> * Antidependencia (R1=**R2**+R3, **R2**=R3+R5)
>
>   Para comprobar que no podemos tener RD aqui, debemos demostrar que  una instrucción siempre lee antes de que escriba una instrucción posterior en orden de programa. Si tenemos un store y seguidamente un load, se lee de memoria antes de que se haya actualizado la posicion de memoria (load lee en el ciclo 5 y store la actualiza en su 6 ciclo). Deberemos cuidar este tipo de riesgo. Con las instrucciones aritmeticas no hay problema en este caso.
>
>   Ej: Store #8, 0(r2), Load r5, 0(r2).
>
> * Dependencia de Salida(R1=2+R4, R1=LOAD(R5))
>
>   Debemos comprobar que una instrucción siempre escribe antes que escriba una instrucción posterior en orden de programa. Con la tabla de reserva vemos que todas las escrituras son el mismo ciclo(ciclo 6), no existirá este tipo de riesgo.

<u>Pregunta 2:</u> Indique las acciones que deben efectuarse y el ciclo en el cual pueden efectuarse, para detectar el riesgo de datos al acceder a memoria.

> Como la dirección de memoria se calcula en la etapa ALU, debemos efectuar las acciones en esta etapa. Las acciones deberan emular un funcionamiento serie.

En el procesador segmentado que se utiliza, la última etapa del proceso de interpretación de una instrucción donde se puede retener una instrucción es la etapa D/L.

<u>Pregunta 3:</u> Describa un mecanismo para controlar los posibles riesgos de datos al acceder a memoria. Posteriormente muestre en un diagrama temporal, utilizando la siguiente secuencia de instrucciones, el mecanismo de control de riesgo descrito. Justifique de forma detallada las retenciones o bloqueos en la etapa D/L.

> La gestion conservadora contra la ejecucion a distancia 1 de un store y un load

<u>Pregunta 4:</u> Diseñe un circuito combinacional que, con las señales descritas, controle los multiplexores MUXCPBloq, MUXBUSBloq y MUXDLNop de la figura previa, en el caso de que se detecte un riesgo de datos, ya sea debido a registros o a memoria.

### Ejercicio 3.5

### Ejercicio 3.16

### Ejercicio 3.14

### Ejercicio 3.21

### Ejercicio 3.15 

### Ejercicio 3.22

