
.text
.global _start
_start:
			ldr		r0,=0x53000000  @ WATCHDOG寄存器地址
			mov		r1,#0x0			
			str		r1,[r0]			@ 写入0，禁止WATCHDOG,否则cpu会不断重新
			
			ldr		sp,=1024*4		@ 设置堆栈，但不能大于4k，因为该开发板的SRAM（静态存储器）只有4k
			bl		main			@ 跳转到main函数中调用程序，执行完后，再跳转回来
			
halt_loop:
			b		halt_loop
			