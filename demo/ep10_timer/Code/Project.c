/**
Title:定时器应用
Authors:DDH-qiu
Date:2022-4-13
Abstract:定时器应用
**/
#include"reg51.h"
unsigned char count=0;
unsigned char num=0;
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7c,0x39,0x5e,0x79,0x71};//段码表

void init_timer()//定时器初始化
{
	TMOD=0x01;//0000 0001定时器T0模式1
	TH0=(65536-500000)/256;//高八位除以256，将初值>>8得到高八位
	TL0=(65535-50000)%256;
	ET0=1;//开启定时器T0的中断
	EA=1;//开启总中断
	TR0=1;//定时器启动在TCON中
}

//显示函数
void display()
{
	P2=s[num];
	if(num==16){num=0;}
}

void main()
{
	init_timer();
	while(1)//等待中断
	{
		display();
	}
}

void timer_isr() interrupt 1 //中断标号interupt，0表示外部中断，1表示定时器中断0，2表示外部中断1，3表示定时器中断1，4表示串口中断
{
	TH0=(65536-50000)/256;//将定时初值归初
	TL0=(65535-50000)%256;
	count++;//段码数组
	if (count==20)//定时循环定时1s
	{
		num++;
		count=0;
	}
	
}