@echo off
qemu-system-arm -m 256 -M raspi2 -serial stdio -kernel myos.elf