[TOC]

## STR - mini project by Victor Correal

### Project Motivation

The aim of this project is to build a Real Time Kernel to run in a Rasperry Pi 3 (in my case, Raspberry Pi 3 model B rev1.2). 

The kernel will be able to schedule tasks (with freeRTOS), work with serial line, GPIO's ports and to receive instructions through the Ethernet RJ45 connection. In *Sistemes Operatius 2* we built a similar operating system in C (with a few syscalls to allocate data, create threads), based in Linux kernel, for this reason I consider it would be affordable to implement this Real Time Kernel.

I also want to create a tool to measure, in function of the assembly code the expected time of execution of a program, internaly in the OS. For testing, I can use and Arduino Uno to use as an oscyloscope to watch over the times.

I am motivated and eager to work with the ARM architecture inside the raspberry Pi, because in the future I want to build a raspberry cluster at home with 3 or 4 raspberry.

I append a tutorial that I would use in the begging of the project to set up a development enviroment: https://jsandler18.github.io/ .

### Implementations Steps

1. Set up the development enviroment.
2. Learn about the ARM architecture and the instructions set.
3. Build the instructions tool measure.
4. Basic OS funcionality. (tasks, systemcalls, GPIO lib, etc...) .
5. Import FreeRTOS (or adapt) on the basic OS.
6. Performance analytic.
7. Implement serial line comunication.
8. Implement Ethernet comunication

