#include <stm32f10x.h>

void delay_ms(uint16_t t)

{
	volatile unsigned long l = 0;
	for(uint16_t i=0; i <t; i++)
	{
		for(l=0; l<6000; l++)
		{}
	}
}
int main(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;
	GPIOF->CRL   &= (0x00FFFFFF);
	GPIOF->CRH   &= (0xFFFFFF00);
	GPIOF->CRL   |= 0x33000000;
	GPIOF->CRH   |= 0x00000033;
	
	while(1)
	{
		int n=0;
		for(n=6; n<=9; n++)
		{
			GPIOF->ODR |= (1<<n);
			delay_ms(500);
		}
		for(n=9; n>=6 ; n--)
		{
			GPIOF->ODR &=~(1<<n);
	
			delay_ms(500);
		}

	}
}