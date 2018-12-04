#include <stdio.h>
#include <avr/interrupt.h>
#include "lib/avr_gpio.h"
#include "lib/avr_usart.h"
#include "lib/bits.h"
#include "sensores.h"
#include "modbus.h"

 uint8_t pack_rtu[8];


