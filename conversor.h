/*
 * conversor.h
 *
 *  Created on: 12 oct. 2020
 *      Author: german
 */

#ifndef SOURCE_CONVERSOR_H_
#define SOURCE_CONVERSOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ENCODER_BITS 8
#define DECODER_BITS 6

/*Devuelve dos archivos abiertos con los nombres dados
 * Return 0 = OK o Return 2= Falló apertura
 * modo=1 -->'w' o modo=0 -->'r'*/
int fileManager(FILE* archivo, char* nombre, int modo);

/*Rellena una cadena de 8 o 6 bits con el codigo binario correspondiente al decimal de la tabla*/
void decimalAbinario (char* cadena,int largoDeLaCadena, int decimalDeLaTabla);

/*Une un valor binario de 8 o 6 bits a una cadena
 *Cuidado con la memoria dinámica!!*/
char* concatenar(char* cadena, char* binario);

/*Devuelve el valor decimal correspondiente a la cadena binaria de 8 o 6 bits recibida*/
int binarioAdecimal (char* cadena[],int largoDeLaCadena);

/*Devuelve el caracter de Base 64 correspondiente al decimal 0-63 dado
 *Devuelve \0 si el decimal no corresponde a la Base */
char caracter64equivalente (int alDecimal);

/*Devuelve el codigo decimal 0-63 correspondiente al caracter ingresado
 *Devuelve -1 si se ingresa un caracter que no pertenece a la Base64*/
int valorBase64Equivalente (char alCaracter);

/*Recibe un archivo de texto ASCII y crea una copia en Base64*/
int encode (char* input,char* output);

/*Recibe un archivo de Texto en Base64 y crea una copia en ASCII*/
int decode (char* input,char* output);

/*Crea un archivo cuando no se pasa el parametro -o*/
char* splitter(char* input,int modo);

#endif /* SOURCE_CONVERSOR_H_ */
