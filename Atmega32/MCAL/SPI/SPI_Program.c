
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"

static void (*SPI_CallBack)(void) = NULL;

void MSPI_voidMasterInit(void)
{
    // data order
    SET_BIT(SPCR, SPCR_DORD);

    // master enable
    SET_BIT(SPCR, SPCR_MSTR);

    // clock polarity
    CLR_BIT(SPCR, SPCR_CPOL);

    // clock phase
    CLR_BIT(SPCR, SPCR_CPHA);
    // clock frequency
    SET_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
    CLR_BIT(SPSR, SPSR_SPI2X);

    // spi enable
    SET_BIT(SPCR, SPCR_SPE);
}

void MSPI_voidSlaveInit(void)
{
    // data order
    SET_BIT(SPCR, SPCR_DORD);

    // master enable
    CLR_BIT(SPCR, SPCR_MSTR);

    // clock polarity
    CLR_BIT(SPCR, SPCR_CPOL);

    // clock phase
    CLR_BIT(SPCR, SPCR_CPHA);
    // clock frequency
    SET_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
    CLR_BIT(SPSR, SPSR_SPI2X);

    // spi enable
    SET_BIT(SPCR, SPCR_SPE);
}

u8 MSPI_u8Trancieve(u8 Copy_u8DataToTransmit)
{
    // send data
    SPDR = Copy_u8DataToTransmit;

    // wait until transmission is complete
    while (GET_BIT(SPSR, SPSR_SPIF) == 0)
        ;

    // return received data
    return SPDR;
}

void MSPI_voidTransmit(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data;
    while (GET_BIT(SPSR, SPSR_SPIF) == 0)
        ;
}

void MSPI_voidReceive(u8 *Copy_u8Data)
{
    while (GET_BIT(SPSR, SPSR_SPIF) == 0)
        ;

    *Copy_u8Data = SPDR;
}
// SPI using async interrupt-----------------------------------
void MSPI_voidMasterInitAsync(void)
{
    // data order
    SET_BIT(SPCR, SPCR_DORD);

    // master enable
    SET_BIT(SPCR, SPCR_MSTR);

    // clock polarity
    CLR_BIT(SPCR, SPCR_CPOL);

    // clock phase
    CLR_BIT(SPCR, SPCR_CPHA);
    // clock frequency
    SET_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
    CLR_BIT(SPSR, SPSR_SPI2X);

    // spi enable
    SET_BIT(SPCR, SPCR_SPE);

    // enable interrupt
    SET_BIT(SPCR, SPCR_SPIE);
}

void MSPI_voidSlaveInitAsync(void)
{
    // data order
    SET_BIT(SPCR, SPCR_DORD);

    // slave enable
    CLR_BIT(SPCR, SPCR_MSTR);

    // clock polarity
    CLR_BIT(SPCR, SPCR_CPOL);

    // clock phase
    CLR_BIT(SPCR, SPCR_CPHA);
    // clock frequency
    SET_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
    CLR_BIT(SPSR, SPSR_SPI2X);

    // spi enable
    SET_BIT(SPCR, SPCR_SPE);

    // enable interrupt
    SET_BIT(SPCR, SPCR_SPIE);
}
u8 MSPI_u8TrancieveAsync(u8 Copy_u8DataToTransmit)
{
    SPDR = Copy_u8DataToTransmit;
    while (GET_BIT(SPSR, SPSR_SPIF) == 0)
        ;
    return SPDR;
}
void MSPI_voidTransmitAsync(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data;
}

void MSPI_voidReceiveAsync(u8 *Copy_u8Data)
{
    *Copy_u8Data = SPDR;
}

void MSPI_voidSetCallBack(void (*Copy_ptr)(void))
{
    SPI_CallBack = Copy_ptr;
}
void __vector_12(void)
{
    SPI_CallBack();
}

