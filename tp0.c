/*
 * tp0.c
 *
 *  Created on: 18 oct. 2020
 *      Author: lucia
 */
#include "conversor.h"

void mensaje_ayuda() {
  	printf("Usage: \n");
	printf("	tp0 -h \n");
	printf("	tp0 -V \n");
	printf("	tp0 [options] \n");
	printf("Options: \n ");
	printf("	-V, --version     Print version and quit.\n" );
	printf("	-h, --help        Print this information. \n");
	printf("	-o, --output      Path to output file. \n");
	printf("	-i, --input       Path to input file. \n");
	printf("	-d, --decode      Decode a base64-encoded file. \n");
	printf("Examples: \n");
	printf("	tp0 -i input.txt -o output.txt \n");
}


int main(int argc, char *argv[]) {

	int modo=0; 			//0:INFO,1:ENCODER,2:DECODER

	char* inputName=NULL;
	char* outputName=NULL;
	int flag=0;
	int ejecutar=0; 		//0:Ejecucion,1:ErrorParametros,2ó+:ErrorDeArchivos
	int end=0;
	int pipe=0; 			//0:Arch-->Arch,1:stdin-->Arch,2:Arch-->stdout,3:stdin-->stdout

	if (argc < 2) {
		//ENCODER DESDE STDIN a STDOUT
		modo=1;
		pipe=3;
  	}

	else if (argc == 2){
		if( strcmp(argv[1], "-h") == 0)
			ejecutar =-1;

		else if (strcmp(argv[1], "-V") == 0) {
			ejecutar = -2;

		} else if (strcmp(argv[1], "-d") == 0){
			//DECODER DESDE STDIN a STDOUT
			modo=2;
			pipe=3;
		} else {
			ejecutar=1;
		}
	}

	else if (argc > 2) {

			for (int i = 1; i < argc ; i++){
				if ((strcmp(argv[i], "-i")) == 0)
					inputName = argv[i + 1];
				if ((strcmp(argv[i], "-o")) == 0)
					outputName = argv[i + 1];
				if ((strcmp(argv[i], "-d")) == 0)
					modo=2;
			}

			if (argc == 3) {

					if (inputName != NULL) {
						//ENCODER DESDE ARCHIVO a STDOUT
						modo=1;
						pipe=2;
					} else if (outputName!=NULL){
						//ENCODER DESDE STDIN a ARCHIVO
						modo=1;
						pipe=1;
					} else {
						ejecutar = 1;
					}

			} else if ((argc == 4) && (modo == 2)){

					if (inputName != NULL) {
						//DECODER DESDE ARCHIVO a STDOUT
						pipe=2;
					} else if (outputName != NULL){
						//DECODER DESDE STDIN a ARCHIVO
						pipe=1;
					} else {
						ejecutar=1;
				}
			} else if ((argc == 5) && (inputName != NULL) && (outputName != NULL)){
				//ENCODER ARCHIVO A ARCHIVO
				modo=1;
				pipe=0;
			} else if ((argc == 6) && (inputName != NULL) && (outputName != NULL) && (modo==2)){
				//DECODER ARCHIVO A ARCHIVO
				pipe=0;
			} else {
				ejecutar=1;
			}
	}

	if (ejecutar == 0){ //--> modo=1 ó 2
		if (modo == 1) {
			flag=encode(inputName,outputName,pipe);
		} else {
			flag=decode(inputName,outputName,pipe);
		}

		if ((flag == 2) || (flag == 4)) {
			 fprintf(stderr,"Error al abrir el archivo de entrada %s.\n",inputName);
		} else if ((flag == 3) || (flag == 5)){
			fprintf(stderr,"Error al abrir el archivo de salida %s.\n",outputName);
		}
	} else	if (ejecutar == 1){
		fprintf(stderr, "Error de parámetros ingresados, para ayuda ingrese -h \n");
	} else if (ejecutar > 1) {
		fprintf(stderr, "Error en archivos, para ayuda ingrese -h \n");
	} else if (ejecutar == -1){
		mensaje_ayuda();
	} else if (ejecutar == -2) {
		printf("Versión del TP: %d \n", VERSION);
	}

	return end;
}
