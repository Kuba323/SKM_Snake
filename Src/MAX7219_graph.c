/*
 * MAX7219_graph.c
 *
 *  Created on: May 6, 2024
 *      Author: Lenovo
 */

#include <stdint.h>
#include "MAX7219_graph.h"
#include "MAX7219.h"

uint8_t buf[8] = {};
uint8_t numbers[10][8] = {
		{0x1c,0x22,0x22,0x22,0x22,0x22,0x1c,0x00},
		{0x04,0x0c,0x14,0x04,0x04,0x04,0x04,0x00},
		{0x1c,0x22,0x02,0x04,0x08,0x10,0x3e,0x00},
		{0x1c,0x22,0x02,0x1c,0x02,0x22,0x1c,0x00},
		{0x0c,0x14,0x24,0x3e,0x04,0x04,0x04,0x00},
		{0x3e,0x20,0x20,0x1c,0x02,0x02,0x3c,0x00},
		{0x1c,0x22,0x20,0x3c,0x22,0x22,0x1c,0x00},
		{0x3c,0x02,0x02,0x04,0x08,0x10,0x20,0x00},
		{0x1c,0x22,0x22,0x1c,0x22,0x22,0x1c,0x00},
		{0x1c,0x22,0x22,0x1c,0x02,0x22,0x1c,0x00},
};

void row(uint8_t address, uint8_t data){
	if(address>=1 && address<=8) MAX7219_write_reg(address, data);
}

void buf_out(void){
	for(uint8_t i=1; i<=8; i++){
		row(i, buf[i-1]);
	}
}

void buf_set(uint8_t x, uint8_t y) {
    uint8_t sx = 7 - (x & 0b0111);
    uint8_t sy = (y & 0b0111);
    buf[sy] |= (1 << sx);
}

void buf_clr(uint8_t x, uint8_t y) {
    uint8_t sx = 7 - (x & 0b0111);
    uint8_t sy = (y & 0b0111);
    buf[sy] &= ~(1 << sx);
}

void set_pixel(uint8_t x, uint8_t y) {
    uint8_t sx = 7 - (x & 0b0111);
    uint8_t sy = (y & 0b0111);
    buf[sy] |= (1 << sx);
    buf_out();
}

void clr_pixel(uint8_t x, uint8_t y) {
    uint8_t sx = 7 - (x & 0b0111);
    uint8_t sy = (y & 0b0111);
    buf[sy] &= ~(1 << sx);
    buf_out();
}


void draw_vertical_line(uint8_t x, uint8_t len){
	if(len<9){
		for(uint8_t i=0; i<len; i++){
			set_pixel(x, i);
		}
	}
}

void draw_horizontal_line(uint8_t y, uint8_t len){
	if(len<9){
		for(uint8_t i=0; i<9; i++){
			set_pixel(i, y);
		}
	}
}

void write_num(uint8_t num){
	for(uint8_t i=0; i<8; i++){
		buf[i] = numbers[num][i];
	}

}
