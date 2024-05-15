/*
 * MAX7219.h
 *
 *  Created on: May 6, 2024
 *      Author: Lenovo
 */

#include <stdint.h>

#ifndef SRC_MAX7219_H_
#define SRC_MAX7219_H_

void MAX7219_write_reg(uint8_t address, uint8_t data);
void MAX7219_init();

#endif /* SRC_MAX7219_H_ */
