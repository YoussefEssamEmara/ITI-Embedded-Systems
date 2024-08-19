#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "Servo_Interface.h"
#include "Servo_Private.h"
#include "Servo_config.h"
#include <util/delay.h>

void MServo_voidInit(void)
{
    MDIO_vSetPinDir(SERVO_PORT, SERVO_PIN, DIO_OUTPUT);
}

void MServo_voidSetAngle(u8 Copy_u8Angle)
{
    u8 Local_u8PulseWidth = 0;
    Local_u8PulseWidth = (u8)(Copy_u8Angle * 11.11) + 500;
    MDIO_vSetPinVal(SERVO_PORT, SERVO_PIN, DIO_HIGH);
    _delay_us(Local_u8PulseWidth);
    MDIO_vSetPinVal(SERVO_PORT, SERVO_PIN, DIO_LOW);
    _delay_us(20000 - Local_u8PulseWidth);
}
