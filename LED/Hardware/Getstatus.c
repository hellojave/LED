#include "stm32f10x.h"
#include "Serial.h"
#include "LED.h"
#include "Motor.h"
#include "PWM.h"
#include "Delay.h"
uint8_t set;
void Getstatus_Init(void)
{
  Serial_Init();
  LED_Init();
	set=USART_ReceiveData(USART3);
  if(set=='A')
	{
	 LED1_ON();
	
	}
	else if(set=='B')
	{
	
	  LED1_OFF();
	}
}
