/*
 * decoder.c
 *
 *  Created on: 8 nov. 2020
 *      Author: german
 */
#include "conversor.h"

int decoder (FILE* entrada, FILE* salida){

	int flag = 0;
	int lecturas = 0;
	int loop;
	char c = 48;				//0
	char captura[CHARENCODIGO]; //BUFFER de Lectura
	char codigo[CHARPLANO]; 	//BUFFER de escritura

	if (flag == 0){

		while(!feof(entrada) && (c != PAD)){ //Lectura general

			lecturas=0;
			for (loop=0; loop < CHARENCODIGO; loop++){
				captura[loop]=0;
			}

			while (	(!feof(entrada)) && (c != PAD) && (lecturas < CHARENCODIGO) ){ //Lectura parcial
				c = fgetc(entrada);
				if ((c != PAD) && (c != EOF) ){					//Descarto los caracteres de pad
					captura[lecturas] = clave64(c);
							if (captura[lecturas] == -1){	//Corte
								flag = -1;
								c = PAD;
								break;
							}
					lecturas++;
				}
			} /*salgo con 1,2,3 ó 4 lecturas*/

			if ((lecturas != 0) && (flag != -1)) {

				codigo[0] = ((captura[0] << 2) + ((captura[1] & 48) >> 4));
				//Shift <-- 2 + AND 00110000 = 6 bits -Sig de captura[0] + "2 bits +Sig" de captura[1]
				codigo[1] = (((captura[1] & 15) << 4) + ((captura[2] & 60) >> 2));
				//AND 00001111 + Shift <-- 4 + (AND 00111100 + Shift --> 2)  = 4bits -Sig de captura[1] + "4 bits +Sig" de captura[2]
				codigo[2] = (((captura[2] & 3) << 6) + (captura[3] & 63));
				//AND 00000011 + Shift <-- 6 + (AND 00111111) = 2bits -Sig de captura[2] + 6 bits de captura[2]
				//--------------------------------------------------------------------------------------------------------

				if (lecturas == CHARENCODIGO) {
					for(loop=0; loop<CHARPLANO; loop++){
						fputc(codigo[loop],salida);
					}
				} else {
					for(loop=0; loop<lecturas; loop++){
						fputc(codigo[loop],salida);
					}
				}

			}
		}
	}
	fputc(END,salida);
	return flag;
}
