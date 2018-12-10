#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>


void init();
uint8_t rbuf_empty();
uint8_t rbuf_full();
char read();
uint8_t write( char byte);



#endif /* RINGBUFFER_H_ */
