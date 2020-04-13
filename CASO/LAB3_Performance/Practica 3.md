## Pràctica 3 - Rendiment

1. **Escriviu un programa que calculi el temps que triga una crida a sistema senzilla. Feu una taula amb els temps d'execució que obteniu. Per què els temps d'execució són tan diferents?**

| Syscall                         | sbrk(0) | sbrk(inc)  | sched_yield() | getpid() | fork()/waitpid() |
| ------------------------------- | ------- | ---------- | ------------- | -------- | ---------------- |
| **Execution time (microsecs.)** |         | man sbrk.2 |               |          |                  |

2. **Podeu comprovar d'alguna manera que els programes executen realment la crida a sistema? (I no aprofiten el resultat retornat per la crida anterior).**

   Haurem de comprovar si el temps de l'execucció de totes les crides a sistema es sempre igual. Aquest temps hauria de ser sempre igual al temps de sistema emprat per la crida.

   Si veiem que aquest temps es menor, voldra dir que la llibreria glibc esta guardant els resultats i optimitzant els valors de retorn, per tal d'estalvir crides a sistema síncrones que augmentarien el temps d'execucciò.

3. **A la darrera transparència del tema Virtualització-Sincronització-MesuresdeRendiment (transp. 50) us demanem que feu un programa que escrigui al disc 500MBytes, mesurant el temps que triga a fer-ho. Des d'un usuari no privilegiat (no root), executeu el vostre programa sobre un fitxer en el disc de la màquina que feu servir per aquest laboratori. Per exemple, podeu fer-ho sobre un fitxer en el directori /tmp.**

4. **Modifiqueu el(s) programa(es) per poder canviar la mida de les dades escrites al disc. Un cop
   executat(s) amb les diferents mides, per exemple (0.5, 1, 2, 4 Gbytes, si teniu espai al disc), feu una gràfica amb els resultats que obteniu de bandwidth. A l'eix de les X situeu el tamany de les dades transmeses i a l'eix de les Y, el bandwidth. Podeu usar LibreOffice scalc, el GNU plot, el jgraph… i comparar els resultats que obteniu amb el vostre company de laboratori.**

5. **Si executeu el programa com a administradors (root), obteniu alguna diferència en els**
   **resultats?**

6. **Escriviu i executeu una aplicació similar a la del punt 2, però que llegeixi del disc. Feu una gràfica similar a la del punt 2, que mostri ara el bandwidth obtingut per les lectures. Compareu els resultats.**

7. **Useu les eines del sistema vmstat i iostat per veure el bandwidth obtingut en lectura i escriptura de fitxers quan executeu els programes write-to-disk i read-from-disk, per separat i alhora. Per una mida concreta (p. ex. 500 Mb), coincideixen amb els vostres números?**