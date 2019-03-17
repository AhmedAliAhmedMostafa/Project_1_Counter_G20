#include"LCD_wait.h"
#include"portInit_V2.h"
typedef enum {STD_LOW,STD_HIGH}Dio_LevelType;
//char t;
void DIO_WritePort (uint8_t port_index,uint8_t port_mask,Dio_LevelType pins_level)
{
	
	Port_SetPinDirection(port_index,port_mask,PORT_PIN_OUT);
	if(pins_level==STD_HIGH)
		{
		if     (port_index==0){GPIOA->DATA|=port_mask;}
		else if(port_index==1){GPIOB->DATA|=port_mask;}
		else if(port_index==2){GPIOC->DATA|=port_mask;}
		else if(port_index==3){GPIOD->DATA|=port_mask;}
		else if(port_index==4){GPIOE->DATA|=port_mask;}
		else if(port_index==5){GPIOF->DATA|=port_mask;}
		}
	else if(pins_level==STD_LOW)
	{
		if     (port_index==0){GPIOA->DATA&=~port_mask;}
		else if(port_index==1){GPIOB->DATA&=~port_mask;}
		else if(port_index==2){GPIOC->DATA&=~port_mask;}
		else if(port_index==3){GPIOD->DATA&=~port_mask;}
		else if(port_index==4){GPIOE->DATA&=~port_mask;}
		else if(port_index==5){GPIOF->DATA&=~port_mask;}			
	}

}
// for testing purposes
//	int main(void){
//		
//		PortInit(0);
//		PortInit(1);
//		PortInit(2);
//		PortInit(3);
//		PortInit(4);
//		PortInit(5);
//		DIO_WritePort(0,0XF0,STD_HIGH);
//		DIO_WritePort(1,0X0F,STD_HIGH);
//		DIO_WritePort(2,0XAA,STD_HIGH);
//		DIO_WritePort(2,0XA0,STD_LOW);
//		DIO_WritePort(3,0X0F,STD_HIGH);
//		DIO_WritePort(3,0X0D,STD_LOW);
//		DIO_WritePort(4,0X83,STD_HIGH);
//		DIO_WritePort(4,0X03,STD_LOW);
//		DIO_WritePort(5,0XFF,STD_HIGH);
//	//GPIOA->DATA|=0XFF;
//	//GPIOB->DATA|=0X77;
////	DIO_WritePort(1,0X11,STD_LOW);	
////	DIO_WritePort(0,0XDD,STD_LOW);	
//	//DIO_FlipPort(0,0xF);
//	//DIO_FlipPort(1,0xF);
//		for(;;){ t=1;t=!t;}
//	}
//	void SystemInit(void){
//	SCB->CPACR |= 0x00F00000;
//	}
