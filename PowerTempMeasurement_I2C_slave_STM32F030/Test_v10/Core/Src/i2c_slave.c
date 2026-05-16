

/*
 * i2c_slave.c
 *
 *  Created on: Mar 19, 2026
 *      Author: MyLaptop
 */


#include "main.h"
#include "i2c_slave.h"

extern I2C_HandleTypeDef hi2c1;

#define RxSize 6
uint8_t RxData[RxSize];

#define TxSize 7
uint8_t TxData[TxSize];
int count = 0;

void I2C_SetTxData(uint8_t *data)
{
    for(int i = 0; i < TxSize; i++)
    {
        TxData[i] = data[i];
    }
}

void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c){
	HAL_I2C_EnableListen_IT(hi2c);
}

extern void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
	if(TransferDirection == I2C_DIRECTION_TRANSMIT)
		{
			// Master ghi → Slave nhận
			HAL_I2C_Slave_Sequential_Receive_IT(hi2c, RxData, RxSize, I2C_FIRST_AND_LAST_FRAME);
		}
		else
		{
			// Master đọc → Slave gửi
			HAL_I2C_Slave_Sequential_Transmit_IT(hi2c, TxData, TxSize, I2C_FIRST_AND_LAST_FRAME);
		}
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	count++;
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_EnableListen_IT(hi2c);
}

void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	// gửi xong 6 byte
}
