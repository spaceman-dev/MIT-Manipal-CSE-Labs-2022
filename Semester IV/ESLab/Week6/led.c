#include <LPC17xx.h>
unsigned int i,j;
unsigned long led=0x00000010;
int main(void){
	LPC_PINCON->PINSEL0&=0xff0000ff;
	LPC_GPIO0->FIODIR |=0x00000ff0;
	while(1){
		led=0x00000010;
		for(i=1;i<9;i++)
		{
			LPC_GPIO0->FIOSET=led;
			for(j=0;j<10000;j++);
			led<<=1;
		}
		led=0x00000010;
		for(i=1;i<9;i++){
			LPC_GPIO0->FIOCLR=led;
			for(j=0;j<1000;j++);
			led<<=1;
		}
	}
}
