/**
Title:DS1302芯片
Authors:DDH-qiu
Date:2022-4-17
Abstract:时钟芯片计时
**/
#include"reg51.h"

void main()
{
	init_lcd();
	WL302(0x8e,0);//打开写保护
	WL302(0x8c,0x20);//写入年，BCD码
	WL302(0x8a,0x01);//写入星期
	WL302(0x88,0x04);//写入月
	WL302(0x86,0x27);//写入日
	WL302(0x84,0x12);//写入小时
	WL302(0x82,0x15);//写入分
	WL302(0x80,0x30);//写入秒
	WL302(0x8e,0x80);//关闭写保护
	while(1)
	{
		diaplay();
	}
}