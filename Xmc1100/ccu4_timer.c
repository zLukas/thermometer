/*
 * ccu4_timer.c
 *
 *  Created on: Apr 23, 2019
 *      Author: Lukas
 */

#include "ccu4_timer.h"
void ccu_init(void){
	CLOCK_XMC1_Init(&CLOCK_XMC1_0);
}

//todo Lukas: make timer-based delay
