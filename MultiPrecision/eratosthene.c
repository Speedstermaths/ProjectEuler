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
BN* minus(BN* a, BN* b);
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
		if((*n).isPrime==1)
		{
			j=n;
			r=j;
			while(j!=NULL)
			{
				for(i=initialize("1");isInferior(i,(*r).num)&&j!=NULL;i=sum(i,initialize("1")))
				{
					if(j!=NULL)
						j=(*j).forw;
				}
				if(j!=NULL&&(*j).isPrime==1)
				{
					(*j).isPrime=0;
				}
			}
		}
		n=(*n).forw;
	}
	return tab;
}

EArr* bnerato2(BN* maxi)
{
	EArr* tab=bneratoInit(maxi);
	EPr* n=(*tab).begin;
	EPr* j=malloc(sizeof(EPr));
	EPr* r=malloc(sizeof(EPr));
	unsigned short int bool=0;
	n=(*n).forw;
	free((*n).backw);
	n=(*n).forw;
	free((*n).backw);
	(*n).backw=NULL;
	if((*tab).begin=n)
	{
		printf("Bah begin de tab est bien n LOL");
		bnprintf((*(*tab).begin).num);
	}
	while((*n).forw!=NULL)
	{
		bool=0;
		if(((*n).isPrime)&&(n!=NULL))
		{
			printf("n vaut là ici maintenant");
			bnprintf((*n).num);
			j=n;
			r=j;
			while(j!=NULL)
			{
				r=j;
				printf("r vaut maintenant");
				bnprintf((*r).num);
				printf("\n");
				if(bool==0)
				{
					printf("bool vaut 0000\n");
					if(j==NULL)
						printf("J est NULL\n");
					else
						bnprintf((*j).num);
					if(n==NULL)
						printf("merde, n est null");
					printf("Je vais rentrer dans le while...\n");
					printf("j, r, n valent \n");
					bnprintf((*j).num);
					printf("\n");
					bnprintf((*r).num);
					printf("\n");
					bnprintf((*n).num);
					printf("\n");
					if((isInferior((*j).num,sum((*r).num,minus((*n).num,initialize("1"))))))
						printf("Je devrais bien y rentrer dans ce foutu while !");
					while((j!=NULL)&&(r!=NULL)&&(isInferior((*j).num,sum((*r).num,minus((*n).num,initialize("1"))))))
					{
						printf("Dans le while ?");
						if(j!=NULL)
						j=(*j).forw;
						if(j==NULL)
							printf("Je suis rentré, j'ai incrémenté j, et j est NULL...\n");
						if(j!=NULL)
						{
							printf("\n J'avance d'une case et j'ai :");
							bnprintf((*j).num);
							printf(" J'ai avancé d'une case.\n Voici la condition d'arrêt :");
							bnprintf(sum((*r).num,minus((*n).num,initialize("1"))));
							printf("\n");
						}
					}
				}
				else
				{
					while((j!=NULL)&&(r!=NULL)&&(isInferior((*j).num,sum((*r).num,minus((*n).num,initialize("2"))))))
					{
						printf("Je rentre dans le while...\n");
						if(j!=NULL)
						{
							printf("Je vais incrémenter j...");
							j=(*j).forw;
							printf("\n j est maintenant incrémenté.\n j=");
							if(j!=NULL)
								bnprintf((*j).num);
							else
								printf("NULL!");
							printf("\n");
						}
						if(j!=NULL)
						{
							printf("\n J'avance d'une case et j'ai :");
							bnprintf((*j).num);
							printf(" J'ai avancé d'une case.\n Voici la condition d'arrêt :");
							bnprintf(sum((*r).num,minus((*n).num,initialize("2"))));
							printf("\n");
						}
					}
				}
				if(j!=NULL&&(*j).isPrime==1)
				{
					(*j).isPrime=0;
					(*(*j).backw).forw=(*j).forw;
					if((*j).forw!=NULL)
					{
						(*(*j).forw).backw=(*j).backw;
						j=(*j).forw;
						free((*j).backw);
						printf("Je libère mon précédent !");
						bnprintf((*j).num);
						printf("c'est ce que je vaux mainteannt\n");
					}
					else
					{
						j=(*j).backw;
						free((*j).forw);
						(*j).forw=NULL;
					}
					bool=1;
					printf("J'ai passé bool à 1.\n");
				}
			}
		}
		if(n!=NULL)
		{
			if((*n).forw!=NULL)
				n=(*n).forw;
			printf("n vaut");
			if(n!=NULL)
				bnprintf((*n).num);
			else
				printf("NULL!");
			printf("\n");
		}
	}
	printf("Je quitte mon cher while...\n");
	n=(*n).backw;
	printf("\n J'ai reculé ! Je vais libérer mon suivant...");
	if((*n).forw!=NULL)
		free((*n).forw);
	else
		printf("C'était pas la peine en fait ^^\n");
	printf("C'est fait !");
	(*tab).end=n;
	printf("C'est la fin, you know.\n\n");
	return tab;
}
