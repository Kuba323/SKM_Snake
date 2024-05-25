/*
 * MAX7219_graph.h
 *
 *  Created on: May 6, 2024
 *      Author: Lenovo
 */

#ifndef SRC_MAX7219_GRAPH_H_
#define SRC_MAX7219_GRAPH_H_

extern uint8_t buf[8];
extern uint8_t numbers[10][8];
void row(uint8_t address, uint8_t data);
void buf_out(void);
void buf_set(uint8_t x, uint8_t y);
void buf_clr(uint8_t x, uint8_t y);
void set_pixel(uint8_t x, uint8_t y);
void clr_pixel(uint8_t x, uint8_t y);
void draw_vertical_line(uint8_t x, uint8_t len);
void draw_horizontal_line(uint8_t y, uint8_t len);
void write_num(uint8_t num);

#endif /* SRC_MAX7219_GRAPH_H_ */
