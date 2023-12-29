#ifndef __MOTOR_H
#define __MOTOR_H

void Motor_Init(void);
void Motor_SetSpeed(int8_t Speed);
void Motor_SetSpeed1(int8_t Speed);
void Forward(void);
void Backword(void);
void Turnleft(void);
void Turnright(void);
void Stop(void);
void Accelerate(void);
void Accelerate1(void);
#endif
