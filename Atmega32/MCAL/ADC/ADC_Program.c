/*
 * ADC_Program.c
 *
 *  Created on: Aug 11, 2024
 *      Author: ZBook G3
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"



// init
void MADC_VoidInit() {
    ADMUX = (1 << ADMUX_REFS0);
    ADCSRA = (1 << ADCSRA_ADEN) | (1 << ADCSRA_ADPS1) | (1 << ADCSRA_ADPS0);
}

u16 MADC_u8StartConversion(u8 channel) {
    // select the ADC channel
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

    // start the conversion
    ADCSRA |= (1 << ADCSRA_ADSC);

    // wait for the conversion to complete
    while (ADCSRA & (1 << ADCSRA_ADSC));

    // Return the ADC value
    return ADCHL;
}
