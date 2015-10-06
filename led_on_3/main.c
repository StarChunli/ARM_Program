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
		wait(50000);
		++i;
		if(i=0){
			GPFDAT = 0X00000000;
		}else{
			if(i%2 != 0){
				GPFDAT = 0X00000000;
			}else{
				if(i == 8){
					i = 1;
					GPFDAT == i;
				}else{
					GPFDAT = 5 << 3;
				}
				
			}
		}
		
	}
	
	return 0;
}
