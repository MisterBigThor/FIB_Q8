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
> <img src="D:\FIB_Q8\AC2\TEO\rsc\eje38.jpeg" style="zoom:67%;" />
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

### Ejercicio 3.7

<u>Pregunta 1:</u> Indique las entradas de los multiplexores del camino de datos que hay que seleccionar para cada tipo de instrucción en los ciclos 4, 5 y 6 del proceso de interpretación. Por ejemplo, para una instrucción Store, donde la marca x denota indistinto:

| Ciclo               | 4      | 4      | 4      | 5      | 6      | 6      |
| ------------------- | ------ | ------ | ------ | ------ | ------ | ------ |
| **Instruccion/MUX** | **m3** | **m4** | **m5** | **m6** | **m1** | **m2** |
| Store               | 5      | 6      | 9      | X      | 0      | 2      |
| Load                | 5      | 6      | 9      | 11     | 0      | 2      |
| Int                 | 5      | 7      | 9      | 10     | 0      | 2      |
| BR                  | 4      | 6      | EV     | 10     | 1      | EV     |

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

<u>Pregunta 3:</u> Muestre el cronograma de ejecución de las instrucciones de una iteración entera del bucle y de la primera instrucción de la siguiente iteración, en el caso en que p->dat > max. Identifique los ciclos perdidos en el cronograma e indique cuál es el motivo.

<u>Pregunta 4:</u> Calcule el CPI medio suponiendo que la condición p->dat > max se cumple en el 10% de las iteraciones.

> $CPI=0.1*CPI_{salto}+0.9*CPI_{NoSalto} = 0.1*\frac{22}{7}+0.9*\frac{20}{7}$

### Ejercicio 3.10

<u>Pregunta 1:</u> Dibuje un diagrama temporal que muestre la interpretación de una iteración del bucle. En el diagrama temporal debe mostrarse la inyección de instrucciones nop cuando se gestiona un riesgo. Indique los ciclos perdidos por cada tipo de riesgo y calcule el CPI de una iteración.

> Se pierden 4 ciclos por RD. No asumo los 4 ciclos que se perderian por el RS del final del bucle.
>
> El $CPI = 13/4 = $ 

El computador donde se ejecuta el programa funciona a una frecuencia de 500 Mhz y consume una potencia de 30 W (vatios). La batería que alimenta al procesador suministra 1 A . H (amperios por hora) a 5 voltios.

<u>Pregunta 2:</u> Calcule la energía de la batería. 

> $E = P * \Delta T, P = V*I$
>
> $E_B = 1 A*H *\frac{3600s}{1 hora}* 5 V= J$

<u>Pregunta 3:</u> Calcule la energía consumida por el procesador en un ciclo.

> $E_{procesador}^{ciclo} = Potencia * T_c = 30W(\frac{J}{S})*(500MHz)^{-1} =$

<u>Pregunta 4:</u> ¿Cuántas iteraciones del bucle se pueden ejecutar antes de que la carga de la batería se reduzca a la mitad?. Exprese el resultado en millones de iteraciones.

> $Iteraciones = \frac{E_{P}^{Ciclos}*CPI^{it}}{0.5*E_B} = $

### Ejercicio 3.3(80)

### Ejercicio 3.5

### Ejercicio 3.16

### Ejercicio 3.14

### Ejercicio 3.21

### Ejercicio 3.15 

### Ejercicio 3.22

