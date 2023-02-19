#include"Delayms.h"
#include"intrins.h"

void Delayms(unsigned char xms)		//@11.0592MHz
{
	unsigned char i, j;
	_nop_();
	_nop_();
	_nop_();
	while(xms)
	{
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}

}




