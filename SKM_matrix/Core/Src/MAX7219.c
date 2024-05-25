/*
 * MAX7219.c
 *
 *  Created on: May 6, 2024
 *      Author: Lenovo
 */

#include "MAX7219.h"
#include "spi.h"

void MAX7219_write_reg(uint8_t address, uint8_t data){
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 0);
	HAL_SPI_Transmit(&hspi1, &address, sizeof(address), HAL_MAX_DELAY);
	HAL_SPI_Transmit(&hspi1, &data, sizeof(data), HAL_MAX_DELAY);
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 1);
}

void MAX7219_init(){
	MAX7219_write_reg(0x09, 0x00);
	MAX7219_write_reg(0x0a, 0x05);
	MAX7219_write_reg(0x0b, 0x07);
	MAX7219_write_reg(0x0c, 0x01);
	MAX7219_write_reg(0x0f, 0x00);
}
