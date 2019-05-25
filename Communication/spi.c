/*
 * spi.c
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */


#include "spi.h"


spi_functions hardware_spi ={
		.exchange_data= usic_spi_send_read
};

uint8 spi_send_read(uint8 register_address, uint8* data_to_send, uint8 data_count){
	 uint8* transmit_data = (uint8*)calloc(data_count,sizeof(uint8));
	 transmit_data[0]= register_address;
	 for(uint8 i = 1 ; i < data_count - 1 ; i++){
		 transmit_data[i] = data_to_send[i-1];
	 }
	 uint8 received_data = hardware_spi.exchange_data(transmit_data,data_count);
	 free(transmit_data);
	 return received_data;
}
