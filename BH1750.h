/*
 * BH1750.h
 *
 *  Created on: Sep 9, 2025
 *      Author: Minsig
 */

#ifndef BH1750_H_
#define BH1750_H_

#include "main.h"

#define BH1750_ADDR (0x23 << 1)

void BH1750_Init(I2C_HandleTypeDef *hi2c);
uint16_t BH1750_ReadLight(I2C_HandleTypeDef *hi2c);

#endif /* BH1750_H_ */
