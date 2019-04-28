/*
 * digital_io.c
 *
 *  Created on: Apr 28, 2019
 *      Author: Lukas
 */

#include "digital_io_pins.h"



void gpio_init(void){
	DIGITAL_IO_Init(&OLED_D_C);
	DIGITAL_IO_Init(&OLED_RES);
}

void set_pin(oled_pins pin , pin_states state ){
	switch(pin){
		case dc_pin:
			state ? (DIGITAL_IO_SetOutputHigh(&OLED_D_C)) : (DIGITAL_IO_SetOutputLow(&OLED_D_C));
			break;
		case reset_pin:
			state ? (DIGITAL_IO_SetOutputHigh(&OLED_RES)) : (DIGITAL_IO_SetOutputLow(&OLED_RES));
	}
}

