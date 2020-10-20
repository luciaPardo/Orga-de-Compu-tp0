/*
 * concatenar.c
 *
 *  Created on: 12 oct. 2020
 *      Author: german
 *
 */
#include "conversor.h"

char* concatenar(char* cadena, char* binario) {
	char* concatenado = malloc(strlen(cadena) + strlen(binario) + 1); // +1 para \0
	    strcpy(concatenado, cadena);
	    strcat(concatenado, binario);
	    return concatenado;
}


