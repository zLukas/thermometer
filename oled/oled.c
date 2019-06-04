/*
 * oled.c
 *
 *  Created on: Apr 23, 2019
 *      Author: Lukas
 */
#include "oled.h"

char temperature[20];
char humidity[20];
char pressure[20];

void oled_init(void){
	ssd1306_initalization();
}
void oled_demo(void){

	ssd1306_clear_screen(0xFF);
	delay_ms(1000);
	ssd1306_clear_screen(0x00);
	delay_ms(1000);
oled_write_lines((float[]){26.1,1000, 50,5 } );
}

void oled_write_lines(float* data){

	snprintf(temperature, 15, "T %.2f      C", data[0]);
	snprintf(pressure, 15,    "P %.0f     hPa", data[1]);
	snprintf(humidity, 15,    "H %.2f     %%", data[2]);
	ssd1306_display_string(5, 16, (uint8 *)temperature, 16, 1);
	ssd1306_display_string(5, 32, (uint8 *)pressure, 16, 1);
	ssd1306_display_string(5, 48, (uint8 *)humidity, 16, 1);

	ssd1306_refresh_gram();
}

//todo Lukas : replace delay in ssd sample

