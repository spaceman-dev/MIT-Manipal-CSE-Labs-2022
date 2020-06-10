#include <LPC17xx.h>
unsigned int i,l,j,c=0;
int main(void)
{
	LPC_PINCON->PINSEL0 &= 0XFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0X0;
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12)
			c--;
		else
			c++;
		if(c==-1)
			c=0xFF;
		LPC_GPIO0->FIOPIN=c<<4;
		if(c == 0X100)
			c=0X00;
		for(l = 1; l < 10000 ; l++);
	}
}