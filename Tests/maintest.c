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

	/*Problème d'affichage console*/
	setvbuf (stdout, NULL, _IONBF, 0);

	a=initialize("7");

	bneratoprintf(bnerato(7));

	return 0;
}

