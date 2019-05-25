/*
 * usic_spi.c
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */


#include "usic_spi.h"


uint8 usic_spi_send_read(uint8* data_to_send, uint8 data_count){
	SPI_MASTER_Transmit(&SPI_MASTER_0, data_to_send, data_count);
	while(SPI_MASTER_IsTxBusy(&SPI_MASTER_0));
	SPI_MASTER_0.runtime->tx_busy =false;

	uint8 data_received;
	SPI_MASTER_Receive(&SPI_MASTER_0, &data_received, 1);
	while(SPI_MASTER_IsRxBusy(&SPI_MASTER_0));
	SPI_MASTER_0.runtime->rx_busy = false;
	return data_received;
}
