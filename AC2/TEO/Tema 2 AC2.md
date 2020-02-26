## Tema 2 Segmentacion y Replicacion

[TOC]

### Diseños Serie

En un diseño serie hay que espera a que finalice una tarea para iniciar una nueva. La productividad es la inversa del tiempo de ciclo, es decir, el tiempo en realizar una operación.

### Segmentación

La segmentación permite diseñar un sistema donde se empiece a procesar una operación antes de acabar la actual. Debemos distinguir las diferentes fases, los diferentes módulos combinacionales de cada fase y establecer un secuenciamiento adecuado.

Entre las diferentes etapas, colocaremos registros de desacoplo para que los cálculos de cada etapa no afecten a la etapa siguiente hasta el flanco del reloj. La latencia de una tarea será el tiempo total de procesado de la tarea, en ciclos de reloj.

El tiempo de ciclo, debe garantizar que las lógicas de las diferentes etapas disponen del suficiente tiempo para procesar los datos de entrada:
$$
T_c \ge max(T_{E_i}) + T_p
$$
La ganancia máxima ideal será el numero de etapas. 
$$
T_{seg} = N(T_p+T_L/NE)+(NE-1)*(T_p+T_L/NE)
$$


### Elementos de Desacoplo

#### Celda D (latch D)

Las celdas trabajan por nivel de la señal de reloj. Se implementa con multiplexor, donde la salida alimenta una de las entradas, haciendo que si el reloj esta en el nivel de la entrada realimentada, no se lee la entrada.

#### Registro D (Flip-flop D)

Los registros funcionan por flanco, se utilizan dos celdas unidas, haciendo que en el flanco que no se lee, la primera celda 'guarde' la señal y en el flanco se transmite a la segunda celda que no se actualizara hasta el siguiente flanco.

![img](registroD)

### Tipos de U.F. Segmentadas

La segmentación de cada U.F. puede responder a varios patrones:

![imgUF](tiposUF)



### Interpretación de instrucciones

