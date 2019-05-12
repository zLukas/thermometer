/*
 * i2c.c
 *
 *  Created on: Apr 20, 2019
 *      Author: Lukas
 */
#include "i2c.h"

application_layer hardware ={
	.i2c_init = usic_i2c_init,
	.i2c_send = usic_i2c_transmit_byte
};
