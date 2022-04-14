#include"Delayus.h"
#include"intrins.h"

void Delayus(unsigned char xus)
{
    while(xus)
    {
        unsigned char i;

	    _nop_();
	    i = 25;
	    while (--i);
        xus--;
    }
}