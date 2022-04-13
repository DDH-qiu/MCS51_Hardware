/**
Title:矩阵键盘控制
Authors:DDH-qiu
Date:2022-4-13
Abstract:矩阵键盘控制数码管
**/

// H3 H2 H1 H0 L3 L2 L1 L0
//行扫描和列扫描


#include"reg51.h"
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7c,0x39,0x5e,0x79,0x71};//0-f段码表
unsigned char num=99;

//延时子程序
void delay(unsigned int n)
{
	unsigned int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}

//按键检测
void key_scan()
{
	unsigned char temp0=0,temp1=0,temp=0;
	P1=0xf0;
	if(P1!=0xf0)//检测按键是否被按下
	{
		//行扫描
		delay(20);//延时消抖
		temp0=P1;
		P1=0x0f;
		if(P1!=0x0f)//检测按键
		{
			//列扫描
			temp1=P1;
		}
	}
	temp=temp0+temp1;
	if(temp==0xEE){num=0;}
	if(temp==0xED){num=1;}
	if(temp==0xEB){num=2;}
	if(temp==0xE7){num=3;}
	if(temp==0xDE){num=4;}
	if(temp==0xDD){num=5;}
	if(temp==0xDB){num=6;}
	if(temp==0xD7){num=7;}
	if(temp==0xBE){num=8;}
	if(temp==0xBD){num=9;}
	if(temp==0xBB){num=10;}
	if(temp==0xB7){num=11;}
	if(temp==0x7E){num=12;}
	if(temp==0x7D){num=13;}
	if(temp==0x7B){num=14;}
	if(temp==0x77){num=15;}
}

//数码管显示
void display()
{
	P2=s[num];
}


void main()
{
	while(1)
	{
		key_scan();
		display();
	}
}
