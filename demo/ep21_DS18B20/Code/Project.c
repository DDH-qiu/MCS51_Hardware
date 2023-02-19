/**
Title:DS18B20芯片
Authors:DDH-qiu
Date:2022-4-17
Abstract:温度测量
**/
#include"reg51.h"
unsigned int readtemp=0;
unsigned char str[]={"0123456789"};
unsigned char s[]={"Temperature:"};
sbit RS=P3^0;
sbit RW=P3^1;
sbit E=P3^2;
sbit DQ=P3^3;

//延时
void delay_18B20(unsigned int i)
{
	for(i;i>0;i--);
}

//初始化DS18B20
void Init_DS18B20(void)
{
	unsigned char x=0;
	DQ=1;
	delay_18B20(8);
	DQ=0;
	delay_18B20(80);
	DQ=1;
	delay_18B20(14);
	x=DQ;
	delay_18B20(20);
}
//写时序
void WriteOneChar(unsigned char dat)
{
	unsigned char i=0;
	for(i=8;i>0;i--)
	{
		DQ=0;
		DQ=dat&0x01;
		if(DQ)
		{
			delay_18B20(1);
			DQ=1;
		}
		else
		{
			delay_18B20(5);
			DQ=1;
		}
		dat>>=1;
	}
}

//读时序
unsigned char ReadOneChar(void)
{
	unsigned char i=0;
	unsigned char dat=0;
	for(i=8;i>0;i--)
	{
		DQ=0;
		dat>>=1;
		DQ=1;
		if(DQ)
		dat |=0x80;
		delay_18B20(4);
	}
	return(dat);
}
//读温度
unsigned char ReadTemperature(void)
{
	unsigned int temp=0;
	unsigned char a=0,b=0;
	Init_DS18B20();
	WriteOneChar(0xcc);
	WriteOneChar(0x44);
	delay_18B20(100);
	Init_DS18B20();
	WriteOneChar(0xcc);
	WriteOneChar(0xbe);
	delay_18B20(100);
	a=ReadOneChar();
	b=ReadOneChar();
	temp=((b*256+a)>>4);
	return(temp);
}

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
	P1=com;
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
	P1=dat;
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
//显示函数
void display()
{
	unsigned char temp0=0,temp1=0,temp2=0,i=0;
	temp0=readtemp/100;
	temp1=(readtemp%100)/10;
	temp2=readtemp%10;

	writecom(0x80);
	while (s[i]!='\0')
	{
		writedat(s[i]);
		i++;
	}
	
	writecom(0x80+0x40);
	delay(5);
	writedat(str[temp0]);
	delay(5);
	writedat(str[temp1]);
	delay(5);
	writedat(str[temp2]);
	delay(5);
	writedat(0xdf);
	delay(5);
	writedat('C');
	delay(5);
}

void main()
{
	init_lcd();
	while(1)
	{
		readtemp=ReadTemperature();
		display();
	}
}
