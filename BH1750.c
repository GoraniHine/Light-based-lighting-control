/*
 * BH1750.c
 *
 *  Created on: Sep 9, 2025
 *      Author: Minsig
 */

#include "bh1750.h"

void BH1750_Init(I2C_HandleTypeDef *hi2c)
{
  uint8_t cmd;

  cmd = 0x01;
  HAL_I2C_Master_Transmit(hi2c, BH1750_ADDR, &cmd, 1, HAL_MAX_DELAY);
  HAL_Delay(10);

  cmd = 0x10;
  HAL_I2C_Master_Transmit(hi2c, BH1750_ADDR, &cmd, 1, HAL_MAX_DELAY); //전송부분
}

uint16_t BH1750_ReadLight(I2C_HandleTypeDef *hi2c)
{
  uint8_t buf[2];
  uint16_t lux;

  HAL_I2C_Master_Receive(hi2c, BH1750_ADDR, buf, 2, HAL_MAX_DELAY);

  lux = (buf[0] << 8) | buf[1];
  lux = lux / 1.2;

  return lux;
}

/*
#define BH1750_POWER_ON     0x01
#define BH1750_RESET        0x07
#define BH1750_CONT_H_RES   0x10 보통 모드
#define BH1750_CONT_H_RES2  0x11 고정밀 모드, 밝기 작은 환경에서도 유리
#define BH1750_CONT_L_RES   0x13 속도 우선 모드, 정밀도는 떨어짐
#define BH1750_ONE_H_RES    0x20 1회 측정 모드, 한 번만 측정하고 자동으로 Power Down 모드로 돌아감.
#define BH1750_ONE_H_RES2   0x21 1회 측정 고정밀 모드
#define BH1750_ONE_L_RES    0x23 1회 측정 속도 우선 모드
 */
