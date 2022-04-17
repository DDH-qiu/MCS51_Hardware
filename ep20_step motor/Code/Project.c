/**
Title:控制步进电机
Authors:DDH-qiu
Date:2022-4-17
Abstract:控制步进电机的运动
**/
#include"reg51.h"
#define uchar unsigned char
uchar st[]={0x09,0x08,0x0c,0x04,0x06,0x02,0x03,0x01};//八步法控制步进电机的控制信号
uchar count=0,num=0;

void delay(unsigned int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}

//步进电机函数
void stepper()
{
	int i=0;
	for(i=7;i>0;i-- )
	{
		P2=st[i];
		delay(10);
	}

}

//定时器初始化
void init_timer()
{
	TMOD=0X01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	ET0=1;
	EA=1;
	TR0=1;
}

void main()
{
	init_timer();
	while(1)
	{
		// stepper();
	}
}


//定时器中断
void timer_isr() interrupt 1
{
	TH0=0x3c;
	T0=0xb0;
	count++;
	if(count==20)


	{
		P2=st[num++];
		if(num==8)
		{
			num=0;
		}
		count=0;
	}
}