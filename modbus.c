/* modbus.c
 *
 *  Created on: Nov 1, 2018
 *      Author: xtarke
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "lib/avr_usart.h"

uint16_t CRC16_2(uint8_t *buf, int len)
{
  uint32_t crc = 0xFFFF;
  int i;

  for (i = 0; i < len; i++)
  {
    crc ^= (uint16_t)buf[i];          // XOR byte into least sig. byte of crc

    for (int i = 8; i != 0; i--) {    // Loop over each bit
      if ((crc & 0x0001) != 0) {      // If the LSB is set
        crc >>= 1;                    // Shift right and XOR 0xA001
        crc ^= 0xA001;
      }
      else                            // Else LSB is not set
        crc >>= 1;                    // Just shift right
    }
  }
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
  return crc;
}

uint8_t modbus(uint8_t dados_s0,uint8_t dados_s1,uint8_t dados_s2,uint8_t dados_s3){
	uint8_t pkg_sensores[8] = {0x15, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00}; //end, R/W, reg, dados, crc

	uint8_t rx_pkg_sensores[16]; // resposta do modbus
	uint8_t i;
	uint16_t crc;

//PRIMEIRO PACOTE (s0)
	//big_endian
	pkg_sensores[3] =0x05;
	pkg_sensores[4] = dados_s0 >> 8;
	pkg_sensores[5] = dados_s0 & 0xff;

	crc = CRC16_2(pkg_sensores,6);

	pkg_sensores[6] = crc >> 8;
	pkg_sensores[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg_sensores[i]); //enviando para a usart todo o pacote s0

	//esperando resposta (sempre que termina de enviar ele espera a resposta, resposta por interrupção)
	for (i=0; i < 8; i++)
		USART_rx(pkg_sensores[i]); //enviando para a usart todo o pacote s0

	_delay_ms(1000);


//SEGUNDO PACOTE (s1)
	//big_endian
	pkg_sensores[3] =0x06;
	pkg_sensores[4] = dados_s1 >> 8;
	pkg_sensores[5] = dados_s1 & 0xff;

	crc = CRC16_2(pkg_sensores,6);

	pkg_sensores[6] = crc >> 8;
	pkg_sensores[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg_sensores[i]); //enviando para a usart todo o pacote s0

	//esperando resposta (sempre que termina de enviar ele espera a resposta, resposta por interrupção)
	for (i=0; i < 8; i++)
		USART_rx(pkg_sensores[i]); //enviando para a usart todo o pacote s0

	_delay_ms(1000);

//TERCEIRO PACOTE (s2)
	//big_endian
	pkg_sensores[3] =0x07;
	pkg_sensores[4] = dados_s2 >> 8;
	pkg_sensores[5] = dados_s2 & 0xff;

	crc = CRC16_2(pkg_sensores,6);

	pkg_sensores[6] = crc >> 8;
	pkg_sensores[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg_sensores[i]); //enviando para a usart todo o pacote s0

	//esperando resposta (sempre que termina de enviar ele espera a resposta, resposta por interrupção)
	for (i=0; i < 8; i++)
		USART_rx(pkg_sensores[i]); //enviando para a usart todo o pacote s0

	_delay_ms(1000);

//QUARTO PACOTE (s3)
	//big_endian
	//big_endian
	pkg_sensores[3] =0x08;
	pkg_sensores[4] = dados_s3 >> 8;
	pkg_sensores[5] = dados_s3 & 0xff;

	crc = CRC16_2(pkg_sensores,6);

	pkg_sensores[6] = crc >> 8;
	pkg_sensores[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg_sensores[i]); //enviando para a usart todo o pacote s0

	//esperando resposta (sempre que termina de enviar ele espera a resposta, resposta por interrupção)
	for (i=0; i < 8; i++)
		USART_rx(pkg_sensores[i]); //enviando para a usart todo o pacote s0

	_delay_ms(1000);

	_delay_ms(1000);


		//fprintf(,"%d   %d   %d", rx_pkg[5], rx_pkg[7], rx_pkg[9]);
		//cmd_LCD(0xc0,0);
		//fprintf(,"%d", rx_pkg[11]);

		//cmd_LCD(0x80,0);


	return 0;
}
