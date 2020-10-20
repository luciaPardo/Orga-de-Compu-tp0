/*
 * binarioAdecimal.c
 *
 *  Created on: 12 oct. 2020
 *      Author: german
 */

#include "conversor.h"

int binarioAdecimal (char* cadena[],int largoDeLaCadena) {

	int decimal=0;
	int potencia=1;
	int peso;

	for(int i=largoDeLaCadena-1; i>-1; i--){

		if (*cadena[i]=='1')
			peso=1;
		else
			peso=0;

		decimal=decimal+peso*potencia;
		potencia=potencia*2;
	}

	return decimal;
}
