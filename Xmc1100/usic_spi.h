/*
 * usic_spi.h
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */

#ifndef XMC1100_USIC_SPI_H_
#define XMC1100_USIC_SPI_H_
#include <DAVE.h>
#include "defines.h"
/* DAVE_init initialize usic_spi*/

uint8 usic_spi_send_read(uint8* data_to_send, uint8* data_to_read, uint8 data_send_count , uint8 data_read_count);

#endif /* XMC1100_USIC_SPI_H_ */