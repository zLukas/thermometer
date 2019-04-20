/*
 * usic_i2c.c
 *
 *  Created on: Apr 20, 2019
 *      Author: Lukas
 */
#include "usic_i2c.h"


extern I2C_MASTER_t I2C_MASTER_0;

void usic_i2c_init(void){
	I2C_MASTER_Init(&I2C_MASTER_0);
}

void usic_i2c_transmit(){

}




