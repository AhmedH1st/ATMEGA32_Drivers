/*
 * UltraSonic_interface.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Ahmed Hesham
 */

#ifndef ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_ULTRASONIC_INTERFACE_H_
#include "DIO_Interface.h"


#define TR       DIO_PD0
//#define ECHO     DIO_PD6     //consider change


typedef enum{

	TARGET_FOUND_WITHIN_RANGE,
	TAREGE_NOT_FOUND_WITHIN_RANGE
}UltraSonic_Status_t;


void Ultrasonic_Init (void);
UltraSonic_Status_t Ultrasonic_GetRead (u16* PDistance);



#endif /* ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
