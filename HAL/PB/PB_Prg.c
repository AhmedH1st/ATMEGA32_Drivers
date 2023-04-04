#include "Bit_Math.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "PB_interface.h"
#include "PB_private.h"
#include "PB_types.h"
#include "PB_cfg.h"

const PB_ConfigType PB_Config_Arr [MAX_NO_PB];

PB_StateType H_PB_void_readSwitch (PB_IDType PB_ID)
{
	u8 index;
	//PB_StateType readed_val;
	/*u8 Local_pin;
	u8 Local_port;*/

	switch (PB_ID)
	{
	case PB1:index=0;break;
	case PB2:index=1;break;
	case PB3:index=2;break;
	case PB4:index=3;break;
	default:break;
	}

	/*Local_pin=(PB_Config_Arr[index].PB_ID) % 10;
	Local_port=(PB_Config_Arr[index].PB_ID) / 10;*/

	if (PB_Config_Arr[index].PB_Activity == PB_ACTIVE_LOW)
	{
		if (!(M_DIO_getPinValue((PB_Config_Arr[index]).PB_ID)))
		{
			return PB_PRESSED;
		}
		else
		{
			return PB_UNPRESSED;
		}

	}

	else if (PB_Config_Arr[index].PB_Activity == PB_ACTIVE_HIGH )
	{
		if (M_DIO_getPinValue(PB_Config_Arr[index].PB_ID))
			{
				return PB_PRESSED;
			}
			else
			{
				return PB_UNPRESSED;
			}
	}

	return 0;

}
