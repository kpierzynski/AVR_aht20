#ifndef __AHT20_H_
#define __AHT20_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "i2c.h"

#define CRC_SAVE_SPACE 0
#define CRC_SAVE_CPU 1

// ===== Config =====
#define CRC_TYPE CRC_SAVE_SPACE
// ==================

typedef struct {
        uint8_t state;
        uint8_t data[5];
        uint8_t crc;
} aht20_t;

enum AHT20_STATUS { AHT20_NOT_READY = 0, AHT20_CRC_FAIL, AHT20_SUCCESS };

#define AHT20_ADDRESS		0x38
#define AHT20_INIT_CMD		0xBE
#define AHT20_INIT_PARAM_1	0x08
#define AHT20_INIT_PARAM_2	0x00
#define AHT20_MEASURE_CMD	0xAC
#define AHT20_MEASURE_PARAM_1	0x33
#define AHT20_MEASURE_PARAM_2	0x00
#define AHT20_SOFT_RESET_CMD	0xBA
#define AHT20_STATUS_WORD	0x71

#define AHT20_BUSY		7
#define AHT20_CAL		3

#define AHT20_AFTER_POWER_ON_DELAY      40 + 5 //Extra 5ms to be sure :p
#define AHT20_DELAY                     30
#define AHT20_MEASURE_DELAY             80

void register_aht20_event_callback(void (*callback)(int8_t temperature, uint8_t humidity, enum AHT20_STATUS status));

void aht20_init();
void aht20_trigger_measurement();
void aht20_event();


#endif
