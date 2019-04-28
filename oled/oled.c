/*
 * oled.c
 *
 *  Created on: Apr 23, 2019
 *      Author: Lukas
 */
#include "oled.h"


application_layer hardware={
		.set_oled_pin = set_pin
};

void oled_init(void){

	hardware.set_oled_pin(reset_pin, low_state);
	ssd1306_initalization();

}
//todo Lukas : replace delay in ssd sample

