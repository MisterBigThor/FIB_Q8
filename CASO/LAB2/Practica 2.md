## Practica 2

2. **Quin processador indica que tenim el programa proc.c? Busqueu a <mach/machines.h>  els codis de “CPU Type” i “CPU Subtype”.**

   El CPU type es 19 i el CPI subtype es 1. Mirant al machines.h veiem que es l'ultim valor possible; podem deduïr que no sap quin tipus de CPU hi ha darrera.

3. **Expliqueu les altres característiques del processador que mostra proc.c. Obtingueu-les del fitxer <mach/processor_info.h> localitzeu-hi l’estructura processor_basic_info.**

   Mirant el kernel interface em trobat la definicio de les caracteristiques que ens diu el executable proc.  

   En primer lloc veiem els ports privilegiats( 0x35 i 0x36) que hi han. Tambe veiem que actualment tenim un unic procesador, amb un identificador (0x37)

   A part del CPU type & subtype tenem un bolean que ens diu si la CPU esta *running*, un altre bolean que diu si aquest es el procesador master () i un numero d'Slot ().

4. **Comproveu que el programa memory-management.c dóna errors al compilar… com els podeu arreglar? (pista: falta una coma (,) a la línia 60). Són clars els missatges d’error que dóna el compilador GCC en aquesta situació?**

   El compilador diu que li faltan arguments, es suficientment clar per buscar l'error.

5. **Un cop arreglat el problema de la pregunta anterior, comproveu que el programa memorymanagement.c funciona correctament. Aquest programa usa processor_info i vm_map de forma intercalada, per demanar memòria 8 cops. L’ús de processor_info per demanar memòria queda fora del seu ús habitual, però funciona correctament. Responeu:** 

   1. **Quanta memòria assigna al procés cada crida a processor_info?** 

      La crida a host_processor retorna un processor_t, que mirant el *sizeof* obtenim que ocupa 4 bytes.

   2. **Quanta memòria assigna al procés cada crida a vm_map?** 

      8192 bytes. Estan assignat a la interficie de la cirda vm_map.

   3. **Quines adreces ens dóna el sistema en cada crida (processor_info i vm_map)?** 

      En el cas de processor_info, la adreça es assignada pel sistema operatiu(ja que realment esta retornant una objecte de tipus processor_t). 

      En el cas de vm_map, el punter del parametre *address* esta inicialitzat a NULL i el sistema operatiu ens busca el primer lloc que acompleix el tamany especificat; cal destacar que al document de kernel interface expresa que l'adreça d'inici de la regió de memoria s'arrodoneix a la seguent pàgina si no hi cap a la actual.

   4. **Són pàgines consecutives? (pista: us ajudarà, incrementar el número d’iteracions que fa el programa… per veure la seqüència d’adreces més clara)** 

      No, l'explicació es la mateixa que a la pregunta 3.

   5. **Quines proteccions podem demanar a l’assignar memòria a un procés Mach? (pista: veieu el fitxer )** 

      Les proteccions possibles son:

      * VM_PROT_READ
      * VM_PROT_WRITE
      * VM_PROT_EXECUTE

      Existeixen dos parametres de protecció, un de max_protection(máxim de permisos que s'apliquen a tot el programa) i un de cur_protection (on defineix el que es pot fer amb la regió.

   6. **Canvieu el programa per a que la memòria demanada sigui de només lectura. Quin error us dóna el sistema quan executeu aquesta nova versió del programa? **

      L'error es Segmentation Fault.

   7. **Després, afegiu una crida a vm_protect (…) per tal de desprotegir la memòria per escriptura i que el programa torni a permetre les escriptures en la memòria assignada. Proveu la nova versió i comproveu que ara torna a funcionar correctament.**

      vm_protect(mach_task_self(), (vm_address_t) &p);
      
      

9,10 

8.  **Feu un programa que creï un flux (thread_create) i li canviï l'estat (uesp, eip) amb les crides thread_get_state i thread_set_state, per engegar-lo posteriorment (thread_resume). Trobareu els tipus genèrics (independents de l'arquitectura) relacionats amb el context d'un flux en el fitxer . La informació específica de com és l'estat d'un thread en la nostra arquitectura i386 la trobareu a : struct i386_thread_state, i #defines i386_THREAD_STATE(flavor), i i386_THREAD_STATE_COUNT**

   **Ara feu que el thread faci un printf(...). Per què us dóna un "bus error"? Podeu esbrinar què passa?** 	

   

9. **Observar que en el fitxer  tenim dues definicions de funcions interessants per resoldre el problema de la pregunta anterior:**