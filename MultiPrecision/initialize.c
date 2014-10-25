/*
 * initialize.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"structures.c"

BN* initialize(char* str)
{
	BN* n=malloc(sizeof(BN));
	char* j=str;
	DG* i=malloc(sizeof(DG));
	(*n).head=i;
	(*i).prev=NULL;
	unsigned int cmpt=size;
	while(cmpt>0)
	{
		if(cmpt>strlen(str))
			(*i).cont=0;
		else
			{
				(*i).cont=*j;
				j++;
			}
		(*i).pow=cmpt-1;
		(*i).next=malloc(sizeof(DG));
		(*(*i).next).prev=i;
		i=(*i).next;
		cmpt--;
	}
	i=(*i).prev;
	free((*i).next);
	(*i).next=NULL;
	(*n).tail=i;
	return n;
}
