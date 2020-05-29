## STR - Earliest Deadline First (EDF) sobre FreeRTOS

### Victor Correal Ramos



En este documento se presenta el desarrollo de un sistema EDF sobre el sistema operativo de tiempo real FreeRTOS. Primeramente se exponen, por conceptos, las diferentes caracterísiticas que hay que implementar; seguidamente se exponen algunos de los detalles de la implementación.

## Marco Teórico

En los sistemas EDF, las prioridades dependen de las *deadlines* absolutas y estas se modifican en tiempo de ejecucción, entonces deberemos controlar estas *deadlines* absolutas para asignar correctamente la prioridad de cada tarea.

Debermos aplicar un modelo como este: $d_i = \phi_i + k*T_i + D_i$ . Donde la variable $k$ deberá incrementarse  cada vez que una tarea ha completado un ciclo, es decir, se ha completado un *computing time*.

La politica de planificación de FreeRTOS garantiza que, en cada instante, la CPU ejecuta la tarea con prioridad más alta(mayor número de prioridad). El numero máximo en FreeRTOS se puede configurar en el archivo FreeRTOSConfig.h, para este caso necesitaremos prioridades desde 1 hasta 5 y en ciertos momentos importantes deberemos aplicar la anterior fórmula y asignar la prioridad correcta.

Se mantendrá una estructura donde cada tarea mantenga su $d_i$ y $k$. Debermos añadir también una lógica que asigne las prioridades de 1 al 5 correctamente cada vez que sea necesario.

## Implementación

* Podemos actualizar la prioridad de las tareas con la llamada ``vTaskPrioritySet(XHandle, P)``

* Caldra hacer una correspondéncia entre el $d_i$ y un número entero, dado que las prioridades en FreeRTOS son enteros.
* En esta implementación, usaremos la *callback* (o hook function) `vApplicationTickHook(void)`. Aqui actualizaremos las prioridades del sistema.
* 



## Conclusiones



