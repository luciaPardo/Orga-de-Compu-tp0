/*
 * help.c
 *
 *  Created on: 8 nov. 2020
 *      Author: german
 */
#include "conversor.h"

void mensajeAyuda() {
  	fprintf(stderr,"Usage: \n");
	fprintf(stderr,"	tp0 -h \n");
	fprintf(stderr,"	tp0 -V \n");
	fprintf(stderr,"	tp0 [options] \n");
	fprintf(stderr,"Options: \n ");
	fprintf(stderr,"	-V, --version     Print version and quit.\n" );
	fprintf(stderr,"	-h, --help        Print this information. \n");
	fprintf(stderr,"	-o, --output      Path to output file. \n");
	fprintf(stderr,"	-i, --input       Path to input file. \n");
	fprintf(stderr,"	-d, --decode      Decode a base64-encoded file. \n");
	fprintf(stderr,"Examples: \n");
	fprintf(stderr,"	tp0 -i input.txt -o output.txt \n");
}

