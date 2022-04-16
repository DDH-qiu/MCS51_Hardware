/**
Title:
Authors:DDH-qiu
Date:2022-
Abstract:
**/
#include"reg51.h"
sbit start=P3^0;
sbit EOC=P3^1;
sbit OE=P3^2;
sbit RS=P3^3;
sbit RW=P3^4;
sbit E=P3^5;
unsigned int vol=0;
unsigned char t[]={"0123456789"};
unsigned char s[]={"VOLTAGE:"};

void delay(unsigned int n)
{
	unsigned char i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}

//对ADC0808的初始化
void adc()
{
	start=0;
	start=1;
	delay(5);
	start=0;
	while(EOC!=1);
	OE=1;
	vol=P2;
	OE=0;
}

//写指令码
void writecom(unsigned char com)
{
	RS=0;
	RW=0;
	E=0;
	P1=com;
	delay(1);
	E=1;
	E=0;
}

//写数据
void writedat(unsigned char dat)
{
	RS=1;
	RW=0;
	E=0;
	P1=dat;
	delay(1);
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


//电压显示功能
void display()
{
	int i=0;
	unsigned char temp0=0,temp1=0,temp2=0;

	//对电压值进行规划
	vol=vol*100/51;
	temp0=vol/100;
	temp1=(vol%100)/10;
	temp2=vol%10;

	//第一行显示
	writecom(0x80);
	for(i=0;i<8;i++)
	{
		writedat(s[i]);
		delay(5);
	}

	//第二行显示
	writecom(0x80+0x40);
	delay(5);
	writedat(t[temp0]);
	delay(5);
	writedat('.');
	delay(5);
	writedat(t[temp1]);
	delay(5);
	writedat(t[temp2]);
	delay(5);	
	writedat('V');
	delay(5);
}

void main()
{
	init_lcd();		
	while(1)
	{	
		display();	
		adc();			
	}
}