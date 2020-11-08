/*
 * clave64.c
 *
 *  Created on: 8 nov. 2020
 *      Author: german
 */

int clave64 (char delCaracter){

	int clave;
	int indice=0;
	char codigo[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	while ((indice<64) && (codigo[indice] != delCaracter)){
		 indice++;
	}

	if (indice < 64){
		clave = indice;
	} else {
		clave = -1;
	}

	return clave;

}
