#include "a6.h"
#include "delay.h"
unsigned char  AT[2]="AT";
unsigned char  a[10]="AT+CGATT=1";
unsigned char  b[12]="AT+CGACT=1,1";
unsigned char  c[33]="AT+CIPSTART=TCP,183.230.40.39,876";	
unsigned char  d[10]="AT+CIPSEND";
unsigned char  e[52]={0x1A};
unsigned char  f[11]="AT+CIPCLOSE";
void A6_INIT(void)
{

	int t;
	USART1->SR&=~(1<<7);
	delay_a6(15000);
	for(t=0;t<10;t++)
		{
			USART_SendData(USART1,a[t]);
			while((USART1->SR&0X40)==0);//???????
		}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(50);
		for(t=0;t<10;t++)
		{
			USART_SendData(USART1,a[t]);
			while((USART1->SR&0X40)==0);//???????
		}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(2000);
		for(t=0;t<12;t++)
	{
		USART_SendData(USART1,b[t]);
		while((USART1->SR&0X40)==0);//???????
	}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(1000);
	for(t=0;t<33;t++)
	{
		USART_SendData(USART1,c[t]);
		while((USART1->SR&0X40)==0);//???????
	}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(3000);
	for(t=0;t<10;t++)
	{
		USART_SendData(USART1,d[t]);
		while((USART1->SR&0X40)==0);//???????
	}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(1000);
		for(t=0;t<52;t++)
	{
		USART_SendData(USART1,e[t]);
		while((USART1->SR&0X40)==0);//???????
	}
		USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(3000);
	
}

void A6_PING(void)
{
int t;
	for(t=0;t<2;t++)
	{
		USART_SendData(USART1,AT[t]);
		while((USART1->SR&0X40)==0);//???????
	}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(50);
	for(t=0;t<11;t++)
	{
		USART_SendData(USART1,f[t]);
		while((USART1->SR&0X40)==0);//???????
	}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(1000);
	for(t=0;t<33;t++)
	{
		USART_SendData(USART1,c[t]);
		while((USART1->SR&0X40)==0);//???????
	}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(3000);
	for(t=0;t<10;t++)
	{
		USART_SendData(USART1,d[t]);
		while((USART1->SR&0X40)==0);//???????
	}
	USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(1000);
		for(t=0;t<52;t++)
	{
		USART_SendData(USART1,e[t]);
		while((USART1->SR&0X40)==0);//???????
	}
		USART1->DR=0x0d;
	while((USART1->SR&0X40)==0);
	USART1->DR=0x0a;
	while((USART1->SR&0X40)==0);
	delay_a6(3000);
}

void delay_a6(u16 time)
{    
	 u16 i=0;  
	 while(time--)
	 {
			i=12000; 
			while(i--) ;    
	 }
}
