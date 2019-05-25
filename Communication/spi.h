/*
 * spi.h
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */

#include "usic_spi.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	uint8 (*exchange_data)(uint8*, uint8);
}spi_functions;

uint8 spi_send_read(uint8 register_address, uint8* data_to_send, uint8 data_count);
