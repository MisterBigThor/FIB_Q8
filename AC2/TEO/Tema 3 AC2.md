# Tema 3 AC2

[TOC]

## Camino de datos



<u>Lazo o bucle hardware.</u> Es una comunicación entre etapas que permite que en una etapa se utilice información suministrada desde etapas posteriores. La latencia puede verse como los ciclos que tardara la información en volver.

## Semántica del procesador segmentado

Una ejecucción segmentada debe dar el mismo resultado que una serie, por eso es importante que se respete la semántica que ha expresado el programador en el programa; es decir, que se respete el orden de las lecturas y escrituras a posiciones de almacenamiento.

Respetar este orden viene caracterizado por <u>latencia efectiva de la segmentación</u>, los ciclos entre el inicio de un calculo y el ciclo donde se puede utilizar ese calculo.

### Riesgos de datos

Modificación del orden de escrituras/lecturas especificado sobre una posición de almacenamiento.

> Ejemplo: Un dato que es calculado, en nuestro procesador, tarda unos ciclos en guardarse en el banco de registros.

* Dependencia verdadera
* Antidependencia
* Dependencia de salida

### Riesgos de secuenciamiento

Interpretación de instrucciones distinta a la especificada por el programador.

> Ejemplo: Mientras se evalua una instrucción de salto condicional, este procesador puede estar ejecutando instrucciones que modifican el estado de la maquina.

En nuestro procesador tenemos dos bucles HW, uno realimenta la etapa CP y otro desde la etapa ES hasta CP(lat. 5); un bucle HW de latencia mayor que 1 provocara riesgo. Se perderán (latencia del bucle - 1) ciclos.

En este diseño de procesador, detectamos el RS en la etapa D/L y deberemos: 

* <u>descartar</u> las dos instrucciones mas jovenes que ya habrian empezado su CP y BUS.
* <u>Suspender</u> la interpretación de nuevas instrucciones hasta que desaparezca el RS.

![image-](rsc\rs1.jpg)

En la practica CP y BUS seguiran haciendo su trabajo, pero a la etapa D/L se inyectara una 'NOP'.  En la misma etapa que se escriba el CP correcto, ya podemos reanudar la interpretación série.

### Lógica de interbloqueos - Gestión de riesgos

Para gestionar estos riesgos hay que añadir unidades de control(lógica interbloqueos), trataremos los riesgos en la etapa D/L, la primera donde podemos 'saber' si hay riesgo. 

La actuación de la logica será emular el funcionamiento serie, al coste de perder ciclos.

#### Solapamiento de riesgos

ToDo:

#### Circuitos de control

ToDo:

