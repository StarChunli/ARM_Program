led_on.bin : led_on.s
	arm-linux-gcc -g -c -o led_on.o led_on.s
	arm-linux-ld -Ttext 0x0000000 -g led_on.o -o led_on_elf
	arm-linux-objcopy -O binary -S led_on_elf led_on.bin

clean:
	rm -r led_on.bin led_on_elf *.o
