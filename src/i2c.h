#ifndef __I2C_H_
#define __I2C_H_

#include <avr/io.h>

#define I2C_F 100000UL

#define I2C_READ	1
#define I2C_WRITE	0

#define I2C_ACK		1
#define I2C_NACK	0

void i2c_init();
void i2c_start();
void i2c_stop();
void i2c_write( uint8_t byte );
uint8_t i2c_read( uint8_t ack );

#endif
