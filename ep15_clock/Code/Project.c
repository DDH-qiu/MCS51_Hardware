/**
Title:数字时钟
Authors:DDH-qiu
Date:2022-4-15
Abstract:51单片机实现数字时钟
**/
#include"reg51.h"
sbit RS=P3^0;
sbit RW=P3^1;
sbit E=P3^2;
unsigned char i=0;
unsigned char count;
unsigned int hour=0,min=0,sec=0;
unsigned char str[]={"0123456789"};

//延时子程序
void delay(unsigned int t)
{
	unsigned int i=0,j=0;
	for(i=0;i<t;i++)
	{
		for(j=0;j<120;j++);
	}
}

//写指令码
void writecom(unsigned char com)
{
	RS=0;
	RW=0;
	E=0;
	P2=com;
	delay(5);
	E=1;
	E=0;
}

//写数据
void writedat(unsigned char dat)
{
	RS=1;
	RW=0;
	E=0;
	P2=dat;
	delay(5);
	E=1;
	E=0;
}

//lcd初始化设置
void init_lcd()
{
	writecom(0x38);//设置16x2显示，5x7点阵，8位数据接口
	writecom(0x0c);//设置开显示，不显示光标
	writecom(0x06);//写一个字符后地址指针加1
	writecom(0x01);//显示清0，数据指针清0
}

//显示函数，显示时间
void display()
{
	unsigned char temp0=0,temp1=0,temp2=0,temp3=0,temp4=0,temp5=0;//拆分字符做准备
	//拆字
	temp0=hour/10;
	temp1=hour%10;
	temp2=min/10;
	temp3=min%10;
	temp4=sec/10;
	temp5=sec%10;
	writecom(0x80);
	delay(5);
	writedat(str[temp0]);
	delay(5);
	writedat(str[temp1]);
	delay(5);
	writedat(':');
	delay(5);
	writedat(str[temp2]);
	delay(5);
	writedat(str[temp3]);
	delay(5);
	writedat(':');
	delay(5);
	writedat(str[temp4]);
	delay(5);
	writedat(str[temp5]);
	delay(5);
}

//定时器初始化
void init_timer()
{
	TMOD=0x01;
	TH0=(65536-50000)/256;//50MS
	TL0=(65536-50000)%256;
	ET0=1;
	EA=1;
	TR0=1;
}

void main()
{
	init_lcd();
	init_timer();
	while(1)
	{
		display();
	}
}


//定时器中断服务
void timer0_isr() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	count++;
	if(count==20)//50毫秒循环20次
	{
		sec=sec+1;
		count=0;
	}
	if(sec==60)
	{
		min=min+1;
		sec=0;//秒
	}
	if(min==60)
	{
		hour=hour+1;
		min=0;//分
	}
	if(hour==24)
	{
		hour=0;//时
	}		
}
