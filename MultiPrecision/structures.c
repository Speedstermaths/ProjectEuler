/*
 * structures.c
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#define size 20

typedef struct digit
{
	struct digit* prev;
	unsigned char cont;
	unsigned char pow;
	struct digit* next;
}DG;

typedef struct bignumber
{
	DG* head;
	DG* tail;
}BN;
