/*
 * max7219.h
 *
 *  Created on: Sep 15, 2025
 *      Author: Minsig
 */

#ifndef INC_MAX7219_H_
#define INC_MAX7219_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>

extern SPI_HandleTypeDef hspi2;

#define MAX7219_CS_PORT GPIOA
#define MAX7219_CS_PIN GPIO_PIN_4

void MAX7219_Init(void);
void MAX7219_Clear(void);
void MAX7219_Send(uint8_t address, uint8_t data);

void MAX7219_DisplayLevel(uint8_t level); //1~8단계 출력
void MAX7219_DisplaySun(void); //해 출력
void MAX7219_DisplayMoon(void); //달 출력

#endif /* INC_MAX7219_H_ */
