/*
 * bnprintf.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include<stdio.h>
#include"structures.c"

int bnprintf(BN* n)
{
	DG* i=(*n).head;
	while(i!=NULL)
	{
		printf("%c",(*i).cont);
		i=(*i).next;
	}
	return 0;
}
