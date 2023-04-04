#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include <util/delay.h>
#include "Timer1_interface.h"
#include "Call_Back_functions.h"
#include "UltraSonic_interface.h"


void Ultrasonic_Init (void)
{

}


UltraSonic_Status_t Ultrasonic_GetRead (u16* PDistance)
{
	UltraSonic_Status_t status;

	u32 RunOutOfTime_counter=0;

	M_void_Timer1_zero();


	M_DIO_void_setPinValue(TR,DIO_HIGH);
	_delay_ms(10);
	M_DIO_void_setPinValue(TR,DIO_LOW);

	while ( (ICU_flag<2) && (RunOutOfTime_counter<1000))
	{
		RunOutOfTime_counter++;
		_delay_us(1);
	}

	if (ICU_flag==2)
	{
		ICU_flag=0;
		*PDistance=((u32)(t2-t1)*4)/58;
		t1=0;
		t2=0;
		status=TARGET_FOUND_WITHIN_RANGE;
	}
	else
	{
		status=TAREGE_NOT_FOUND_WITHIN_RANGE;
	}

	return status;
}
