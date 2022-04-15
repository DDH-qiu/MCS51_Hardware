/**
Title:LCD1602液晶屏显示
Authors:DDH-qiu
Date:2022-4-15
Abstract:LCD1602液晶屏显示实践
**/
#include"reg51.h"
sbit RS=P3^0;
sbit RW=P3^1;
sbit E=P3^2;
unsigned char i=0;
unsigned char str[]={"HELLO WORLD"};

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

//显示函数,zey是狗，玩笑啦zey是我宝贝😘😘
void display()
{
	writecom(0x80);//第一行显示
	delay(50);
	writedat('z');
	delay(5);
	writedat('e');
	delay(5);
	writedat('y');
	delay(5);
	writedat('s');
	delay(5);
	writedat('g');
	delay(5);
	writecom(0x80+0X40+3);//第二行显示中间
	while(str[i]!='\0')
	{
		writedat(str[i]);
		delay(5);
		i++;
	}
	delay(5);

}

void main()
{
	init_lcd();
	while(1)
	{
		display();
	}
}
