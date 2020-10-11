#include <stdio.h>
#include <string.h>
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
	char ret[2];
	if (argc < 2) {
		printf("Error de cantidad de parámetros ingresados, para ayuda ingrese -h \n");
		return -1;
  	}

	if (argc == 2 && strcmp(argv[1], "-h") == 0)
		mensaje_ayuda();

	else if (strcmp(argv[1], "-V") == 0) {
		printf("versión del tp: %d \n", VERSION);
		return 0;
  	}

	else if (argc >= 3) {
		int i;
		for (i = 1; i <= argc ; i++){
			if ((strcmp(argv[i], "-i")) == 0) 
				input = argv[i + 1];
			if ((strcmp(argv[i], "-o")) == 0) 
				output = argv[i + 1];
			if (input != NULL && (strcmp(argv[i], "-d")) != 0)
				//decode(input);	
				continue;
		}
	}
  return 0;
}
