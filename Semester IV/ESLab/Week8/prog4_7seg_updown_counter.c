#include<LPC17XX.h>
#define FIRSTSEG  0<<23;
#define SECONDSEG  1<<23;
#define THIRDSEG  2<<23;
#define FOURTHSEG  3<<23;
unsigned int dig_1 = 0x00;
unsigned int dig_2 = 0x00;
unsigned int dig_3 = 0x00;
unsigned int dig_4 = 0x00;
unsigned long i;
unsigned int dig_count = 0, temp1 = 0x00, one_sec_flag = 0x00;
unsigned int array_dec[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned long int temp2 = 0x0;
void display(void)
{
	if(dig_count == 0x01)
	{
		temp1 = dig_1;
		LPC_GPIO1->FIOPIN = FIRSTSEG;
	}
	if(dig_count == 0x02)
	{
		temp1 = dig_2;
		LPC_GPIO1->FIOPIN = SECONDSEG;
	}
	if(dig_count == 0x03)
	{
		temp1 = dig_3;
		LPC_GPIO1->FIOPIN = THIRDSEG;
	}
	if(dig_count == 0x04)
	{
		temp1 = dig_4;
		LPC_GPIO1->FIOPIN = FOURTHSEG;
	}
	temp1 &= 0x0F;
	temp2 = array_dec[temp1];
	temp2<<=4;
	LPC_GPIO0->FIOPIN = temp2;
	for(i=0; i<1000; i++);
	LPC_GPIO0->FIOCLR = 0x00000FF0;
}
void delay()
{
	for(i=0; i<5000000; i++);
}
int main()
{
	LPC_GPIO0->FIODIR |=0xFF<<4;
	LPC_GPIO1->FIODIR |=15<<23;
	while(1)
	{	
		delay();
		dig_count +=1;
		if(dig_count == 0x05)
		{
			delay();
			dig_count = 0x01;
			one_sec_flag = 0xFF;
		}	
		if((LPC_GPIO2->FIOPIN & 1))
		{
			if(one_sec_flag == 0xFF)
			{
				one_sec_flag = 0x00;
				dig_1+=1;
				if(dig_1 == 0xA)
				{
					dig_1 = 0;
					dig_2+=1;
					if(dig_2 == 0xA)
					{
						dig_2=0;
						dig_3+=1;
						if(dig_3 == 0xA)
						{
							dig_3 = 0;
							dig_4+=1;
							if(dig_4==0xA)
							{
								dig_4 = 0;
							}
						}
					}
				}
			}	
		}
		else if(!(LPC_GPIO2->FIOPIN & 1))
		{
			if(one_sec_flag==0xFF)
			{
				one_sec_flag = 0x00;
				dig_1-=1;
				if(dig_1==0xFFFFFFFF)
				{
					dig_1=9;
					dig_2-=1;
					if(dig_2==0xFFFFFFFF)
					{
						dig_2=9;
						dig_3-=1;
						if(dig_3==0xFFFFFFFF)
						{
							dig_3 = 9;
							dig_4 -= 1;
							if(dig_4==0xFFFFFFFF)
							{
								dig_4 = 9;
							}
						}
					}
				}
			}
	}
			display();
}	
}