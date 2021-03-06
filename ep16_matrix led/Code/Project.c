/**
Title:LED点阵屏
Authors:DDH-qiu
Date:2022-4-16
Abstract:点阵屏按键输出0-9
**/
#include"reg51.h"
unsigned char tab[]={
	0x00,0x7e,0xff,0xc3,0xc3,0xff,0x7e,0x00,
	0x00,0x00,0x43,0xff,0xff,0x03,0x00,0x00,
	0x00,0x63,0xc7,0xcf,0xdb,0xf3,0x63,0x00,
	0x00,0x42,0xdb,0xdb,0xdb,0xff,0x66,0x00,
	0x00,0x3e,0x46,0xff,0xff,0x06,0x06,0x00,
	0x00,0xf6,0xf7,0xd3,0xd3,0xdf,0xde,0x00,
	0x00,0x7e,0xef,0xdb,0xdb,0xdf,0x4e,0x00,
	0x00,0xc0,0xc0,0xc7,0xff,0xf8,0xc0,0x00,
	0x00,0xff,0xff,0xdb,0xdb,0xff,0xff,0x00,
	0x00,0x72,0xfb,0xdb,0xdb,0xff,0x7e,0x00};
unsigned char row[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
sbit key0=P1^0;
unsigned char num,flag;

//按键函数
void key()
{
	if(flag==0&&key0==0)
	{
		flag=1;
	}
	if(flag==1&&key0==1)
	{
		num++;
		flag=0;
	}
	if(num==10)
	{
		num=0;
	}
}

//点阵函数
void matrix()
{
	int i=0;
	// for(i=0;i<8;i++)
	// {
	// 	P2=~row[i];
	// 	P3=tab[i];
	// }
	for(i=8*num;i<8*(num+1);i++)
	{
		P2=~row[i-8*num];
		P3=tab[i];
	}

}

void main()
{
	while(1)
	{
		matrix();
		key();
	}
}
