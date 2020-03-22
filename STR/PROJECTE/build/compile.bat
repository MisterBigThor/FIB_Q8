@echo off
echo start compilation
cd ..
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -c src/boot.S -o OBJECTS/boot.o

arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/kernel.c -o OBJECTS/kernel.o -O2 -Wall -Wextra -I include/
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/uart.c -o OBJECTS/uart.o -O2 -Wall -Wextra -I include/
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/stdio.c -o OBJECTS/stdio.o -O2 -Wall -Wextra -I include/
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/stdlib.c -o OBJECTS/stdlib.o -O2 -Wall -Wextra -I include/
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src/atag.c -o OBJECTS/atag.o -O2 -Wall -Wextra -I include/
cd build

arm-none-eabi-gcc -T linker.ld -o myos.elf -ffreestanding -O2 -nostdlib ../OBJECTS/*.o

echo end compilation
