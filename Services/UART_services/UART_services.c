#include "STD_TYPES.h"
#include "Mcu_HW.h"
#include "Bit_Math.h"
#include "UART_interface.h"
#include "Call_Back_functions.h"
#include "FP_interface.h"
#include "util/delay.h"


/********** WIFI SERVICES FUNCTIONS **********************/


void UART_Send_WIFI_String_Synch (u8* str)
{
	u8 i=0;

	M_void_UART__SendWord_Synch(str[i]);

	for (; str[i] != '\n';)
	{
		i++;
		M_void_UART__SendWord_Synch(str[i]);
	}
}


void UART_Recieve_WIFI_String_Synch (u8* str)
{
	u8 i=0;
	u8 count=0;
	M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);

	for (; str[i] != '\n' && count < 1;)
	{
		if (str[i] == '\n' && count == 0)
		{
			count=1;
			i=0;
			M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);
			continue;
		}
		if (str[i] == '\r')
		{
			if (count == 1)
			{
				i--;
				M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);
				continue;
			}
			i=0;
			M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);
			continue;
		}

		i++;
		M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);
	}
	str[i]=0;
}








void UART_Recieve_WIFI_String_Synch_TRIAL2 (u8* str)
{
	u8 i=0;
	u8 count=0;
	M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);

	for (; str[i] != '\n' && count < 1;)
	{
		if (str[i] == '\n' && count == 0)
		{
			count=1;
		}
		i++;
		M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);
	}
	str[i]=0;
}




void UART_Recieve_WIFI_String_Synch_TRIAL3 (u8* str)
{
	u8 i=0;
	u8 count=0;
	UART_Response_t response=UART_NORESPONSE;



	for (u16 j =0; j<100; j++)
	{
		response=M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);
		if (response == UART_RESPONSED)
		{
			i++;
		}
	}
	str[i]=0;
}


void UART_SendString_Synch (u8* str)
{
	u8 i;

	for (i=0; str[i]; i++)
	{
		M_void_UART__SendWord_Synch(str[i]);
	}
}


void UART_ReceiveString (u8* str)    //initial need optimization
{
	 u8 i=0;
	 M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);
	 for (; str[i]!='K';)
	 {
		 i++;
		 M_void_UART_ReceiveWord_Synch_NoBlocking(&str[i]);
	 }
}









/********************SERVICES OF FINGER PRINT**********************/


void UART_SendArr (u8* arr, u8 size)
{
	u8 i;

	for (i=0; i<size; i++)
	{
		M_void_UART__SendWord_Synch(arr[i]);
		//_delay_ms(200);   //test
	}
}


void UART_RecieveArr (u8* arr, u8 size)
{
	UART_Response_t response;
	u8 i=0;

	response=M_void_UART_ReceiveWord_Synch_NoBlocking(&arr[i]);

	for (; i<size;)
	{
		if (response == UART_RESPONSED)
		{
			i++;
			M_void_UART_ReceiveWord_Synch_NoBlocking(&arr[i]);
		}
		else
		{
			H_LCD_WriteChar('n');
		}
	}
}

