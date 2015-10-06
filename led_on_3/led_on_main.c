#define		GPFCON	(*( volatile unsigned long*)0x56000050)
#define		GPFDAT	(*( volatile unsigned long*)0x56000054)

#define		GPF3_out	(1 << (3*2))
#define		GPF4_out	(1 << (4*2))
#define		GPF5_out	(1 << (5*2))
#define		GPF6_out	(1 << (6*2))

void wait(volatile unsigned long dly)
{
	for(;dly > 0;dly--);
}
int main(void)
{
	unsigned long i = 0;
	GPFCON = GPF3_out|GPF4_out|GPF5_out|GPF6_out; //将LED1,2,3,4对应的GPF3/4/5/6三个引脚设为输出
	
	while(1){
		wait(70000);
		/*GPFDAT = ~(i << 4);
		if(++i == 8)
			i = 0;
		GPFDAT == i;*/
		GPFDAT = 0x0000000;
		wait(40000);
		i++;
		if(i<3){
			GPFDAT = (8+i) << 3;
		}
		else{
			if(i<8){
				GPFDAT = (16+i) << 3;
			}else{
				i = 1;
				GPFDAT == i;
			}
		}
	}
	
	return 0;
}
