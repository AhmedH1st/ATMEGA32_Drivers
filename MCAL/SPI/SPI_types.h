
#ifndef SPI_SPI_TYPES_H_
#define SPI_SPI_TYPES_H_



typedef enum{
	SPI_SLAVE,
	SPI_MASTER

}SPI_Role_t;


typedef enum {
	SPI_MSB,
	SPI_LSB

}SPI_DataOrder_t;

typedef enum{
	SPI_MODE0,
	SPI_MODE1,
	SPI_MODE2,
	SPI_MODE3
}SPI_Mode_t;

typedef enum{
	SPI_F_4,
	SPI_F_16,
	SPI_F_64,
	SPI_F_128,
	SPI_F_2,
	SPI_F_8,
	SPI_F_32,

}SPI_Frequency_t;

/*typedef struct{
	u8 doube_Speed_bit : 0;
}SPI_Double_SpeedBit_t;*/

typedef struct {
	SPI_Role_t role;
	SPI_DataOrder_t Data_oreder;
	SPI_Mode_t mode;
	SPI_Frequency_t freq;

}SPI_cfg_t;

#endif /* SPI_SPI_TYPES_H_ */
