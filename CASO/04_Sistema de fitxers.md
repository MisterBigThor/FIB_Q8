## Sistema de fitxers

### Gestió de quotes

Límit de quantitat de dades que un usuari té en un sistema de fitxers. Requereix que el sistema de fitxers i el kernel les suporti.

Es dona un "Grace period" en el qual l'usuari pot arribar al límit només amb warnings.

### Journaling

Les operacions sobre fitxers inclouen diverses operacions físiques, si en mig de les operacions s'apaga la máquina la recuperació sera molt costosa(recórre l'arbre de directoris).

La millor solució es anotar al journal, de forma asíncrona, les operacions que s'han iniciat sobre el disc.

* Cal escriure per avançat, respecte a la resta del disc.
* En recuperació, només es tenen en compte seqüencies completes i que el checksum es correcte.
* Existeixen dos nivells de journaling:
  * Físic: Grava una còpia de cada bloc
  * Lògic: Grava només els canvis a les metadates

### Sistemes de fitxers en xarxa

Existeixen diferents solucions per tenir un sistema de fitxers en xarxa:

* Network Files System (NFS): 
  * Centralitzat a un servidor, el sistema de fitxers "extern".
  * Funciona sobre Remote Procedure Calls.
  * Es monta el sistema de fitxers al sistema de fitxers del host, es transparent al usuari final.
* Network-attached storage(NAS)
  * Servidor de dades a nivell de fitxer.
  * L'implementació sovint es un RAID.
  * Es connecten als clients via NFS, SMB o AFP.
* Storage area network(SAN)
  * Xarxa dedicada a servir blocks de dades.
  * Connexió via Drivers físics i firmware propi.
* Andrew File System (AFS)(OpenAFS)
  * Sistema distribuït en diferents servidors. El resultat es una visió homogènia dels fitxers independent de la localització del usuari.
* Object Exchange (OBEX) + Filesystem in User Space (FUSE)
  * OBEX: Protocol d'intercanvi de dades amb dispositius mòbils (tot tipus de fitchers/xarxes).
  * FUSE: Mòdul carregable, que permet crear sistemes d'arxius virtuals. FUSE en essència es un visualitzador de sistemes de fitxers físics.

### Mecanisme de boot

* BIOS/DOS

* UEFI

  

