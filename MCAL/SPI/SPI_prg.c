#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "Mcu_HW.h"
#include "SPI_interface.h"
#include "avr/interrupt.h"


void (*SPI_PTOFUNCTRANSMIT)(void);
u8 WORD_Transmitted_Asynch;


void M_void_SPI_Init (void)
{
	/*****Master or Slave******/
	SPCR &= 0xEF;
	SPCR |= (SPI_CONFIGURATION.role<<MSTR);

	/*****Data Order******/
	SPCR &= 0xDF;
	SPCR |= (SPI_CONFIGURATION.Data_oreder<<DORD);

	/*****Frequency******/
	WRITE_BIT(SPSR,SPI2X,((SPI_CONFIGURATION.freq)>>2));
	SPI_CONFIGURATION.freq &=0x03;
	SPCR &= 0xFC;
	SPCR |= (SPI_CONFIGURATION.freq);

	/*****Mode******/
	switch (SPI_CONFIGURATION.mode)
	{
	case SPI_MODE0:
		CLR_BIT(SPCR,CPOL);
		CLR_BIT(SPCR,CPHA);
		break;

	case SPI_MODE1:
		CLR_BIT(SPCR,CPOL);
		SET_BIT(SPCR,CPHA);
		break;

	case SPI_MODE2:
		SET_BIT(SPCR,CPOL);
		CLR_BIT(SPCR,CPHA);
		break;

	case SPI_MODE3:
		SET_BIT(SPCR,CPOL);
		SET_BIT(SPCR,CPHA);
		break;
	}


	/*****SPI Enable******/
	SET_BIT(SPCR,SPE);

}


void M_void_SPI_Interrupt_Enable (void)
{
	SET_BIT(SPCR,SPIE);
}

void M_void_SPI_Interrupt_Disable (void)
{
	CLR_BIT(SPCR,SPIE);
}

void M_void_SPI_Set_Transmit_INT_CallBack (void (*localptr)(void))
{
	SPI_PTOFUNCTRANSMIT=localptr;
}


void M_void_SPI_Transmit_Synch (u8 word)
{
	while (!GET_BIT(SPSR,SPIF));
	SPDR=word;
}


void M_void_SPI_Transmit_ASynch (u8 word)
{
	WORD_Transmitted_Asynch=word;
}


ISR (SPI_STC_vect)
{
	SPI_PTOFUNCTRANSMIT();
}





