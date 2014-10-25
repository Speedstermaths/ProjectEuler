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
	BN* c=initialize("3");

	printf("%i\n",divides(a,b));
	printf("%i\n",divides(a,c));
	printf("%i\n",divides(b,c));
	return 0;
}

