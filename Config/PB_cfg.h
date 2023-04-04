#ifndef PB_CFG_H_
#define PB_CFG_H_

#include "Std_Types.h"
#include "PB_types.h"

/**************
 * Config number of Push Buttons connected
 */
#define MAX_NO_PB     4



typedef struct{
	PB_IDType        PB_ID;
	PB_ActiveType    PB_Activity;
}PB_ConfigType;



extern const PB_ConfigType PB_Config_Arr [MAX_NO_PB];




#define PB1_PIN           	  DIO_PD0
#define PB2_PIN               DIO_PD6
#define PB3_PIN               DIO_PD5
#define PB4_PIN               DIO_PD3

#define PB1_ActiveType

#endif /* PB_CFG_H_ */
