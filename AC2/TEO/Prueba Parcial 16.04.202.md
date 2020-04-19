## Prueba Parcial 16.04.202

### Victor Correal Ramos

### Ejercicio 1

Pregunta A

> $CPI_{medio} = CPI_1*0.3+CPI_2*0.7 =$
>
> $=2.36*0.3+2.88*0.7=2.72$

Pregunta B

> Podemos expresar el $CPI_{medio}$ teniendo en cuenta las instrucciones de secuenciamiento:
>
> $CPI_{medio} = 0.3*CPI_{medio} + 0.7*CPI_{medio} $
>
> El rendimiento es la inversa del tiempo de ejecucción ($T_{ejec}=N*CPI*Tc$). Entonces doblando la frecuencia y aplicando un incremento X sobre las instrucciones de secuenciamiento obtenemos:
>
> $T_{ejec} = N*(0.3*CPI_{medio}*X + CPI_{medio})*T_c*2$
>
> Si debemos mantener el rendimiento,  podemos obtener el valor de X cuando la ganancia respeto al diseño original es 1, entonces obtenemos la ecuación:
>
> $G=1=\frac{N*CPI_{medio}*T_c}{N*(0.3*CPI_{medio}*X + CPI_{medio})*T_c*2}$
>
> $1=\frac{CPI_{medio}}{(0.3*CPI_{medio}*X + CPI_{medio})*2}$
>
> X = -1.67
>
> Es decir, el valor necesario de mejora es del67%

Pregunta C



Pregunta D

> csal <= suma_int(4) and '1';
>
> SUM <=suma_int(3)&suma_int(2)&suma_int(1)&suma_int(0);

Pregunta E

``````vhdl
architecture of Suma is
suma_int <= std_logic_vector(‘0’ & (signed(A) & '1' ) + (‘0’ & signed(B)) & cen) );
csal<= (not suma_int(4) and A(3) and A(4) ) or (suma_int(4) and not A(3) and not A(4));
sum <= suma_int(3)&suma_int(2)&suma_int(1)&suma_int(0);
``````

### Ejercicio 2

Pregunta A

> Consideramos los retardos(en ns) de las etapas como:
>
> Retardo etapa 1: 6+2 = 8, Retardo etapa 2: 5, Retardo etapa 3: 4+2=6ns, Retardo etapa 4: 7+2=9
>
> El tiempo de ciclo minimo sera mayor o igual al mayor retardo de etapa, en este caso: 9 ns + retardo de los registros de desacoplo.

Pregunta B

> Las latencias prohibidas vendran dadas porque las etapas 1 y 2 se utilizan en ciclos diferentes. En este caso las latencia prohibidas son 3,4,5 y 6.
>
> ![](WhatsApp Image 2020-04-16 at 16.34.30.jpeg)

Pregunta C

> La LMI sera = (1+5+1)/3=2.33. Los MOPS se pueden deducir como:
>
> $LMI\space ciclos*\frac{1 operacion}{6 ciclos}*\frac{1 ciclo}{9 ns}$
>
> $MOPS = 2.33/(6*9ns)10^6 = 43.14MOPS$

Pregunta D

> De cada 6 operaciones, 2 operaciones podran dar resultado. Entonces la fracción será de 2/6 = 0.33

Pregunta E

> En este caso, se utilizan los recursos de las etapas en diferentes ciclos de la interpretación. La tabla de reservas es de tipo no lineal, en este caso para mejorar la productividad seria replicar los recursos

Pregunta F

> 6(mirar dibujo apartado B)

### Ejercicio 3

Pregunta a

Aplicamos este factor para calcular los fallos /instrucción

$CPI \space \frac{Ciclos}{Instruccion}*\frac{2GHz^{-1}}{1 Ciclos}*\frac{1 fallo}{15 ns}$

$Fallos_A = 0.25^{-1}*2GHz^{-1}/15ns=0.13$

$Fallos_A = (0.2*0.25)^{-1}*2GHz^{-1}/10ns=0.2$

Pregunta b

Pregunta c

Pregunta d



