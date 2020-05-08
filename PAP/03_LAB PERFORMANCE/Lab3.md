## LAB 3: Performance characteritzation of HPC clusters

En el document s'inclouen els resultats de diferents programes de prova. Els resultats es comparen amb la màquina BOADA. Cada programa de proves està dissenyat per un supòsit.



### Stream

Aquest joc de proves comprova operacions d’alt ús de memória. L'ample de banda obtingut de les diferents operacions es representa en el gràfic.
![](Lab3.assets\MB_s vs #threads.png)

Boada utilitza les memories DDR4-2400 i DDR4-2133 que tenen sobre el paper un ample de banda de pic de 19.200 i 17.066 MB/s. 

Per mirar el rendiment concret de la memòria hauríem de centrar-nos en els resultats de l’operació de còpia, ja que les altres operacions veuen limitat el seu ample pel temps en realitzar les operacions.

Mirant els resultats, podem comprobar que existeixen diverses memòries que s’accedeixen en paral·lel; donant lloc a una lantecia major a la l’especificada pel tipus de memòria. 

Pel que fa a l'ús de les directives numactl, tenim que aquestes controlen les polítiques de planificació i ubicació de memòria. L'opció ``--membind`` fa que nomès s'ubiqui memoria als nodes; d'altra banda que l'opció ``--cpunodebind`` fa que s'executin les comandes als nodes seleccionats. 

S'han aplicat els següents paràmetres en els diferents test proposats:

* Ubicar la memória i els threads a un NUMA node.(V1 al gràfic)``numactl -m 0 -N 0``
* Ubicar la memória a un node i els threads a un altre node.(V2 al gràfic)``numactl -m 0 -N 1``
* Ubicar memória i threads a dos nodes.(V3 al gràfic)``numactl -m 0,1 -N 0,1``

> Afegir gràfic i comentar

### Linpack

### HPCG

