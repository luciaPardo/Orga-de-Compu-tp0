/*
 * decoder64.c
 *
 *  Created on: 13 oct. 2020
 *      Author: german
 */

int valorBase64Equivalente (char alCaracter) {

	char codigo[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
						'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
						'0','1','2','3','4','5','6','7','8','9','+','/','\0'};

	int decimal=0;

	while (codigo[decimal]!=alCaracter){
		if(decimal<63)
		decimal++;
		else
		decimal = -1;
	}

	return decimal;
}
