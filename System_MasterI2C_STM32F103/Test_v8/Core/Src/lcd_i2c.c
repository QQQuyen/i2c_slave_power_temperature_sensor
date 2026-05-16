/*
 * lcd_i2c.c
 *
 *  Created on: Mar 18, 2026
 *      Author: MyLaptop
 */

#include "lcd_i2c.h"

extern I2C_HandleTypeDef hi2c1;

#define LCD_ADDR (0x27 << 1)

#define LCD_BACKLIGHT 0x08
#define ENABLE 0x04

void lcd_send_cmd(char cmd)
{
    char data_u, data_l;
    uint8_t data_t[4];

    data_u = (cmd & 0xF0);
    data_l = ((cmd << 4) & 0xF0);

    data_t[0] = data_u | LCD_BACKLIGHT | ENABLE;
    data_t[1] = data_u | LCD_BACKLIGHT;
    data_t[2] = data_l | LCD_BACKLIGHT | ENABLE;
    data_t[3] = data_l | LCD_BACKLIGHT;

    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, data_t, 4, 100);
}

void lcd_send_data(char data)
{
    char data_u, data_l;
    uint8_t data_t[4];

    data_u = (data & 0xF0);
    data_l = ((data << 4) & 0xF0);

    data_t[0] = data_u | LCD_BACKLIGHT | ENABLE | 0x01;
    data_t[1] = data_u | LCD_BACKLIGHT | 0x01;
    data_t[2] = data_l | LCD_BACKLIGHT | ENABLE | 0x01;
    data_t[3] = data_l | LCD_BACKLIGHT | 0x01;

    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, data_t, 4, 100);
}

void lcd_init(void)
{
    HAL_Delay(50);

    lcd_send_cmd(0x30);
    HAL_Delay(5);
    lcd_send_cmd(0x30);
    HAL_Delay(1);
    lcd_send_cmd(0x30);
    HAL_Delay(10);

    lcd_send_cmd(0x20); // 4-bit mode
    HAL_Delay(10);

    lcd_send_cmd(0x28); // 2 line
    lcd_send_cmd(0x08); // display off
    lcd_send_cmd(0x01); // clear
    HAL_Delay(2);
    lcd_send_cmd(0x06); // entry mode
    lcd_send_cmd(0x0C); // display on
}

void lcd_send_string(char *str)
{
    while (*str) lcd_send_data(*str++);
}

void lcd_clear(void)
{
    lcd_send_cmd(0x01);
    HAL_Delay(2);
}

void lcd_put_cur(int row, int col)
{
    uint8_t addr;

    if (row == 0)
        addr = 0x80 + col;
    else
        addr = 0xC0 + col;

    lcd_send_cmd(addr);
}
