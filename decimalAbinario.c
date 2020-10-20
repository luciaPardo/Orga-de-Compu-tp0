/*
 * decimalAbinario.c
 *
 *  Created on: 12 oct. 2020
 *      Author: german
 */
#include "conversor.h"

void decimalAbinario (char* cadena,int largoDeLaCadena, int decimalDeTabla) {

	int decimal = decimalDeTabla;

	for(int i=0; i<largoDeLaCadena; i++){
		cadena[i] = '0';
	}

	int contador = largoDeLaCadena;
	cadena[contador]='\0';

	while(decimal > 0){
		contador--;

		if(decimal%2 == 0)
			cadena[contador] = '0';
		else
			cadena[contador] = '1';

		decimal = decimal/2;
	}


}

