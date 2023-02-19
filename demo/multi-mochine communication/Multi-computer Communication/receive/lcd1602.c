#include"lcd1602.h"

void delay(unsigned int t)
{
	unsigned int i=0,j=0;
	for(i=0;i<t;i++)
	{
		for(j=0;j<120;j++);
	}
}

void writedat(unsigned char dat)
{
	RS=1;
	RW=0;
	E=0;
	E=1;
	P2=dat;
	delay(5);
	E=0;
}

void writecom(unsigned char com)
{
	RS=0;
	RW=0;
	E=0;
	E=1;
	P2=com;
	delay(5);
	E=0;
}
	
void initlcd()
{
	writecom(0x38);
	writecom(0x0c);
	writecom(0x06);
	writecom(0x01);
}