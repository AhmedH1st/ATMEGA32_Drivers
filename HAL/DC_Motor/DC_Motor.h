/*
 * DC_Motor.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Ahmed Hesham
 */

#ifndef DC_MOTOR_DC_MOTOR_H_
#define DC_MOTOR_DC_MOTOR_H_

#include "PORT_Interface.h"




#define inc1   DIO_PD0
#define inc2   DIO_PD1

#define M_EN     DIO_PB3

void H_void_Motor_Start_CCw (void);
void H_void_Motor_Start_Cw (void);
void H_void_Motor_Stop (void);



#endif /* DC_MOTOR_DC_MOTOR_H_ */
