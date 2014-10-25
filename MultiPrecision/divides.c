/*
 * divides.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include"structures.c"

unsigned char isInferior(BN* a, BN* b);
BN* sum(BN* a, BN* b);
unsigned char isEqual(BN* a,BN* b);

unsigned char divides(BN* N, BN* d)
{
	BN* i=d;
	unsigned char bool;
	while(isInferior(i,N))
	{
		i=sum(i,d);
	}
	if(isEqual(i,sum(N,d)))
		bool=1;
	else
		bool=0;
	return bool;
}
