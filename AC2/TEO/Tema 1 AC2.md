## Tema 1 AC2

[TOC]

### Maquina von Neumann

Una máquina Von Neumann es un modelo de arquitectura, consta de:

* <u>Unidad de procesado</u>,(U.P.) con:
  * Unidad de Control (contador de programa)
  * Unidad funcional (realiza los cálculos)
* <u>Memoria</u>, con acceso a datos e instrucciones.

El conjunto de instrucciones se denomina lenguaje máquina. Los compiladores traducen el lenguaje de alto nivel a L.M. Una misma familia puede tener  varias implementaciones (microarquitectura), se puede dar el caso donde una instrucción de L.M. se traduzca en varias instrucciones de la U.P.

Una máquina de esta clase es limitada por la comunicación entre UP y MEM, caracterizada por:

* Latencia: Tiempo entre la solicitud y la disponibilidad del dato en la UP.
* Ancho de banda: Numero de bytes que se transmiten por tiempo.

Hay que destacar que hay que leer de memoria cada instrucción y cada acceso a memoria(LOAD, STORE).

> OP = # operaciones / tiempo
>
> Si queremos interpretar 500 millones de instrucciones por segundo, necesitaremos(con 64 bits):
>
> Tiempo Acceso Medio = 1seg/500*10^6 = 286ps
>
> Ancho Banda = #Bytes/Tiempo = 28 GBytes/s

### Propiedad de localidad y jerarquía de Memoria

Los programas (conjuntos de instrucciones) tienden a interpretar instrucciones y acceder a datos recientemente utilizados; Además de acceder a posiciones de memoria cercanas.

* Localidad temporal: Acceso a una posición de memoria ya accedida
* Localidad espacial: Acceso a una posición contigua.

El factor que nos limita estas propiedades es la distribución de la memoria.

> Ciclos Medios Aceso = CMA = CICLOSacierto + (FALLOSref * PENf)

### Progreso de los procesadores y métricas

>1/Rendimiento = Texec = N * CPI * Tc
>
>Tiempo / Programa = instr / programa * ciclos / inst * Tiempo / Ciclo
>
>Speed-Up = Tori / Tnew --> (Tori / Tnew) - 1) * 100
>
>CPImedio = SUM[(Ni * CPIi)/N]

Donde N depende del compilador y el LM, el CPI depende de la organización y el LM y el Tiempo de ciclo depende de la tecnología y la organización. Añadiendo la jerarquía de memoria, obtenemos:

> T = (N * CPIup + CM) = (N * CPIup +(N * FALLOSinst * Pf)) * Tc
>
> T = (N * CPIup + CM) = (N * CPIup +(N * REFinst* FALLOSref * Pf)) * Tc

Donde podemos usar los fallos de acceso por instrucción o los fallos por referencias a memoria. 

### Ley de Amdahl

> La ley de Amdahl establece que la ganancia por añadir una mejora en un diseño está limitada por la fracción de tiempo original en que se utiliza.

![img](rsc\amdahl)

$$
F_m = T_2/T_0; G_m = T_2/T_3 \\
G=\frac{T_0}{T_m} = \frac{T_0}{T_1+T_3} = \frac{1}{(1-F_m)*T_0 + F_m/G_m}
$$

Entonces, la ganancia depende de $F_m$, la fracción de  tiempo original donde se puede usar la mejora y de $G_m$, la ganancia cuando se utiliza el la mejora el 100%..

### Concurrencia en Instrucciones

Para acelerar la interpretación de instrucciones se pueden usar varias técnicas de concurrencia; el objetivo es reducir el tiempo de ejecución de forma transparente al programador.

Hay que destacar que la ganancia de estas técnicas se ve afectada por dependencias de datos entre instrucciones o limitaciones de recursos.

#### Segmentación

Interpretar  las instrucciones de forma segmentada, es decir, iniciando una instrucción en cada ciclo (o acabando). Una instrucción se divide en etapas, la problemática son los recursos, no se puede solapar su uso. La ganancia ideal es el número de etapas.

#### Paralelismo

El paralelismo es trata de añadir mas recursos de cálculo, para procesar varias instrucciones a la vez, se puede combinar esta técnica con la segmentación. La ganancia ideal es el numero de instrucciones por ciclo por el numero de etapas.

### Multihilo

El objetivo de las técnicas de multihilo es incrementar el número de programas ejecutados por unidad de tiempo.

La técnica utiliza los espacios de espera a memoria, a E/S o fallos de cache para realizar instrucciones de otro hilo. Se pueden distingir varios tipos de multihilo:

* Grueso: En un intervalo de tiempo, solo se ejecutan instrucciones de un hilo
* Fino: Existen varios hilos activos, pero en un ciclo solo se ejecutan instrucciones de un hilo.
* Simultáneo: Varios hilos activos y se pueden ejectuar en un mismo ciclo.

### Potencia y Energía

La energía se mide en unidades de trabajo (Julios) y la Potencia es la energía consumida por unidad de tiempo(Julio/s o W).

> Pcom = C * V^2 * freq



