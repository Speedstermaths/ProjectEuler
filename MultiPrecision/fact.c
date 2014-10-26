/*
 * fact.c
 *
 *  Created on: 26 oct. 2014
 *      Author: Franck
 */

#include"structures.c"

BN* initialize(char* str);
BN* minus(BN* a, BN* b);
unsigned char isInferior(BN* a, BN* b);
BN* multiply(BN* a, BN* b);

BN* fact(BN* n)
{
	BN* fac=n;
	BN* i=n;
	while(isInferior(initialize("2"),i))
	{
		fac=multiply(fac,minus(i,initialize("1")));
		i=minus(i,initialize("1"));
	}
	return fac;
}
