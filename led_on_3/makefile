CFLAGS 	:= -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -ffreestanding
led.bin : led_on_3.s  main.c
	arm-linux-gcc $(CFLAGS) -c -o led_on_3.o led_on_3.s
	arm-linux-gcc $(CFLAGS) -c -o main.o main.c
	arm-linux-ld -Ttext 0x0000000 led_on_3.o main.o -o leds_elf
#	arm-linux-ld -Tleds.lds  crt0.o leds.o -o leds_elf
	arm-linux-objcopy -O binary -S leds_elf leds.bin
	arm-linux-objdump -D -m arm  leds_elf > leds.dis
clean:
	rm -f   leds.dis leds.bin leds_elf *.o