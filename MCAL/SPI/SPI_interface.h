
#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_

#include "STD_TYPES.h"
#include "SPI_types.h"
#include "SPI_cfg.h"

extern u8 WORD_Transmitted_Asynch;



void M_void_SPI_Init (void);
void M_void_SPI_Interrupt_Enable (void);
void M_void_SPI_Interrupt_Disable (void);
void M_void_SPI_Set_Transmit_INT_CallBack (void (*localptr)(void));
void M_void_SPI_Transmit_ASynch (u8 word);
void M_void_SPI_Transmit_Synch (u8 word);


#endif /* SPI_SPI_INTERFACE_H_ */
