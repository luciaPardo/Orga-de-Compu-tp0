/*
 * conversor.h
 *
 *  Created on: 8 nov. 2020
 *      Author: german
 */

#ifndef SRC_CONVERSOR_H_
#define SRC_CONVERSOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define VERSION 'R'
#define CHARPLANO 3
#define CHARENCODIGO 4
#define PAD 61
#define HALT 92
#define END 10

/*Devuelve el caracter de Base 64 correspondiente al decimal 0-63 dado
 *Devuelve \0 si el decimal no corresponde a la Base */
char valor64 (int alDecimal);

/*Devuelve el indice 0-63 correspondiente al caracter c dado
 *Devuelve -1 si el caracter no corresponde a la Base64 */
int clave64 (char c);

/*Recibe un archivo de texto ASCII y crea una copia en Base64*/
int encoder (FILE* input, FILE* output);

/*Recibe un archivo de Texto en Base64 y crea una copia en ASCII*/
int decoder (FILE* input, FILE* output);

/*Imprime un mensaje*/
void mensajeAyuda();

#endif /* SRC_CONVERSOR_H_ */
