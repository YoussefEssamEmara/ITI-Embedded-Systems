/*
 * ADC_Interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: ZBook G3
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

//ENABLE PIN ADEN
#define ENABLE 1
#define DISABLE 0
// DEFINITION CHANNELS
#define CHANNEL_0	0b00000000
#define CHANNEL_1	0b00000001
#define CHANNEL_2	0b00000010
#define CHANNEL_3	0b00000011
#define CHANNEL_4	0b00000100
#define CHANNEL_5	0b00000101
#define CHANNEL_6	0b00000110
#define CHANNEL_7	0b00000111
// init
void MADC_VoidInit();

// start conversion
u16 MADC_u8StartConversion(u8 channel);
#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
