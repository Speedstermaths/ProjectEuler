/*
 * minus.c
 *
 *  Created on: 26 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include"structures.c"

BN* minus(BN* a, BN* b)
{
	BN* delta=initialize("0");
	while(isInferior(sum(a,delta),a))
	{
		delta=sum(delta,initialize("1"));
	}
	return delta;
}
