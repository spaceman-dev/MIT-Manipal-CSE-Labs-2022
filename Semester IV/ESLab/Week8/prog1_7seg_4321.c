#include<LPC17xx.h>
void delay();
void display();
unsigned int i=0;
unsigned int seven_seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x60,0x7D,0x07,0x7F,0x6F};
unsigned int dig_count = 0;
unsigned int dig_value[4]={4,3,2,1};
unsigned int dig_select[]={0<<23,1<<23,2<<23,3<<23};
int main(void)
{
	LPC_GPIO0->FIODIR = 0XFF<<4;
	LPC_GPIO1->FIODIR = 15<<23;
	while(1){
		delay();
		display();
		dig_count = dig_count + 1;
		if(dig_count == 4)
			dig_count = 0;
	}
}
void display(void)
{
	LPC_GPIO1->FIOPIN=dig_select[dig_count];
	LPC_GPIO0->FIOPIN=seven_seg[dig_value[dig_count]]<<4;
}
void delay()
{
	for(i=0;i<100000;i++);
}