/*
 * oled.h
 *
 *  Created on: Apr 23, 2019
 *      Author: Lukas
 */

#ifndef OLED_OLED_H_
#define OLED_OLED_H_
#include <stdio.h>
#include "defines.h"
#include "SSD1306.h"

void oled_init(void);
void oled_demo(void);
void oled_write_lines(char* data);
#endif /* OLED_OLED_H_ */
