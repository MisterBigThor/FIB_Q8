## LAB 2 Inertial Measurement Unit sensor

##### By Victor Correal and Raimon Mestre

In this lab class we are asked to find the worst case execution time for sampling a inertial sensor.

### Introduction

The inertial sensor works with I2C communication and a SparkFun library provides a nice interface to pick up the data.

Our arduino sketch reads the accelerometer raw data and applys two conversions. The first one converts the raw data to 2 readable values (pitch and roll); after that, we apply a RC software filter, to reduce the noise.

We also define a DEBUG symbol, that allows as to print to the serial line the values of pitch and roll.

### Execution Time

A first look for the execution time requires add a digital pin to use the oscilloscope; in our case we obtain this:

![](C:\Users\corre\Downloads\WhatsApp Image 2020-03-03 at 13.47.14.jpeg)

We mesure the average time is around 2,8 ms. In the next section we investigate some factors that can afect in the execution time. 

### Finding the worst case execution time

Finding the worst case execution time is capital to make a good real time sistem. In this case, we have some factors that we need to study:

* The sensor features: We need to read the datasheet of the sensor, to find features like temperature, maximum values, correct operation voltatge, etc ... that can afect the performance.

* The communication: This sensors works with I2C, so if the i2C channel will be busy it can afect the execution time; we need to read about this protocol.

* The result: In this case, we don't do nothing with the calculatet data, but the execution time will depend if we use global variables or we pass the results to the next stage in a bigger system.

* The code: We can count assembly instructions (or even optimize the code) by disassembling the binary and finding the datasheet of the Arduino.

  