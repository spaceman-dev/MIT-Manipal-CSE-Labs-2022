#include <LPC17xx.h>
unsigned int i=4,j,c=1,k=0;
int main(void)
{
	LPC_PINCON->PINSEL0&=0xff0000ff;
	LPC_GPIO0->FIODIR |=0x00000ff0;
	while(1)
	{
		for(k=0;k<8;k++)
		{
			LPC_GPIO0->FIOPIN=c<<i;i++;
			for(j=0;j<100000;j++);
		}
		c=1;
		i=4;
	}	
}