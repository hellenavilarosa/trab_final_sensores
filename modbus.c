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
	uint8_t pkg_s0[8] = {0x15, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00}; //end, R/W, reg, dados, crc
	uint8_t pkg_s1[8] = {0x15, 0x01, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00}; //end, R/W, reg, dados, crc
	uint8_t pkg_s2[8] = {0x15, 0x01, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00}; //end, R/W, reg, dados, crc
	uint8_t pkg_s3[8] = {0x15, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00}; //end, R/W, reg, dados, crc

	uint8_t rx_pkg_s0[16]; // resposta do modbus
	uint8_t rx_pkg_s1[16]; // resposta do modbus
	uint8_t rx_pkg_s2[16]; // resposta do modbus
	uint8_t rx_pkg_s3[16]; // resposta do modbus
	uint8_t i;
	uint16_t crc;

//PRIMEIRO PACOTE (s0)
	//big_endian
	pkg_s0[4] = dados_s0 >> 8;
	pkg_s0[5] = dados_s0 & 0xff;

	crc = CRC16_2(pkg_s0,6);

	pkg_s0[6] = crc >> 8;
	pkg_s0[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg_s0[i]); //enviando para a usart todo o pacote s0

	//esperando resposta (sempre que termina de enviar ele espera a resposta, resposta por interrupção)
	for (i=0; i < 8; i++)
		USART_rx(pkg_s0[i]); //enviando para a usart todo o pacote s0

	_delay_ms(1000);


//SEGUNDO PACOTE (s1)
	//big_endian
	pkg_s1[4] = dados_s1 >> 8;
	pkg_s1[5] = dados_s1 & 0xff;

	crc = CRC16_2(pkg_s1,6);

	pkg_s1[6] = crc >> 8;
	pkg_s1[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg_s1[i]); //enviando para a usart todo o pacote s0

	//esperando resposta
	for (i=0; i < 8; i++)
		USART_rx(pkg_s1[i]); //enviando para a usart todo o pacote s0

	_delay_ms(1000);

//TERCEIRO PACOTE (s1)
	//big_endian
	pkg_s2[4] = dados_s2 >> 8;
	pkg_s2[5] = dados_s2 & 0xff;

	crc = CRC16_2(pkg_s1,6);

	pkg_s2[6] = crc >> 8;
	pkg_s2[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg_s2[i]); //enviando para a usart todo o pacote s0

	for (i=0; i < 8; i++)
		USART_rx(pkg_s2[i]);
	//esperando resposta

	_delay_ms(1000);

//QUARTO PACOTE (s1)
	//big_endian
	pkg_s3[4] = dados_s3 >> 8;
	pkg_s3[5] = dados_s3 & 0xff;

	crc = CRC16_2(pkg_s3,6);

	pkg_s3[6] = crc >> 8;
	pkg_s3[7] = crc & 0xff;

	for (i=0; i < 8; i++)
		USART_tx(pkg_s3[i]); //enviando para a usart todo o pacote s0

	//esperando resposta
	for (i=0; i < 8; i++)
		USART_rx(pkg_s3[i]); //enviando para a usart todo o pacote s0

	_delay_ms(1000);


		//fprintf(,"%d   %d   %d", rx_pkg[5], rx_pkg[7], rx_pkg[9]);
		//cmd_LCD(0xc0,0);
		//fprintf(,"%d", rx_pkg[11]);

		//cmd_LCD(0x80,0);


	return 0;
}
