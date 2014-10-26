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
	BN* a=initialize("600851475143");

	EArr* tab=bnerato(a);

	bneratoprintf(tab);

	return 0;
}

