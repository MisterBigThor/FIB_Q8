## Lliurament LAB 2 PAP

En aquest document s'explica l'implementació del itinerari 1: worksharing model. Seguidament també veiem els programes que s'han utilitzat per comprobar el funcionament .

### Decisions d'implementació

Detallare seguidament els trets mes importants sobre cada secció de la llibreria:

Primerament, la llibreria inicialitza les estructures de dades de totes les possibles parts implicades i crea el thread amb identificador -1.

La primera estructura que em de construir es la parallel; esta pensat com la unitat de control dels threads. La llibreria inicialitza el thread amb identificador -1 i totes les crides a GOMP_* depenen d'aquest thread. El controlador guarda per cada thread: 

* les dades i codi que s'ha d'executar.

* l'identificador de thread d'intre del 'team' i nivell d'anidat.
* Una barrera i un punter a barrera (només un thread de cada team creará la barrera).
* Array d'enters, per identificar els joins que s'han de fer.

Amb aquest controlador podem implementar les crides a parallel i asegurar que els paralels anidats acabaran abans que el paralel exterior. Per tal de permetre les regions anidades, les crides a funcions intrínseques es fan contra la clau especifica de cada thread.

Pel que fa a les estructures de sincronització:

* La barrier esta construida amb una pthread barrier i s'actualitzen el numero de threads a esperar al inici de cada regió paral·lela.
* Les seccions crítiques sense nom, s'implementen directament amb un pthread_mutex
* Les seccions crítiques amb nom estan implementades sobre una estructura de tipus map, amb un màxim de 5 named locks. S'ha utilitzat una estructura d'un array per fer el map.

Seguidament, el constructor single esta implementat de forma 'arriscada'. El controlador d'aquesta estructura es guarda, per cada thread, el número de vegades que s'ha notificat l'arribada d'un single i s'actualitza, de forma atómica una variable que representa el numero màxim de 'singles' que s'han registrat. El seu funcionament segueix aquest esquema:

````mermaid
graph LR;
A[Single Reached] --> F[++singles.ID]
F-.->B{singles.ID>MAX}
B==>|SI|C(Return true)==>G[Act. Max]
B==>|NO|D(Return false)
````

Es arriscat, ja que es pot retornar fals si el valor del máxim s'actualitza en més d'una unitat.

Per últim, la construcció loop guarda una llista (implementada com una llista doblement encadenada)  de descriptors de loop i una estructura de control per poder saber, per cada thread, en quin loop es troba. La lógica es podria resumir amb el següent esquema:

````mermaid
graph LR
    subgraph init a loop:
    A["GOMP_loop_dyn_start()"]==>B["loops[ID]++"]
    B==>C{"loops[ID] > actualLoop"}
    C==>|YES|D(init new descriptor)
    C==>|NO|F["return allocate Iterations @ loopDescriptor(loops[ID])"]
    D==>F
    end
	subgraph more iterations? 
	G["GOMP_loop_dyn_next()"]==>F
    end
    subgraph no more iterations left
    F-.->R["return false"]
    R==>Z["GOMP_loop_end()"]
    R==>Y["GOMP_loop_end_nowait()"]
    end
````

El control coneix en cada moment i per cada thread, en quin loop es troba i pot adjudicar regions d'iteracions en cada moment.

En el moment de definir el descriptor, es calculen els chunks necesaris i un array permet saber quines regions han sigut adjudicades ja. Els procediments de dynamic_start i allocate_iterations es fa protegit amb mutex, ja que hi ha condicions de carrera sobre la llista global de descriptors.

### Possibles millores

Hi ha certes opcions de diseny, que podrien aportart millor rendiment peró que son mes complicades d'implementar:

1. Hash map per les seccions crítiques amb nom.
2. Adjudicació d'iteracions sobre "bancs" de threads, aixi l'exclusió mutua només afecta al banc d'aquell thread.
3. Cercant de noves iteracions amb un valor aleatori
4. Afegir les seccions crítiques amb nom al descriptor de la regió paral·lela

### Resultats

S'ha definit una macro(LOG) per tal de poder veure el funcionament global i coordinat de cada part de la llibreria.

Els programas de prova que s'han utilitzat, i els resultats comparats amb la versió real es resumeixen en aquesta taula.

| NOM TEST   | RESULTAT | TEMPS GOMP | TEMPS OMP |
| ---------- | -------- | ---------- | --------- |
| tparallel  |          |            |           |
| tparallel1 |          |            |           |
|            |          |            |           |
|            |          |            |           |
|            |          |            |           |
|            |          |            |           |
|            |          |            |           |

S'han realitzat 5 execuccions i s'ha prés la mitjana. La descripció de cada test està a un document apart, per tal de simplificar la taula.

### Conclusions i valoracions

Un cop acabat la meva modesta implementació d'openMP he pogut aprende molt millor les eines que proporciona POSIX threads. També el funcionament de la llibreria real d'openMP.



