#include <LPC17xx.h>
unsigned int i,j,c=0;
int main(void)
{
	LPC_PINCON->PINSEL0 &= 0XFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0X0;
	while(1)
	{
		c++;
		LPC_GPIO0->FIOPIN = c<<4;
		for(i = 0 ; i < 100000 ; i++);
		if(c == 0XFF)
			c = 0;
	}
}