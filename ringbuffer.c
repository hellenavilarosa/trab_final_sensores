#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include "ringbuffer.h"

#define MAX_SIZE 16
typedef struct ringbuffer {
	int size;
	int rd;
	int wr;
char buf[MAX_SIZE];
} t_ringbuffer;

void init(t_ringbuffer * rbuf){
	rbuf->size = 0;
	rbuf->rd = 0;
	rbuf->wr = 0;
}

uint8_t rbuf_empty(t_ringbuffer * rbuf){
	if (rbuf->size == 0) {
		return 1;
	} else {
		return 0;
	}
}
uint8_t rbuf_full(t_ringbuffer * rbuf){
	if (rbuf->size == MAX_SIZE)
		return 1;
	else
		return 0;
}
char read(t_ringbuffer * rbuf){
	char tmp = 0;
	if(!rbuf_empty(rbuf)){
		rbuf->size--;
		tmp = rbuf->buf[rbuf->rd];
		rbuf->rd = (rbuf->rd + 1) % MAX_SIZE;
	}
	return tmp;
}
uint8_t write(t_ringbuffer * rbuf, char byte){
	if(!rbuf_full(rbuf)){
		rbuf->size++;
		rbuf->buf[rbuf->wr] = byte;
		rbuf->wr = (rbuf->wr + 1) % MAX_SIZE;
		return 1;
	}
	return 0;
}
