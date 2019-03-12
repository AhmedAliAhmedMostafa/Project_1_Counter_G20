
void Push_button_init (void){
#include "stdint.h" 

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










