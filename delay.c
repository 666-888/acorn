#include "define_function.h"
#include "define_data.h"
void delay()//�����ʱ
{
	int i;
	for(i=0;i<5000;i++)
	{
		asm("nop");
	}
}
void delay_10us()//��ʱ10us
{
	int j;
	for(j=0;j<1;j++)
	{
		asm("nop");
	}
}
