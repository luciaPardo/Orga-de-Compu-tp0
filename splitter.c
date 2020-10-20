/*
 * splitter.c
 *
 *  Created on: 18 oct. 2020
 *      Author: german
 */

#include "conversor.h"

char* splitter(char* input, int modo){

	char* aux=malloc(strlen(input));
	strcpy(aux,input);

	char* nombre = malloc(strlen(input) + 3);
	char delimitador[] = ".";
    char *token = strtok(aux, delimitador);
    if(token != NULL){
            strcpy(nombre,token);
    }

    if(modo==0){
    	char sufijo[]= "B64";
    	strcat(nombre,sufijo);
    }else {
    	char sufijo[]= "Asc";
    	strcat(nombre,sufijo);
    }
    char ext[]=".txt";
    strcat(nombre,ext);

    free(aux);
    fprintf(stderr,"Se ha creado el archivo de salida %s por defecto\n",nombre);

    return nombre;
}
