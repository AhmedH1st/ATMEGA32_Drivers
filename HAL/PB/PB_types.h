/*
 * PB_types.h
 *
 *  Created on: Feb 18, 2023
 *      Author: Ahmed Hesham
 */

#ifndef PB_PB_TYPES_H_
#define PB_PB_TYPES_H_


typedef enum{
	PB_UNPRESSED=0,
	PB_PRESSED
}PB_StateType;


typedef enum{
	PB1=0,
	PB2,
	PB3,
	PB4
}PB_IDType;

typedef enum {
	PB_ACTIVE_LOW,
	PB_ACTIVE_HIGH
}PB_ActiveType;



#endif /* PB_PB_TYPES_H_ */
