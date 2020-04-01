````asm
load r1, 0(r2) 	;a
load r3, 0(r4)	;b
add r5, r1, r3	;c
store r5, 0(r6)	;d
add r2, r2, #8	;e
add r4, r4, #8	;f
add r6, r6, #8	;g
sub r9, r9, #1	;h	
bne r9, 1$		;i
--> dependencia vertadera
..> antidependecia
.M.> dependencia de Memoria
````

````mermaid
graph TB;
    A-->C
    B-->C
    C-->D 
    D-.->G
    B-.->F
    A-.->E
	H-.->I
	A-->|M|D
	B-->|M|D
````