/**
Title:外部中断
Authors:DDH-qiu
Date:2022-4-14
Abstract:外部中断——数码管
**/
#include"reg51.h"
sbit ex=P3^2;
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7c,0x39,0x5e,0x79,0x71};//段码表
unsigned char num=0;

//外部中断初始化
void init_tex()
{
	IT0=1;//下降沿触发，外部中断标志是IE0
	EX0=1;//外部中断0允许
	EA=1;//中断总允许
	ex=1;//先将P3.2拉高,下降沿触发，否则就一直是低电平检测不到下降沿
}

//显示函数
void display()
{
	P2=s[num];
	if(num==16)
	{
		num=0;
	}
}


void main()
{
	init_tex();
	while(1)
	{
		display();
	}
}

//中断服务子程序
void ex_isr() interrupt 0
{
	num++;//当按键按下的时候num加1，数码管段码表加1
}