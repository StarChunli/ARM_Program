#define GPFCON      (*(volatile unsigned long *)0x56000050)
#define GPFDAT      (*(volatile unsigned long *)0x56000054)

#define GPBCON      (*(volatile unsigned long *)0x56000010)
#define GPBDAT      (*(volatile unsigned long *)0x56000014)

/*
 * LED1,LED2,LED3��ӦGPF4��GPF5��GPF6
 * �������λ
 */
#define	GPF4_out	(1<<(4*2)) 
#define	GPF5_out	(1<<(5*2))
#define	GPF6_out	(1<<(6*2))

//��������msk����Ӱ������λ��ֻ�Բ���λ���в���
#define	GPF4_msk	(3<<(4*2))
#define	GPF5_msk	(3<<(5*2))
#define	GPF6_msk	(3<<(6*2))

/*
 * S6,S8,S2��ӦGPF0��GPF2��GPB5
 * ��������λ
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
        // LED1,LED2,LED3��Ӧ��3��������Ϊ���
        GPFCON &= ~(GPF4_msk | GPF5_msk | GPF6_msk); //��λ������λ������ 00
        GPFCON |= GPF4_out | GPF5_out | GPF6_out;    //λ��01,���
        
        // S6,S8��Ӧ��2��������Ϊ����
        GPFCON &= ~(GPF0_msk | GPF2_msk);
        GPFCON |= GPF0_in | GPF2_in; // 00 ����

        // S7��Ӧ��������Ϊ����
        GPBCON &= ~GPB7_msk;
        GPBCON |= GPB7_in;

        while(1){
            //��KnΪ0(��ʾ����)������LEDnΪ0(��ʾ����)
            dwDat = GPFDAT;             // ��ȡGPF�ܽŵ�ƽ״̬
        
            if (dwDat & (1<<0))        // S6û�а���
                GPFDAT |= (1<<4);       // LED1Ϩ��
            else    
                GPFDAT &= ~(1<<4);      // LED1����
                
            if (dwDat & (1<<2))         // S8û�а���
                GPFDAT |= (1<<5);       // LED2Ϩ��
            else    
                GPFDAT &= ~(1<<5);      // LED2����
    
            dwDat = GPBDAT;             // ��ȡGPG�ܽŵ�ƽ״̬
            
            if (dwDat & (1<<7))         // S7û�а���
                GPFDAT |= (1<<6);       // LED3Ϩ��
           else    
               GPFDAT &= ~(1<<6);      // LED3����
    }

    return 0;
}
