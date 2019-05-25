/*
 * bm280.c
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */

#include "sensor.h"

bme_bosh_api bme;

bme_bosh_api* get_bme_pointer(void){
	return &bme;
}

void bme_init(void){
	bme_bosh_api*  bme_ptr = get_bme_pointer();

	bme_ptr->bme_device.dev_id = 1;
	bme_ptr->bme_device.intf = BME280_SPI_INTF;
	bme_ptr->bme_device.delay_ms =delay_us;
	bme_ptr->bme_device.write = spi_send_read;
	bme_ptr->bme_device.read = spi_send_read;
}

