/*
 * usic_i2c.h
 *
 *  Created on: Apr 20, 2019
 *      Author: Lukas
 */

#ifndef XMC1100_USIC_I2C_H_
#define XMC1100_USIC_I2C_H_


#include <stdio.h>
#include "I2C_MASTER/i2c_master.h"
#include "defines.h"
void i2c_no_link_irq(void);
void i2c_error_irq(void);

void usic_i2c_init(void);
void usic_i2c_transmit_byte(uint8 slave_address,uint8 memory_address, uint8 byte);

#endif /* XMC1100_USIC_I2C_H_ */
