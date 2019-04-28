/*
 * digital_io_pins.h
 *
 *  Created on: Apr 28, 2019
 *      Author: Lukas
 */

#ifndef XMC1100_DIGITAL_IO_PINS_H_
#define XMC1100_DIGITAL_IO_PINS_H_

#include <DAVE.h>

typedef enum{
	low_state = 0,
	high_state =1

}pin_states;

typedef enum{
	dc_pin =0,
	reset_pin
}oled_pins;


void gpio_init(void);
void set_pin(oled_pins pin , pin_states state );

#endif /* XMC1100_DIGITAL_IO_PINS_H_ */
