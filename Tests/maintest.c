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
	BN* a;
	EArr* T;

	/*Problème d'affichage console*/
	setvbuf (stdout, NULL, _IONBF, 0);

	a=initialize("7");

	T=bnerato2(a);

	printf("toto\n");

	bneratoprintf(T);

	return 0;
}

