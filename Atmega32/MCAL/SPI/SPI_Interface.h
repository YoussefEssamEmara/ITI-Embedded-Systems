#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_


void MSPI_voidMasterInit(void);

void MSPI_voidSlaveInit(void);

u8 MSPI_u8Trancieve(u8 Copy_u8DataToTransmit);

void MSPI_voidTransmit(u8 Copy_u8Data);

void MSPI_voidReceive(u8 *Copy_u8Data);

// SPI using async interrupt

void MSPI_voidMasterInitAsync(void);

void MSPI_voidSlaveInitAsync(void);

u8 MSPI_u8TrancieveAsync(u8 Copy_u8DataToTransmit);

void MSPI_voidTransmitAsync(u8 Copy_u8Data);

void MSPI_voidReceiveAsync(u8 *Copy_u8Data);

void MSPI_voidSetCallBack(void (*Copy_ptr)(void));

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */