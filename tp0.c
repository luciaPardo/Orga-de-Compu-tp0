/*
 * tp0.c
 *
 *  Created on: 18 oct. 2020
 *      Author: lucia
 */
#include "conversor.h"
#define VERSION 0
#define MAX_BUFF 100


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
	char* input;
	char* output;
	int modo=0;
	int flag=1;

	if (argc < 2) {
		fprintf(stderr, "Error de cantidad de parámetros ingresados, para ayuda ingrese -h \n");
		return -1;
  	}

	if (argc == 2 && strcmp(argv[1], "-h") == 0)
		mensaje_ayuda();

	else if (strcmp(argv[1], "-V") == 0) {
		printf("Versión del TP: %d \n", VERSION);
		return 0;
  	}

	else if (argc > 2) {
		int i;
		for (i = 1; i < argc ; i++){
			if ((strcmp(argv[i], "-i")) == 0)
				input = argv[i + 1];
			if ((strcmp(argv[i], "-o")) == 0)
				output = argv[i + 1];
			if ((strcmp(argv[i], "-d")) == 0)
				modo=1;
		}
			if (input != NULL && modo != 0) {
				flag=decode(input,output);
				while(flag!=0){
					if (flag==3){
						return 3;
					}else if (flag==4){
						output=splitter(input,modo);
						flag=decode(input,output);
						free(output);
					}
				}

			} else if (input != NULL) {
				flag=encode(input,output);
				while(flag!=0){
					if (flag==1){
						return 1;
					}else if (flag==2){
						output=splitter(input,modo);
						flag=encode(input,output);
						free(output);
					}
				}

			}
	}
  return 0;
}
