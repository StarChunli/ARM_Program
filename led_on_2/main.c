#define		GPFCON	(*( volatile unsigned long*)0x56000050)
#define		GPFDAT	(*( volatile unsigned long*)0x56000054)

int main()
{
	GPFCON = 0X00000040;	//设置寄存控制器让GPF4为输出端口
	GPFDAT = 0X00000000; 	//GPF4输出为0,产生电流，让LED1亮
	return 0;
}