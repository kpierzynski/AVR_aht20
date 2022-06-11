#include <avr/io.h>
#include <avr/interrupt.h>

#include "i2c.h"
#include "aht20.h"

void parse_aht20( int8_t temperature, uint8_t humidity, enum AHT20_STATUS status ) {
	if( status != AHT20_SUCCESS ) {
		// ...process error
		return;
	}

	// ...use provided values
}

int main()
{
	//Init i2c
	i2c_init();

	//Init aht20
	aht20_init();

	//Register callback for reading temperature and humidity
	register_aht20_event_callback( parse_aht20 );

	//Trigger measurement and wait 80mS
	aht20_trigger_measurement();
	_delay_ms(AHT20_MEASURE_DELAY);

	while(1) {
		//Event loop, nonblocking
		aht20_event();
	}

	return 0;
}
