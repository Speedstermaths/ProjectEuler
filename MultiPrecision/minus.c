/*
 * minus.c
 *
 *  Created on: 26 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include"structures.c"

BN* sum(BN* a, BN* b);

BN* minus(BN* a, BN* b)
{
	BN* delta=initialize("0");
	while(isInferior(sum(sum(b,delta),initialize("1")),a))
	{
		delta=sum(delta,initialize("1"));
	}
	return delta;
}
