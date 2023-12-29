#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "Getstatus.h"
#include "LED.h"
uint8_t RxData;
int a=1;
int main(void)
{
	
  LED_Init();
	Serial_Init();

	while (1)
	{
    Getstatus_Init();
  }
}

