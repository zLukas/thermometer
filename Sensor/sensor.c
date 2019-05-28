/*
 * bm280.c
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */

#include "sensor.h"

bme_bosh_api bme_sensor;

bme_bosh_api* get_bme_pointer(void){
	return &bme_sensor;
}
void  bme_init(void){
	bme_bosh_api* bme = get_bme_pointer();
	bme->initialized= 0 ;
	bme->bme_device.dev_id = 1;
	bme->bme_device.write = spi_send;
	bme->bme_device.read = spi_read;
	bme->bme_device.delay_ms = delay_ms;

	bme->initialized  = bme280_init(&(bme->bme_device));
}

void bme_read(void){
	//todo Lukas: implement this
}

void bme_parse(void){
	//todo Lukas: implement this
}
