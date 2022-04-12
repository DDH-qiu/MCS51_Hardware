/**
Title:静态数码管
Authors:DDH-qiu
Date:2022-4-1
Abstract:一位输出静态数码管
**/

#include"reg51.h"
unsigned char s[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//共阴0-9

void delay(unsigned int n)
{
	unsigned int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}

void seg()
{
	int i=0;
	for(i=0;i<10;i++)
	{
		P2=s[i];//取出字码
		P1=~s[i];
		delay(1000);
	}
}

void main()
{
	while(1)
	{
		seg();
	}
}
//数码管有共阴极和共阳极接法两种
//数码管静态显示