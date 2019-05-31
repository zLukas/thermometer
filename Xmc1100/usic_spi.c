/*
 * usic_spi.c
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */


#include "usic_spi.h"
uint8 spi_init(void){

}

uint8 usic_spi_send_read( uint8* data_to_send, uint8* data_to_read, uint8 data_send_count , uint8 data_read_count){
	SPI_MASTER_Transmit(&SPI_MASTER_0, data_to_send, data_send_count);
	//wait for transmit
	while(SPI_MASTER_IsTxBusy(&SPI_MASTER_0));

	if(data_to_read == 0){
		//wait for receive
		SPI_MASTER_Receive(&SPI_MASTER_0, data_to_read, data_read_count);
		while(SPI_MASTER_IsRxBusy(&SPI_MASTER_0));
		return (data_to_read == 0) ?  0 : 1;
	}
	else{
		return 0;
	}


}
