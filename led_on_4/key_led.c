#define GPFCON      (*(volatile unsigned long *)0x56000050)
#define GPFDAT      (*(volatile unsigned long *)0x56000054)

#define GPBCON      (*(volatile unsigned long *)0x56000010)
#define GPBDAT      (*(volatile unsigned long *)0x56000014)

/*
 * LED1,LED2,LED3对应GPF4、GPF5、GPF6
 * 定义输出位
 */
#define	GPF4_out	(1<<(4*2)) 
#define	GPF5_out	(1<<(5*2))
#define	GPF6_out	(1<<(6*2))

//定义屏蔽msk，不影响其他位，只对操作位进行操作
#define	GPF4_msk	(3<<(4*2))
#define	GPF5_msk	(3<<(5*2))
#define	GPF6_msk	(3<<(6*2))

/*
 * S6,S8,S2对应GPF0、GPF2、GPB5
 * 定义输入位
 */
#define GPF0_in     (0<<(0*2)) 
#define GPF2_in     (0<<(2*2))
#define GPB7_in     (0<<(7*2))

#define GPF0_msk    (3<<(0*2))
#define GPF2_msk    (3<<(2*2))
#define GPB7_msk    (3<<(7*2))

int main()
{
        unsigned long dwDat;
        // LED1,LED2,LED3对应的3根引脚设为输出
        GPFCON &= ~(GPF4_msk | GPF5_msk | GPF6_msk); //按位操作，位与清零 00
        GPFCON |= GPF4_out | GPF5_out | GPF6_out;    //位或，01,输出
        
        // S6,S8对应的2根引脚设为输入
        GPFCON &= ~(GPF0_msk | GPF2_msk);
        GPFCON |= GPF0_in | GPF2_in; // 00 输入

        // S7对应的引脚设为输入
        GPBCON &= ~GPB7_msk;
        GPBCON |= GPB7_in;

        while(1){
            //若Kn为0(表示按下)，则令LEDn为0(表示点亮)
            dwDat = GPFDAT;             // 读取GPF管脚电平状态
        
            if (dwDat & (1<<0))        // S6没有按下
                GPFDAT |= (1<<4);       // LED1熄灭
            else    
                GPFDAT &= ~(1<<4);      // LED1点亮
                
            if (dwDat & (1<<2))         // S8没有按下
                GPFDAT |= (1<<5);       // LED2熄灭
            else    
                GPFDAT &= ~(1<<5);      // LED2点亮
    
            dwDat = GPBDAT;             // 读取GPG管脚电平状态
            
            if (dwDat & (1<<7))         // S7没有按下
                GPFDAT |= (1<<6);       // LED3熄灭
           else    
               GPFDAT &= ~(1<<6);      // LED3点亮
    }

    return 0;
}
