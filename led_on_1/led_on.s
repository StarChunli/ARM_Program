@ 功能：LED电灯程序，点亮LED1

.text				@ 指定了后续编译出来的内容放在代码段【可执行】
.global _start 		@ 告诉编译器后续跟的是一个全局可见的名字【可能是变量，也可以是函数名】
_start:				@ 是一个函数的起始地址，也是编译、链接后程序的起始地址
		LDR		R0,=0x56000050  @ LDR:将0x56000050地址放到R0中
		MOV		R1,#0x00000400	@ MOV（MVN）指令可完成从另一个寄存器，被移位的寄存器或将一个立即数加载到目的寄存器
		STR		R1,[R0]			@ 将R1寄存器的值，传送到地址值为R0的（存储器）内存中
		LDR		R0,=0x56000054
		MOV		R1,#0x00000000
		STR		R1,[R0]

MAIN_LOOP:
		B		MAIN_LOOP		@ B指令无法实现子程序的返回，只能实现单纯的跳转


		 


