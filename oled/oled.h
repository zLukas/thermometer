/*
 * oled.h
 *
 *  Created on: Apr 23, 2019
 *      Author: Lukas
 */

#ifndef OLED_OLED_H_
#define OLED_OLED_H_

#include "SSD1306.h"

#define uint16 uint16_t
#define uint8	uint8_t

typedef struct{
	void (*i2c_send)(uint16, uint8);
	void (*set_cs_pin)(uint8);
	void (*set_res_pin)(uint8);
}application_layer;

static application_layer hardware_functions;

#endif /* OLED_OLED_H_ */
