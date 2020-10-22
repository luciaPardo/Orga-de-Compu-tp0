/*
 * decode.c
 *
 *  Created on: 18 oct. 2020
 *      Author: german
 */
#include "conversor.h"

int decode (char* input, char*output, int pipe){

	int flag=0;
	FILE* entrada;
	FILE* salida;

	if ((pipe == 0) || (pipe == 2)){
		entrada = fopen(input,"r");
		if (entrada == NULL) {
			  flag=2;
		}
	} else {
		entrada = stdin;
	}
	if ((pipe == 0) || (pipe == 1)) {
		salida = fopen(output,"w");
		if (salida == NULL) {
			flag=3;
		}
	} else {
		salida = stdout;
	}

	if (flag == 0){
	char c;
	int decimalBase64,bits,multiplo8,caracteresASCII,posicionEnCadenaDeBits,decimalAscii;

	char* caracterActualBinario = (char*)calloc(DECODER_BITS,sizeof(char));
	char* cadenaDeBits = (char*)calloc(DECODER_BITS,sizeof(char));
	char* temporal;
	char* cadenaAcodificar[ENCODER_BITS+1];

	if (!feof(entrada)){
		c=fgetc(entrada); //traducir-->sobreescribir c
		decimalBase64 = valorBase64Equivalente(c);
		if(decimalBase64==-1){
			fprintf(stderr,"El texto ingresado no corresponde a la codificación en Base 64\n");
		}
		decimalAbinario(cadenaDeBits,DECODER_BITS,decimalBase64);

		c=fgetc(entrada);
		while(!feof(entrada)){
			if(c != '='){ //Ignoro los pads
				decimalBase64 = valorBase64Equivalente(c);
				if (decimalBase64!=-1){
					decimalAbinario(caracterActualBinario,DECODER_BITS,decimalBase64);

						temporal= concatenar(cadenaDeBits,caracterActualBinario);
						cadenaDeBits = (char *) realloc(cadenaDeBits, strlen(temporal) + 1);
						strcpy(cadenaDeBits, temporal);
						free(temporal);
						temporal=NULL;
				} else {
					flag=-1;
					break;
				}
			}
			c=fgetc(entrada);
		}
		if (flag != -1){
			bits=strlen(cadenaDeBits);
			multiplo8=bits%ENCODER_BITS;
			if(multiplo8 != 0){
				for (int i=0; i<multiplo8; i++){
					cadenaDeBits[bits-i]='\0';
				}
			}
			bits=strlen(cadenaDeBits);
			caracteresASCII=bits/ENCODER_BITS;
			posicionEnCadenaDeBits=0;

			for(int i=0; i<caracteresASCII; i++){
				for (int j=0;j<ENCODER_BITS;j++){
						posicionEnCadenaDeBits=i*ENCODER_BITS+j;
						cadenaAcodificar[j]=&(cadenaDeBits[posicionEnCadenaDeBits]);
				}
				cadenaAcodificar[ENCODER_BITS]='\0';
				decimalAscii=binarioAdecimal(cadenaAcodificar,ENCODER_BITS);
				c=decimalAscii;
				fputc(c,salida);
			}

		}
	}
	if ((pipe == 0) || (pipe == 2)){
		fclose(entrada);
	}
	if ((pipe == 0) || (pipe == 1)) {
		fclose(salida);
	}

	free(caracterActualBinario);
	caracterActualBinario=NULL;
	free(cadenaDeBits);
	cadenaDeBits=NULL;
	}

	return flag;
}
