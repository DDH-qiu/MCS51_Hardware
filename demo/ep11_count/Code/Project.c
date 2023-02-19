/**
Title:计数器应用
Authors:DDH-qiu
Date:2022-4-13
Abstract:计数器-数码管三次加1
**/
#include"reg51.h"
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7c,0x39,0x5e,0x79,0x71};//段码表
unsigned char num;

void init_counter()
{
	TMOD=0x06;
	TH0=256-3;
	TL0=256-3;
	ET0=1;
	EA=1;
	TR0=1;	
}

void display()
{
	P2=s[num];
	if(num==10)
	{
		num=0;
	}
}

void main()
{
	init_counter();
	while(1)
	{
		display();
	}
}

void counter_isr() interrupt 1
{
	num++;
}
