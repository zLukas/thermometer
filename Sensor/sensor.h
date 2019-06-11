/*
 * bm280.h
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */

#ifndef SENSOR_SENSOR_H_
#define SENSOR_SENSOR_H_

#include "defines.h"
#include "bme280.h"
#include "spi.h"
#include "timer.h"


#define BME_RESET_ADDRESS_VALUE 0xB6

/* sensor handlng using bosh API*/
typedef struct{
	struct bme280_dev bme_device;
	struct bme280_settings bme_settings;
	struct bme280_data bme_data;
	struct bme280_uncomp_data bme_raw_data;
	int8 initialized;
}bme_bosh_api;

void bme_init(void);
void bme_read(void);
bme_bosh_api* get_bme_pointer(void);
#endif /* SENSOR_SENSOR_H_ */
