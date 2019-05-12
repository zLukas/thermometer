/*
 * i2c.h
 *
 *  Created on: Apr 20, 2019
 *      Author: Lukas
 */

#ifndef COMMUNICATION_I2C_H_
#define COMMUNICATION_I2C_H_

#include "usic_i2c.h"
#include "defines.h"
#define NO_COMMAND	0xFF

typedef struct{
	void (*i2c_init)(void);
	void (*i2c_send)(uint8,uint8 ,uint8);
	void (*i2c_receive)(uint16, uint8);
}application_layer;


#endif /* COMMUNICATION_I2C_H_ */
