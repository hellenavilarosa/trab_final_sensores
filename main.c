/*
 * 03_main_uart_debug.c
 *
 *  Created on: Aug 30, 2018
 *      Author: xtarke
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "lib/avr_usart.h"
#include "sensores.h"
#include "modbus.h"

int main(){

	/* Habilita IRQ global */
	sei();

	uint8_t i=0;

	/* Obtem o stream de depuração */
	FILE *debug = get_usart_stream();

	/* Inicializa hardware da USART */
	USART_Init(B9600);

	/*INICIALIZA�AO DO SENSOR*/
	sensor_init();

	/* Mensagem incial: terminal do Proteus utiliza final de linha com '\r' */
	fprintf(debug,"Teste de debug\n");

	while (1){

		modbus(get_sensor(1),get_sensor(2),get_sensor(3),get_sensor(4)); // dados enviados para o modbus

		for(i=0; i<4; i++){
			fprintf(debug, "%d:  %d\n", i, get_sensor(i));
		}

		_delay_ms(500);
	}
}
