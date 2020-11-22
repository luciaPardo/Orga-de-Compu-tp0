/*
 * valor64.c
 *
 *  Created on: 8 nov. 2020
 *      Author: german
 */

char valor64 (int alDecimal){

	char caracterEquivalente;
	char codigo[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	if ((alDecimal > -1) && (alDecimal<64)){
		caracterEquivalente = codigo[alDecimal];
	} else {
		caracterEquivalente ='\0';
	}

	return caracterEquivalente;

}

