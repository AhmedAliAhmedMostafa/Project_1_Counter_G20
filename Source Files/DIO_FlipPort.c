#include"LCD_wait.h"
#include"portInit_V2.h"
void DIO_FlipPort(uint8_t port_index,uint8_t port_mask)
{
		if     (port_index==0){GPIOA->DATA^=port_mask;}
		else if(port_index==1){GPIOB->DATA^=port_mask;}
		else if(port_index==2){GPIOC->DATA^=port_mask;}
		else if(port_index==3){GPIOD->DATA^=port_mask;}
		else if(port_index==4){GPIOE->DATA^=port_mask;}
		else if(port_index==5){GPIOF->DATA^=port_mask;}
}
//int main(void)
//{
//	GPIOA->DATA|=0XFF;
//	GPIOB->DATA|=0X77;
//	DIO_FlipPort(0,0xF);
//	DIO_FlipPort(1,0xF);
//}
//void SystemInit(void){
//	SCB->CPACR |= 0x00F00000;
//	}
	