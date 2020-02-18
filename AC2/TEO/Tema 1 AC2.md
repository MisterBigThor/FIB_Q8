## Tema 1 AC2

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



### Concurrencia en Instrucciones

### Multihilo

### Potencia y Energía

La energía se mide en unidades de trabajo (Julios) y la Potencia es la energía consumida por unidad de tiempo(Julio/s o W).

> Pcom = C * V^2 * freq



