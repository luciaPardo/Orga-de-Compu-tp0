/*
 * encoder.c
 *
 *  Created on: 8 nov. 2020
 *      Author: german
 */
#include "conversor.h"

int encoder (FILE* entrada, FILE* salida){

	int flag = 0;
	int lecturas = 0;
	int escribir = 0;
	int loop;
	char c = 48;				//0
	char captura[CHARPLANO];	//BUFFER de Lectura
	char codigo[CHARENCODIGO]; //BUFFER de escritura

	if (flag == 0){

		while(!feof(entrada) && (c != HALT)){ //Lectura general

			lecturas=0;
			for (loop=0; loop<CHARPLANO; loop++){
				captura[loop]=0;
			}

			while ((!feof(entrada)) && (c != HALT) && (lecturas < CHARPLANO)){ //Lectura parcial
				c = fgetc(entrada);
				if ((c != EOF) && (c != HALT)) {
					captura[lecturas]= c;
					lecturas++;
				}
			} //salgo con 1,2 o 3 lecturas

			if (lecturas != 0) {
				escribir = lecturas+1;

				codigo[0] = valor64 ((captura[0] & 252) >> 2);
				//AND 11111100 + Shift --> 2 = 6 bits +Sig de captura[0]
				codigo[1] = valor64 (((captura[0] & 3) << 4) + ((captura[1] & 240) >> 4));
				//AND 00000011 + Shift <-- 4 + (AND 11110000 + Shift --> 4)  = 2bits -Sig de captura[0] + 4 bits +Sig de captura[1]
				codigo[2] = valor64 (((captura[1] & 15) << 2) + ((captura[2] & 192) >> 6));
				//AND 00001111 + Shift <-- 2 + (AND 11000000 + Shift --> 6 ) = 4bits -Sig de captura[1] + 2 bits +Sig de captura[2]
				codigo[3] = valor64 ((captura[2] & 63));
				//AND 00111111 = 6 bits -Sig de captura[2]
				//--------------------------------------------------------------------------------------------------------

				for(loop=0; loop<escribir; loop++){
					fputc(codigo[loop],salida);
				}
				if (lecturas<CHARPLANO){
					for (loop=0; loop<(CHARENCODIGO-escribir); loop++){
						fputc(PAD,salida);
					}
				}

			}
		}

	}
	fputc(END,salida);
	return flag;
}
