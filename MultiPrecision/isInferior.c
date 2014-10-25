/*
 * isInferior.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include"structures.c"

unsigned char isInferior(BN* a, BN* b)
{
	unsigned char bool=1;
	DG* i=(*a).head;
	DG* j=(*b).head;
	while(bool==1&&i!=NULL)
	{
		if((*i).cont>(*j).cont)
			bool=0;
		else if((*i).cont<(*j).cont)
			break;
		else
		{
			i=(*i).next;
			j=(*j).next;
		}
	}
	return bool;
}
