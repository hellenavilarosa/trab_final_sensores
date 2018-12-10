#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include "ringbuffer.h"


typedef struct ringbuffer{
	uint8_t size;
	uint8_t rd;
	uint8_t wr;
char buf[16];
} t_ringbuffer;

t_ringbuffer  rbuf;

void init(){
	rbuf.size=0;
	rbuf.rd = 0;
	rbuf.wr = 0;
}

uint8_t rbuf_empty(){


	if ((rbuf.size) == 0){
		return 1;
	} else {
		return 0;
	}
}
uint8_t rbuf_full(){

	if (rbuf.size == 16)
		return 1;
	else
		return 0;
}

char read(){
	char tmp = 0;

	if(! rbuf_empty(rbuf)){
		rbuf.size--;
		tmp = rbuf.buf[rbuf.rd];
		rbuf.rd = (rbuf.rd + 1) % 16;
	}
	return tmp;
}
uint8_t write( char byte){

	if(!rbuf_full()){
		rbuf.size++;
		rbuf.buf[rbuf.wr] = byte;
		rbuf.wr = (rbuf.wr + 1) % 16;
		return 1;
	}
	return 0;
}
