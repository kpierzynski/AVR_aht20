#include "i2c.h"

void i2c_init() {
	//F_SCL = F_CPU / (16 + 2*TWBR*PRESC)
	//TWSR - presc register
	#if (F_CPU/I2C_F - 16)/2 > 255
		#error TWBR outside range
	#endif
	TWBR = (F_CPU/I2C_F - 16)/2;
}

void i2c_start() {
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while( !(TWCR & (1<<TWINT)) );
}

void i2c_stop() {
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while( !(TWCR & (1<<TWSTO)) );
}

void i2c_write( uint8_t byte ) {
	TWDR = byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( !(TWCR & (1<<TWINT)) );
}

uint8_t i2c_read( uint8_t ack ) {
	TWCR = (1<<TWINT) | ( ( ack ? 1 : 0 ) <<TWEA) | (1<<TWEN);
	while( !(TWCR & (1<<TWINT)) );
	return TWDR;
}
