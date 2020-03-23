## 

En nuestro caso, disponemos de la arquitectura 'armv71' y el modelo -A53

https://www.arm.com/products/silicon-ip-cpu/cortex-a/cortex-a53

ARM diferencia varios casos de uso dentro de su gama de procesadores:

etc, etc, etc

En nuestro caso, vemos que la arquitectura que implementa el A53 es la ARMv8-A

Primer problema, el ubuntu nativo de raspberry pi dice que la arquitectura el armv71.

## Architectura ARM

Los procesadores cortex, como el nuestro, son del tipo superescalar, ejectuando + 1 instruccion por ciclo y con mas de un core.

Los registros  disponibles son x0,..,x30 -> usando como 64 bits o w0,...,w30 usa 32 bits(son el mismo).

32 registros mas de 128bits para coma flotante. Vx

Registro 0: xzr y wzr

Stack Pointer: sp (usualmente para usar de base en loads/store)

x30 : registro de link (linkregister LR)

PC: no se puede modificar con operaciones de procesado

> ADR Xd, . //. means here and adr return the @ of the label.

Registros de sistema: 

Existe un read (MRS Xd, <sys_reg>) y un write (MSR <sys_reg>, Xn)

Todos los registros de sistema acaban en _ELx donde la x define el privilegio para aceder al registro.

https://developer.arm.com/architectures/learn-the-architecture/armv8-a-instruction-set-architecture/system-calls

