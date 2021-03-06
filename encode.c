/*
 * encode.c
 *
 *  Created on: 18 oct. 2020
 *      Author: german
 */
#include "conversor.h"

int encode (char*input, char*output){

	FILE* entrada = fopen(input,"r");
		if (entrada == NULL) {
		  fprintf(stderr,"Error al abrir el archivo fuente.\n");
		  return 1;
		}
	FILE* salida = fopen(output,"w");
		if (salida == NULL) {
			fprintf(stderr,"Error al abrir el archivo de salida.\n");
			return 2;
		}
	char c;
	char cero = '0';
	char igual = '=';
	int decimalAscii,multiplo6,cerosAagregar,caracteresEnBase64,posicionEnCadenaDeBits,decimalBase64,multiplo4,igualesAagregar,bits;
	char* caracterActualBinario = (char*)calloc(ENCODER_BITS,sizeof(char));
	char* cadenaDeBits = (char*)calloc(ENCODER_BITS,sizeof(char));
	char* temporal;
	char* cadenaAcodificar[DECODER_BITS+1];

	if (!feof(entrada)){
		c=fgetc(entrada); //traducir-->sobreescribir c
		decimalAscii=c;
		decimalAbinario(cadenaDeBits,ENCODER_BITS,decimalAscii);

		c=fgetc(entrada);
		while(!feof(entrada)){
			decimalAscii=c;
			decimalAbinario(caracterActualBinario,ENCODER_BITS,decimalAscii);

			temporal= concatenar(cadenaDeBits,caracterActualBinario);
			cadenaDeBits = (char *) realloc(cadenaDeBits, strlen(temporal) + 1);
			strcpy(cadenaDeBits, temporal);
			free(temporal);
			temporal=NULL;

			c=fgetc(entrada);
		}

		bits=strlen(cadenaDeBits);
		multiplo6=bits%DECODER_BITS;
		if(multiplo6!=0){
			cerosAagregar=DECODER_BITS-multiplo6;
			for (int i=0; i<cerosAagregar; i++){
					strncat(cadenaDeBits, &cero,1);
			}
		}
		bits=strlen(cadenaDeBits);
		caracteresEnBase64=bits/DECODER_BITS;
		multiplo4=caracteresEnBase64%4;
		posicionEnCadenaDeBits=0;

		for(int i=0; i<caracteresEnBase64; i++){
			for (int j=0;j<DECODER_BITS;j++){
					posicionEnCadenaDeBits=i*DECODER_BITS+j;
					cadenaAcodificar[j]=&(cadenaDeBits[posicionEnCadenaDeBits]);
			}
			cadenaAcodificar[DECODER_BITS]='\0';
			decimalBase64=binarioAdecimal(cadenaAcodificar,DECODER_BITS);
			c=caracter64equivalente(decimalBase64);
			fputc(c,salida);
		}

		if (multiplo4!=0){
			igualesAagregar=4-multiplo4;
			for (int i=0; i<igualesAagregar; i++){
				fputc(igual,salida);
			}
		}
	}


	fclose(entrada);
	fclose(salida);

	free(caracterActualBinario);
	caracterActualBinario=NULL;
	free(cadenaDeBits);
	cadenaDeBits=NULL;

	return 0;
}
