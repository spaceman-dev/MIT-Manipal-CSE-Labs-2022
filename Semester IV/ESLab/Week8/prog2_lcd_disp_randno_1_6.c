#include<LPC17xx.h>
#include <math.h>
#include <stdlib.h> 
#include"lcd_disp.h"
unsigned char dice[6]={'1','2','3','4','5','6'};
unsigned char Msg[]="Roll Your Dice:";
int main()
{
	int num=0;
	lcd_init();
	temp1=0x80;
	lcd_com(800);
	lcd_puts(&Msg[0]);
	temp1=0xC0;
	lcd_com(800);
		if(!(LPC_GPIO2->FIOPIN & 1<<12))
		{
			num = (rand() % (6));
			lcd_puts(&dice[num]);
		}
}