/*
 * usic_i2c.c
 *
 *  Created on: Apr 20, 2019
 *      Author: Lukas
 */
#include "usic_i2c.h"

void i2c_no_link_irq(void){

}

void i2c_error_irq(void){

}


extern I2C_MASTER_t I2C_MASTER_0;

void usic_i2c_init(void){
	I2C_MASTER_Init(&I2C_MASTER_0);
}

void usic_i2c_transmit_byte(uint8 slave_address,uint8 memory_address, uint8 byte){

	static uint8 data_to_send[2];
	data_to_send[0] = memory_address;
	data_to_send[1] = byte;
	I2C_MASTER_Transmit(&I2C_MASTER_0, true,(uint32) slave_address,data_to_send, 1, true);
}
