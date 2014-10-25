/*

 * maintest.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include"../MultiPrecision/mp.h"
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	/*Problème d'affichage console*/
	setvbuf (stdout, NULL, _IONBF, 0);
	BN* a=initialize("120");
	BN* b=initialize("10");
	BN* c=initialize("125");
	BN* d=initialize("5");

	printf("%i\n",isInferior(a,b));
	printf("%i\n",isInferior(b,c));
	printf("%i\n",isInferior(a,c));
	printf("%i\n",isInferior(a,d));
	return 0;
}

