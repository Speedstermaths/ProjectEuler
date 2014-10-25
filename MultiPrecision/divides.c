/*
 * divides.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include"structures.c"

unsigned char divides(BN* N, BN* d)
{
	BN* i=d;
	unsigned char bool;
	while(isInferior(i,N))
	{
		i=sum(i,i);
	}
	if(isEqual(i,N))
		bool=1;
	else
		bool=0;
	return bool;
}
