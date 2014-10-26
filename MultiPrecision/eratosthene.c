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

int bneratoprintf(EArr* tab)
{
	EPr* i=(*tab).begin;
	while(i!=NULL)
	{
		if((*i).isPrime)
		{
			bnprintf((*i).num);
			printf("\n");
		}
		i=(*i).forw;
	}
	return 0;
}

EArr* bneratoInit(BN* maxi)
{
	EArr* tab=malloc(sizeof(EArr));
	EPr* n=malloc(sizeof(EPr));
	BN* cmpt=malloc(sizeof(BN));
	(*tab).begin=n;
	if(n==NULL)
		printf("Echec !!!");
	(*n).backw=NULL;
	for(cmpt=initialize("0");isInferior(cmpt,maxi);cmpt=sum(cmpt,initialize("1")))
	{
		(*n).num=cmpt;
		(*n).isPrime=1;
		(*n).forw=malloc(sizeof(EPr));
		(*(*n).forw).backw=n;
		n=(*n).forw;
	}
	n=(*n).backw;
	free((*n).forw);
	(*n).forw=NULL;
	(*tab).end=n;
	return tab;
}

EArr* bnerato(BN* maxi)
{
	EArr* tab=bneratoInit(maxi);
	EPr* n=(*tab).begin;
	EPr* j=malloc(sizeof(EPr));
	EPr* r=malloc(sizeof(EPr));
	BN* i=malloc(sizeof(BN));
	(*n).isPrime=0;
	n=(*n).forw;
	(*n).isPrime=0;
	n=(*n).forw;
	while(n!=NULL)
	{
/*		printf("Valeur de n :");
		bnprintf((*n).num);
		printf("\n");*/
		if((*n).isPrime==1)
		{
			j=n;
			while(j!=NULL)
			{
				r=j;
				for(i=initialize("1");isInferior(i,(*r).num)&&j!=NULL;i=sum(i,initialize("1")))
				{
/*					bnprintf(i);
					printf("\n");
					bnprintf((*j).num);
					printf("\n");
					printf("%i\n",isInferior(i,(*j).num));*/
					if(j!=NULL)
						j=(*j).forw;
				}
				if(j!=NULL)
				{
					(*j).isPrime=0;
/*					printf("Je raye de la carte");
					bnprintf((*j).num);
					printf("\n");*/
				}
			}
		}
		n=(*n).forw;
	}
	return tab;
}
