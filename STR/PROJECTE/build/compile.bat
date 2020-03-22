@echo off
echo start compilation
cd ..
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -c src/kernel/boot.S -o OBJECTS/boot.o
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/kernel/kernel.c -o OBJECTS/kernel.o -O2 -Wall -Wextra -I include/kernel
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/kernel/uart.c -o OBJECTS/uart.o -O2 -Wall -Wextra -I include/kernel


arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/common/stdio.c -o OBJECTS/stdio.o -O2 -Wall -Wextra -I include/common
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/common/stdlib.c -o OBJECTS/stdlib.o -O2 -Wall -Wextra -I include/common
cd build

arm-none-eabi-gcc -T linker.ld -o myos.elf -ffreestanding -O2 -nostdlib ../OBJECTS/*.o

echo end compilation