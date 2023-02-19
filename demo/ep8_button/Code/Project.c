/**
Title:独立按键
Authors:DDH-qiu
Date:2022-4-12
Abstract:独立按键控制数码管的变化
**/
#include"reg51.h"
sbit key0=P1^0;
unsigned char num=0;
unsigned char flag=0;
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


//延时子函数ms级别
// void delay(unsigned int n)
// {
// 	unsigned int i=0,j=0;
// 	for(i=0;i<n;i++)
// 	{
// 		for(j=0;j<120;j++);
// 	}
// }


//按键子函数
void key()
{
	//延时消抖，只要按下就一直加一
	// if(key0==0)//检测按键是否按下
	// {
	// 	delay(500);//按键消抖
	// 	num++;
	// }

	//通过标志位flag来判断按键是否按下，按一次只加一
	if(key0==0&&flag==0)//两个判定条件
	{
		flag=1;
	}
	if(flag==1&&key0==1)
	{
		num++;
		flag=0;//结束时清除flag标志位
	}
}


//数码管子函数
void seg()
{
	P2=s[num];
	if(num==10)//当num计数到10时清零
	{
		num=0;
	}
	
}



void main()
{
	while(1)
	{
		//调用两个函数子程序
		key();
		seg();
	}
}

