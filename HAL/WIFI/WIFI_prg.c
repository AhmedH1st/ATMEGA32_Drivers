#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "UART_interface.h"
#include "UART_services.h"
#include "WIFI_interface.h"
#include "Call_Back_functions.h"
#include "util/delay.h"

/*******************TO BE REALLOCATE IN ANOTHER FILE*********************/



void WIFI_Init (void)
{
	UART_SendString_Synch("AT\r\n");

	while(Rec_Com_flag == 0);

	Rec_Com_flag=0;
	_delay_ms(2000);

	UART_SendString_Synch("ATE0\r\n");

	while(Rec_Com_flag == 0);

	Rec_Com_flag=0;
	_delay_ms(2000);

	UART_SendString_Synch("AT+GMR\r\n");

	while(Rec_Com_flag == 0);

	Rec_Com_flag=0;
	_delay_ms(2000);

	UART_SendString_Synch("AT+CWMODE=3\r\n");

	while(Rec_Com_flag == 0);

	Rec_Com_flag=0;
	_delay_ms(2000);


	UART_SendString_Synch("AT+CWJAP=");
	UART_SendString_Synch(IP);
	UART_SendString_Synch(",");
	UART_SendString_Synch(Pass);
	UART_SendString_Synch("\r\n");

	while(Rec_Com_flag == 0);

	Rec_Com_flag=0;
	_delay_ms(2000);

	UART_SendString_Synch("AT+CIFSR\r\n");

	while(Rec_Com_flag == 0);

	Rec_Com_flag=0;
	_delay_ms(2000);

	UART_SendString_Synch("AT+CIPSTATUS\r\n");

	while(Rec_Com_flag == 0);

	Rec_Com_flag=0;
	_delay_ms(2000);


	UART_SendString_Synch("AT+CIPSTART=");
	UART_SendString_Synch("\"TCP\"");
	UART_SendString_Synch(",");
	UART_SendString_Synch(SERVER_IP);
	UART_SendString_Synch(",");
	UART_SendString_Synch(SERVER_PORT);
	UART_SendString_Synch("\r\n");


	while(Rec_Com_flag == 0);

	Rec_Com_flag=0;
	_delay_ms(2000);
	Rec_Com_flag=2;
	_delay_ms(2000);
	H_LCD_ClearDisplay();

	H_LCD_Writestr("You Ready To Go!");
	_delay_ms(3000);
	H_LCD_ClearDisplay();

}









