/*
 * isEqual.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include"structures.c"

unsigned char isEqual(BN* a,BN* b)
{
	unsigned char bool=1;
	DG* i=(*a).tail;
	DG* j=(*b).tail;
	while(bool!=0&&i!=NULL)
	{
		if((*i).cont!=(*j).cont)
			bool=0;
		i=(*i).prev;
		j=(*j).prev;
	}
	return bool;
}
