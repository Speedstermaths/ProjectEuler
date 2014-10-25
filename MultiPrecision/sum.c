/*
 * sum.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include<stdio.h>
#include"structures.c"

BN* sum(BN* a, BN* b)
{
	BN* S=malloc(sizeof(BN));
	DG* i=(*a).tail;
	DG* j=(*b).tail;
	DG* s=malloc(sizeof(DG));
	(*s).next=NULL;
	(*S).tail=s;
	unsigned short carry=0;
	unsigned short int cmpt=0;
	while((i!=NULL)||(j!=NULL))
	{
		(*s).pow=cmpt;
		if((*i).cont!=0&&(*j).cont!=0)
		{
			(*s).cont=((*i).cont-48+(*j).cont-48+carry)%10+48;
			carry=((*i).cont-48+(*j).cont-48+carry)/10;
		}
		else if((*i).cont==0&&(*j).cont!=0)
		{
			(*s).cont=((*j).cont-48+carry)%10+48;
			carry=(0+(*j).cont-48+carry)/10;
		}
		else if((*i).cont!=0&&(*j).cont==0)
		{
			(*s).cont=((*i).cont-48+carry)%10+48;
			carry=((*i).cont-48+0+carry)/10;
		}
		else if((*i).cont==0&&(*j).cont==0)
		{
			(*s).cont=carry%10+48;
			carry=(0+carry)/10;
		}
		(*s).prev=malloc(sizeof(DG));
		(*(*s).prev).next=s;
		s=(*s).prev;
		cmpt++;
		i=(*i).prev;
		j=(*j).prev;
	}
	{
		s=(*s).next;
		free((*s).prev);
		(*s).prev=NULL;
		(*S).head=s;
	}
	return S;
}
