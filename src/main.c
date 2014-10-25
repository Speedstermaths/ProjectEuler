/*
 * main.c
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

	bnprintf(sum(initialize("123"),initialize("123")));
	return 0;
}
