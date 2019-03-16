//#include<stdint.h>

#include"TM4C123GH6PM.h"
//typedef  enum  {PORT_PIN_IN,PORT_PIN_OUT}Port_PinDirectionType;
//char  t ;
void PortInit (uint8_t portIndex) // assume port [A:F] as [0:5]
	{
		if		 (portIndex==0){GPIOA->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X01;GPIOA->DATA|=0X3FC;GPIOA->DEN=0XFF;return;}
		else if(portIndex==1){GPIOB->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X02;GPIOB->DATA|=0X3FC;GPIOB->DEN=0XFF;return;}
		else if(portIndex==2){GPIOC->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X04;GPIOC->DATA|=0X3FC;GPIOC->DEN=0XFF;return;}
		else if(portIndex==3){GPIOD->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X08;GPIOD->DATA|=0X3FC;GPIOD->DEN=0XFF;return;}
		else if(portIndex==4){GPIOE->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X10;GPIOE->DATA|=0X0FC;GPIOE->DEN=0XFF;return;}
		else if(portIndex==5){GPIOF->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X20;GPIOF->DATA|=0X07C;GPIOF->DEN=0XFF;return;}
		else {return;}
	}
//	int main(void){
//		PortInit(0);
//		PortInit(1);
//		PortInit(2);
//		PortInit(3);
//		PortInit(4);
//		PortInit(5);
//		for(;;){ t=1;t=!t;}
//	}
//	void SystemInit(void){
//	SCB->CPACR |= 0x00F00000;
//	}
	