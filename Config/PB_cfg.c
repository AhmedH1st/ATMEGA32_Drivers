#include "PB_cfg.h"
#include "DIO_Interface.h"





/*
 * Config status of connected Push Buttons and connected in which pins
 * PB_Config_Arr[0] represent --> PB1
 * PB_Config_Arr[1] represent --> PB2
 * PB_Config_Arr[2] represent --> PB3
 * PB_Config_Arr[3] represent --> PB4
 *
 */
const PB_ConfigType PB_Config_Arr [MAX_NO_PB]={{DIO_PD7,PB_ACTIVE_LOW},
											   {DIO_PD6,PB_ACTIVE_LOW},
											   {DIO_PD5,PB_ACTIVE_LOW},
											   {DIO_PD3,PB_ACTIVE_LOW}};

