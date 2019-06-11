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

void bme_power_on_reset(void){
	uint8 reset_value = BME_RESET_ADDRESS_VALUE;
	get_bme_pointer()->bme_device.write(BME280_RESET_ADDR,&reset_value,1);
}

void  bme_init(void){
	bme_bosh_api* bme = get_bme_pointer();
	bme->initialized= 0 ;
	bme->bme_device.dev_id = 1;
	bme->bme_device.write = spi_send;
	bme->bme_device.read = spi_read;
	bme->bme_device.delay_ms = delay_ms;
	bme_power_on_reset();
	delay_us(1000);
	bme->initialized  = bme280_init(&(bme->bme_device));
}

void bme_read(void){
	bme_bosh_api* bme = get_bme_pointer();
	bme280_get_sensor_data(BME280_ALL, &bme->bme_data, &bme->bme_device);
}

void bme_parse(void){
	//todo Lukas: implement this
}
