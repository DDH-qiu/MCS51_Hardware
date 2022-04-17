/**
Title:PWM控制直流电机
Authors:DDH-qiu
Date:2022-4-17
Abstract:PWM控制直流电机的转速
**/
#include"reg51.h"
#define uint unsigned int 
sbit IN1=P2^0;
sbit IN2=P2^1;
sbit E=P2^2;
unsigned char valueh[]={0xf8,0xe0};
unsigned char valuel[]={0x30,0xc0};

//延时函数
void delay(uint n)
{
	uint i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}

//电机驱动函数
void motor()
{
	IN1=0;
	// IN2=1;
	// delay(50);
	// IN2=0;
	// delay(50);
	E=1;
}

//定时器初始化
void init_timer()
{
	TMOD=0x01;
	TH0=(65536-10000)/256;
	TL0=(65536-10000)%256;
	ET0=1;
	EA=1;
	TR0=1;
	IN2=0;
}

void main()
{
	init_timer();
	while(1)
	{
		motor();
	}
}

//定时中断
void timer_isr() interrupt 1
{
	uint count;
	TH0=valueh[count];//(65536-value[count])/256;
	TL0=valuel[count];//(65536-value[count])%256;
	IN2=~IN2;
	count++;
	if(count==2)
	{
		count=0;
	}
}