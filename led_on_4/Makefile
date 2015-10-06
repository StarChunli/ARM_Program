CFLAGS 	:= -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -ffreestanding
led.bin : led_on_4.s  key_led.c
	arm-linux-gcc $(CFLAGS) -c -o led_on_4.o led_on_4.s
	arm-linux-gcc $(CFLAGS) -c -o key_led.o key_led.c
	arm-linux-ld -Ttext 0x0000000 led_on_4.o key_led.o -o leds_elf
#	arm-linux-ld -Tleds.lds  crt0.o leds.o -o leds_elf
	arm-linux-objcopy -O binary -S leds_elf leds.bin
	arm-linux-objdump -D -m arm  leds_elf > leds.dis
clean:
	rm -f   leds.dis leds.bin leds_elf *.o