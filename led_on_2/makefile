led_on_2.bin: led_on_2.s main.c
	arm-linux-gcc -g -c -o led_on_2.o led_on_2.S
	arm-linux-gcc -g -c -o main.o main.c
	arm-linux-ld -Ttext 0x0000000 -g  led_on_2.o main.o -o led_on_c_elf
	arm-linux-objcopy -O binary -S led_on_c_elf led_on_c.bin