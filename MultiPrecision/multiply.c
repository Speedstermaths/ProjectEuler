/*
 * multiply.c
 *
 *  Created on: 26 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include"structures.c"

BN* initialize(char* str);
unsigned char isInferior(BN* a, BN* b);
BN* sum(BN* a, BN* b);

BN* multiply(BN* a, BN* b)
{
	BN* cmpt;
	BN* prod;
	prod=initialize("0");
	for(cmpt=initialize("1");isInferior(cmpt,b);cmpt=sum(cmpt,initialize("1")))
	{
		prod=sum(prod,a);
	}
	return prod;
}
