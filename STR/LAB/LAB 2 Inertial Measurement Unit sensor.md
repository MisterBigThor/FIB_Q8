lab2_2_CORREAL_MESTRE

## LAB 2 Inertial Measurement Unit sensor

En aquest laboratori tenim l'objectiu de mesura el *worst case execution time* en agafar mostres del sensor inercial.

### Introduction

Aquest sensor (AltlMU) funciona amb protocol I2C i Sparkfun proporciona una llibreria per poder llegir les dades del giroscopi i del accelerometre.

El nostre codi aplica una formula per calcular el pitch i el roll (en funcion de les acceleracions del 3 eixos), ja que les dades extretes del sensor directament no son significatives. Em encapsulat aquest càlcul en una funció que calcula aquest dos valors.

Per filtrat les dades, ja que aquests sensors porporcionen dades amb molt de soroll utilitzem un filtre RC *software*.

Aquest es el nostre codi que permet mesura les dades; per últim les dades de pitch i roll s'envien en mode 
*debug* al serial plotter

### Finding the worst case execution time

Tenim diversos factors que ens afecten a aquest cálcul. 

D'una banda tenim que el sensor esta implementan  el protocol I2C i aquest es un factor de risc, ja que si tenim més dispositius esclaus I2C el temps pot variar.

El temps d'execucció del codi, també varien en funció de si utilitzem variables globals o retornem els valors



//Breu explicacio del codi



//Breu explicacio del filtratje 



//Mesura del temps d'execuccio





https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing