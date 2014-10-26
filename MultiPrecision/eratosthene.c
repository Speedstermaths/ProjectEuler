/*
 * eratosthene.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#include<stdlib.h>
#include"structures.c"
#include<stdio.h>

BN* initialize(char* str);
unsigned char isInferior(BN* a, BN* b);
BN* sum(BN* a, BN* b);
int bnprintf(BN* n);

EArr* bneratoInit(BN* maxi)
{
	EArr* tab=malloc(sizeof(EArr));
	EPr* n=(*tab).head;
	BN* cmpt=malloc(sizeof(BN));
	(*n).prev=NULL;
	for(cmpt=initialize("0");isInferior(cmpt,maxi);cmpt=sum(cmpt,initialize("1")))
	{
		(*n).num=cmpt;
		(*n).isPrime=1;
		(*n).next=malloc(sizeof(EPr));
		(*(*n).next).prev=n;
		n=(*n).next;
	}
	n=(*n).prev;
	free((*n).next);
	(*n).next=NULL;
	(*tab).tail=n;
	return tab;
}

EArr* bnerato(BN* maxi)
{
	EArr* tab=bneratoInit(maxi);
	EPr* n=(*tab).head;
	EPr* j;
	BN* i;
	(*n).isPrime=0;
	n=(*n).next;
	(*n).isPrime=0;
	n=(*n).next;
	while(n!=NULL)
	{
		if((*n).isPrime==1)
		{
			j=n;
			while(isInferior((*j).num,maxi))
			{
				for(i=initialize("1");isInferior(i,(*j).num);i=sum(i,initialize("1")))
				{
					n=(*n).next;
				}
				(*n).isPrime=0;
				printf("Je raye de la carte");
				bnprintf((*n).num);
				j=n;
			}
		}
	}
	return tab;
}
