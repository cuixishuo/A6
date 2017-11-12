#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "a6.h"

 int main(void)
 {	
		int len,t;
		int a;
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
		delay_init();	    //��ʱ������ʼ��	  
		uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
		LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
		LED0=0;
		A6_INIT();
		LED0=1;	
		TIM3_Int_Init(4999,7199);//10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms 
	 while(1)
	 {
		 
	 		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3FFF;//�õ��˴ν��յ������ݳ���
			for(t=0;t<len;t++)
			{ 	
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//�ȴ����ͽ���
			}
			USART1->DR=USART_RX_BUF[55];
			printf("\r\n\r\n");//���뻻��
			a=(int)USART_RX_BUF[55];
			printf("%d",a);
			USART_RX_STA=0;
		}
			switch(a)
			{
				case(48):{LED1=0;break;}
				case(49):{LED1=1;break;}
//				case(50):{LED1=1;break;}
//				case(51):{LED1=0;break;}

			}		
			
	 }
 }








