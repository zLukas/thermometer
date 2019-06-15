/*
 * bm280.c
 *
 *  Created on: May 25, 2019
 *      Author: Lukas
 */

#include "sensor.h"

bme_bosh_api bme_sensor;
bme280_oversamplings convertion_table[] ={
		{.oversmpling= BME280_OVERSAMPLING_1X, .value = 1},
		{.oversmpling= BME280_OVERSAMPLING_2X, .value = 2},
		{.oversmpling= BME280_OVERSAMPLING_4X, .value = 4},
		{.oversmpling= BME280_OVERSAMPLING_8X, .value = 8},
		{.oversmpling= BME280_OVERSAMPLING_16X, .value = 16}
};


bme_bosh_api* get_bme_pointer(void){
	return &bme_sensor;
}
uint8 match_conversion_table(uint8 oversample){
	for(uint8 i = 0; i < sizeof(convertion_table)/sizeof(bme280_oversamplings); i++ ){
		if(convertion_table[i].oversmpling == oversample){
			return convertion_table[i].value;
		}
	}
	/* error */
	return 0xFF;
}
/*
 * todo: decide if it's  important
 */
uint16 calculate_measurement_time(void){
	bme_bosh_api* bme = get_bme_pointer();
	/* find proper value
	float t_humidity 	= match_conversion_table(bme->bme_settings.osr_h);
	float t_pressure 	= match_conversion_table(bme->bme_settings.osr_p);
	float t_temperature = match_conversion_table(bme->bme_settings.osr_t);

	float t_measure_min, t_measure_max, t_measure_typ;
	t_measure_min = 1 + (2*t_humidity)
			+(2 * t_pressure +0.5)
			+(2 * t_humidity + 0.5);

	t_measure_max = 1.25 + (2.3 *t_temperature)
			+(2.3 * t_pressure + 0.575)
			+(2.3 * t_humidity + 0.575);
	t_measure_typ = (t_measure_min + t_measure_max)/2;

			/* round to higher number
			return (uint16)(t_measure_typ + 0.5);

}
*/
void set_bme(void){
	bme_bosh_api* bme = get_bme_pointer();
	uint8 mode = 10;
	uint8 settings_to_update;

	//bme280_set_sensor_mode(BME_FORCED_MODE, &bme->bme_device);
	bme->bme_device.read(BME280_PWR_CTRL_ADDR,&mode,1);

	/* check if bme is in sleep after reset */
	if(mode == 0){

		/* assign values */
		bme->bme_settings.osr_h = BME280_OVERSAMPLING_1X;
		bme->bme_settings.osr_p = BME280_OVERSAMPLING_16X;
		bme->bme_settings.osr_t = BME280_OVERSAMPLING_2X;
		bme->bme_settings.filter= BME280_FILTER_COEFF_16;

		/* add setting to be updated */
		settings_to_update = BME280_OSR_PRESS_SEL;
		settings_to_update |= BME280_OSR_TEMP_SEL;
		settings_to_update |= BME280_OSR_HUM_SEL;
		settings_to_update |= BME280_FILTER_SEL;

		 uint8 rslt= bme280_set_sensor_settings(settings_to_update, &(bme->bme_device));
		/* measurement time based on equations in bme280 datasheet (Chapter 9.)*/
		bme->measurement_time = 15;//calculate_measurement_time();
	}
}

void  bme_init(void){
	spi_bme_init();
	bme_bosh_api* bme = get_bme_pointer();
	bme->initialized= 1 ;
	bme->bme_device.intf = BME280_SPI_INTF;
	bme->bme_device.dev_id = 0;
	bme->bme_device.write = spi_send;
	bme->bme_device.read = spi_read;
	bme->bme_device.delay_ms = delay_ms;
	bme->initialized  = bme280_init(&(bme->bme_device));
	set_bme();

	uint8 results =  bme280_crc_selftest(&(bme->bme_device));
}

void bme_read(void){
	spi_bme_init();
	bme_bosh_api* bme = get_bme_pointer();

	bme280_set_sensor_mode(BME280_FORCED_MODE, &bme->bme_device);
	bme->bme_device.delay_ms(40);
	bme280_get_sensor_data(BME280_ALL, &(bme->bme_data), &(bme->bme_device));
}
