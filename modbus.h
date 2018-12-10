#ifndef _MODBUS_H
#define _MODBUS_H

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>

int modbus(uint8_t dados_s0,uint8_t dados_s1,uint8_t dados_s2,uint8_t dados_s3);

#endif
