#include "stm32f10x.h"
void PWM_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM1);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	
	  TIM_Cmd(TIM1, ENABLE);
		TIM_CtrlPWMOutputs(TIM1,ENABLE);        //MOE �����ʹ��,�߼���ʱ�����뿪�����
		
		
//	GPIO_InitTypeDef GPIO_InitStructure1;
//	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_8;
//	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure1);
//	
//	TIM_InternalClockConfig(TIM1);
//	
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure1;
//	TIM_TimeBaseInitStructure1.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructure1.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInitStructure1.TIM_Period = 100 - 1;		//ARR
//	TIM_TimeBaseInitStructure1.TIM_Prescaler = 36 - 1;		//PSC
//	TIM_TimeBaseInitStructure1.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure1);
//	
//	TIM_OCInitTypeDef TIM_OCInitStructure1;
//	TIM_OCStructInit(&TIM_OCInitStructure);
//	TIM_OCInitStructure1.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStructure1.TIM_OCPolarity = TIM_OCPolarity_High;
//	TIM_OCInitStructure1.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure1.TIM_Pulse = 0;		//CCR
//	TIM_OC1Init(TIM1, &TIM_OCInitStructure1);
//	
//	  TIM_Cmd(TIM1, ENABLE);
//		TIM_CtrlPWMOutputs(TIM1,ENABLE);  
}

void PWM_SetCompare4(uint16_t Compare)
{
	TIM_SetCompare4(TIM1, Compare);
}
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM1, Compare);
}
