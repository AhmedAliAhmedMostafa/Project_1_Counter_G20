#include "stdint.h" 
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define GPIO_PORTF_LOCK_R       (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile uint32_t *)0x40025524))
#define GPIO_PORTF_DIR_R        (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_AMSEL_R      (*((volatile uint32_t *)0x40025528))
#define GPIO_PORTF_DEN_R        (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_AFSEL_R      (*((volatile uint32_t *)0x40025420))
#define GPIO_PORTF_PCTL_R       (*((volatile uint32_t *)0x4002552C))
#define GPIO_PORTF_PUR_R        (*((volatile uint32_t *)0x40025510))
#define GPIO_PORTF_DATA_R       (*((volatile uint32_t *)0x400253FC))

void Push_button_init (void){

uint32_t delay ; 
SYSCTL_RCGCGPIO_R  |= 0x20 ;
delay = 1 ; //dummy var 
GPIO_PORTF_LOCK_R =0x4C4F434B ;
GPIO_PORTF_CR_R  |= 0x11 ;
GPIO_PORTF_AMSEL_R = 0 ;
GPIO_PORTF_DEN_R  |= 0x11 ;
GPIO_PORTF_AFSEL_R = 0 ;
GPIO_PORTF_PCTL_R  = 0 ;
GPIO_PORTF_PUR_R = 0x11 ;
GPIO_PORTF_DIR_R |= 0x11 ;


}
