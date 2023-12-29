#include "stm32f10x.h"
#include "Pwm.h"
int8_t i;
void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12| GPIO_Pin_13|GPIO_Pin_1|GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	PWM_Init();
}

void Motor_SetSpeed(int8_t Speed)
{
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		PWM_SetCompare4(Speed);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		GPIO_SetBits(GPIOB, GPIO_Pin_13);
		PWM_SetCompare4(-Speed);
	}
}

void Motor_SetSpeed1(int8_t Speed)
{
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_1);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
		PWM_SetCompare1(Speed);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);
		GPIO_SetBits(GPIOB, GPIO_Pin_0);
		PWM_SetCompare1(-Speed);
	}
}

void Forward(void)
{
 	  Motor_SetSpeed(50);
		Motor_SetSpeed1(-50);
}
void Backword(void)
{
   	Motor_SetSpeed(-50);
		Motor_SetSpeed1(50);
}

void Turnleft(void)
{
    Motor_SetSpeed(20);
		Motor_SetSpeed1(-100);
}
void Turnright(void)
{
    Motor_SetSpeed(100);
		Motor_SetSpeed1(-20);
}
void Stop(void)
{

    Motor_SetSpeed(0);
		Motor_SetSpeed1(0);

}
void Accelerate(void)

{
  	
 for(i=50;i<100;i++)
	{
	  Motor_SetSpeed(i);
		Motor_SetSpeed1(-i);

	}
}
void Accelerate1(void)

{
  	
 for(i=50;i<100;i++)
	{
	  Motor_SetSpeed(-i);
		Motor_SetSpeed1(i);

	}
}
