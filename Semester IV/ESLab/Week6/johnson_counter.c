#include <LPC17xx.h>
unsigned int i,j;
unsigned long LED = 0X00000010;
int main(void)
{
	LPC_PINCON->PINSEL0&=0xff0000ff;
	LPC_GPIO0->FIODIR |=0x00000ff0;
	while(1)
	{
		LED = 0x00000010;
		for(i = 0 ; i < 9 ; i = i +2)
		{
			LPC_GPIO0->FIOSET=LED;
			for(j = 0 ; j < 1000 ; j++);
			LED<<=1;
		}
		LED = 0x00000010;
		for(i = 1 ; i < 9 ; i++)
		{
			LPC_GPIO0->FIOCLR=LED;
			for(j = 0 ; j < 1000 ; j++);
			LED<<=1;
		}
	}
}
