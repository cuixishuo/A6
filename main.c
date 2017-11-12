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
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
		delay_init();	    //延时函数初始化	  
		uart_init(115200);	 //串口初始化为115200
		LED_Init();		  	//初始化与LED连接的硬件接口
		LED0=0;
		A6_INIT();
		LED0=1;	
		TIM3_Int_Init(4999,7199);//10Khz的计数频率，计数到5000为500ms 
	 while(1)
	 {
		 
	 		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3FFF;//得到此次接收到的数据长度
			for(t=0;t<len;t++)
			{ 	
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//等待发送结束
			}
			USART1->DR=USART_RX_BUF[55];
			printf("\r\n\r\n");//插入换行
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








