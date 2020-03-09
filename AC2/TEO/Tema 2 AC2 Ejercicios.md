[TOC]

### Ejercicio 2.1

Un procesador segmentado tiene tres etapas (I , M y A). Existen, únicamente dos tipos de instrucciones X e Y y su interpretación utiliza las etapas en los ciclos especificados a continuación.

<u>Pregunta 1:</u> Compruebe que es posible que exista colisión al ejecutar un programa si la latencia de iniciación de instrucciones es de un ciclo.

En el caso de dos instrucciones del mismo tipo no habra colisión possible, pero si primero ejecutamos una instr. Y seguida de una X el recurso A se utilizaria a la vez.

Esto viene dado porque en diferentes ciclos se utiliza el mismo recurso.



<u>Pregunta 2:</u> ¿Cuál es la latencia de iniciación mínima constante que garantiza que no existe colisión en la ejecución de un programa?. 

La latencia seria 2, para evitar el problema de la pregunta anterior.

<u>Pregunta 3:</u> Rediseñe los dos tipos de instrucciones para que la latencia de iniciación constante sea la menor posible. (NOTA: analice el número de ciclos y utilización de las etapas). 

Añadiendo a las instrucciones del tipo X una etapa de retardo en el segundo ciclo, solucionariamos el problema, ya que desde el inicio de la interpretación de cualquiera de las dos instr. se utilizan los mismo recursos en los mismo ciclos.

<u>Pregunta 4:</u> Razone si el nuevo diseño aumenta o disminuye el tiempo de ejecución de los programas al compararlo con los dos casos anteriores. Para ello, calcule la productividad en cada caso.

$Productividad = \frac{\text{#}OPs}{Tiempo}  = \frac{OPs}{LMI}$

Base(en el caso peor): $P_1 = 1/1.5 = 0.7 ops/ciclo$

Latencia de Inicio = 2, $P_2 = 1/2 = 0.5$ ops/ciclo

Rediseñando las instruciones: $P_3 = 1 / 1 = 1 $ ops/ciclo

### Ejercicio 2.2

<u>Pregunta 1:</u> ¿Cuál es el periodo mínimo de la señal de reloj (tiempo de ciclo)?. 

$T_c \ge 20ps+300ps \ge 320 ps$

<u>Pregunta 2:</u> Calcule la productividad del módulo secuencial

$P=\frac{OPs}{Tiempo} = 1 / 320ps = 3.12 G \space Ops/s$

Supongamos que la UF anterior se ha dividido en 6 bloques (A, B, C, D, E y F) que se conectan como se muestra en la figura y con los tiempos de retardo que se indican.

![img](2.2Eje)

<u>Pregunta 3:</u> Utilizando 1 registro de desacoplo segmente la UF para maximizar la productividad (2 etapas). Indique la productividad.

> Añadir segmentación requiere que el tiempo de las etapas sea lo mas parejo possible, para que tenga sentido; entonces vemos que el tiempo de la etapa no debe ser superior a 300 / 2 -> 150 ps. Cojeremos las etapas A, B y C aunque sumen un poco más, pero es lo mas parejo a 150 que podemos obtener.

El tiempo de ciclo en este caso sera $T_c \ge Tp + max(Te_i) \ge 20 + 170(ps)$ 

$P = 1 / 190 ps = 5.26 G \space Ops/s$

<u>Pregunta 4:</u> ¿Cuál es la latencia de la operación en el diseño de la 3ª pregunta?.

La latencia es de 2 ciclos.

<u>Pregunta 5:</u> Utilizando 2 registros de desacoplo segmente la UF para maximizar la productividad (3 etapas). Indique la productividad.

$T_c \ge 20 + 110 (ps)$

$P = 1 / 130 ps = 7.69 G\space Ops/s$

<u>Pregunta 6:</u> ¿Cuál es la latencia de la operación en el diseño de la 5ª pregunta?. 

La latencia es de 3 ciclos.

<u>Pregunta 7:</u> ¿Cuál es el número de etapas mínimo para maximizar la productividad?.

$P = (T_c)^{-1}$

La productividad será máxima con el menor tiempo de ciclo.

Supongamos que un mejor particionado de la UF consigue que todos los bloques tengan el mismo retardo y que el número de bloques puede ser el que queramos.

<u>Pregunta 8:</u> Calcule la productividad en el caso de que el retardo de cada uno de los bloques (tB), en que se divide la UF, es despreciable frente al retardo que representa el registro de desacoplo (tRD) entre etapas (tB << tRD).

> En este caso, el tiempo del registro es el unico que importa para calcular el tiempo de ciclo:

$Tc \ge T_{RD} \rightarrow P = (T_{RD})^{-1} = 50 G \space  Ops/s$

### Ejercicio 2.3

Considere el siguiente circuito donde se muestran bloques combinacionales y el flujo de información entre bloques. Así mismo, dentro de cada bloque, se ha anotado la latencia en picosegundos.

![img](2.3Eje)

<u>Pregunta 1:</u> ¿Cuál es la latencia del circuito?. Marque con trazo grueso las conexiones del camino crítico. Suponga que el retardo de almacenamiento en un registro de desacoplo es cero. 

La latencia del circuito es 170 ps.

Suponga que el retardo de almacenamiento en un registro de desacoplo es cero.

<u>Pregunta 2:</u> ¿Cuál es la máxima productividad, en operaciones por segundo, que se puede obtener al segmentar el circuito?. 

La productividad depende del tiempo de ciclo, sin contar los retardos por possibles riesgos estructurales. El Tiempo de ciclo correspondera al maximo del retardo entre las etapas

$P = (Tc)^{-1} = 16.7 G \space Ops/s$

<u>Pregunta 3:</u> Muestre una organización segmentada que maximice la productividad.

$T_c = 60ps$

| TIPO/CICLO | 1    | 2    | 3    | 4    | 5    |
| ---------- | ---- | ---- | ---- | ---- | ---- |
| 1          | A    | C    | F    | NOP  | J    |
| 2          | A    | C    | NOP  | I    | J    |
| 3          | A    | D    | G    | I    | J    |
| 4          | A    | D    | H    | NOP  | J    |
| 5          | B    | D    | G    | I    | J    |
| 6          | B    | E    | H    | NOP  | J    |
| 7          | B    | D    | H    | NOP  | J    |

<u>Pregunta 4:</u> Muestre un organización segmentada que minimice el número de etapas y mantenga una productividad de al menos una operación cada 85 ps


| TIPO/CICLO | 1    | 2    | 3    |
| ---------- | ---- | ---- | ---- |
| 1          | AC   | F    | J    |
| 2          | AD   | G    | IJ   |
| 3          | AD   | HJ   |      |
| 4          | BD   | G    | IJ   |
| 5          | BE   | HJ   |      |
| 6          | BD   | HJ   |      |

Entre dos etapas puede haber varios flujos de información. Cada uno de ellos requiere de un registro de desacoplo. La información que hay en la entrada de un registro de desacoplo se transfiere a la salida en el flanco ascendente de la señal de reloj. Suponga la siguiente segmentación.

![img](2.2Eje2)

<u>Pregunta 5:</u> Muestre en un esquema los registros de desacoplo numerándolos como 1 o 2 para indicar respectivamente si son registro de salida de la 1ª etapa o de la 2ª etapa.



### Ejercicio 2.16

### Ejercicio 2.8

### Ejercicio 2.9

### Ejercicio 2.19

### Ejercicio 2.14