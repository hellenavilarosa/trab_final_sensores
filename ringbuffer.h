#ifndef _RINGBUFFER_H
#define _RINGBUFFER_H

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>

void init(t_ringbuffer *rbuf);
uint8_t rbuf_empty(t_ringbuffer *rbuf);
uint8_t rbuf_full(t_ringbuffer *rbuf);
char read(t_ringbuffer *rbuf);
uint8_t write(t_ringbuffer *rbuf, char byte);


#endif
