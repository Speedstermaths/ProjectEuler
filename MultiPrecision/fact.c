/*
 * fact.c
 *
 *  Created on: 26 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include"structures.c"

unsigned char isEqual(BN* a,BN* b);

BN* factrec(BN* n)
{
	if(isEqual(n,0))
		return 1;
	else
		return multiply(n,factrec(minus(n,1)));
}
