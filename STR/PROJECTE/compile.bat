echo starting Compilation...

arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -c src\boot.S -o objects\boot.o
arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c src\kernel.c -o kernel.o -O2 -Wall -Wextra
arm-none-eabi-gcc -T linker.ld -o myos.elf -ffreestanding -O2 -nostdlib boot.o kernel.o

echo end Compilation