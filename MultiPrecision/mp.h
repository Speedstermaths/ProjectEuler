/*
 * mp.h
 *
 *  Created on: 25 oct. 2014
 *      Author: Franck
 */

#ifndef MP_H_
#define MP_H_
#include"structures.c"

BN* initialize(char* str);

int bnprintf(BN* n);

BN* sum(BN* a, BN* b);

unsigned char isEqual(BN* a,BN* b);

unsigned char divides(BN* N, BN* d);

unsigned char isInferior(BN* a, BN* b);

EArr* bneratoInit(BN* maxi);

EArr* bnerato(BN* maxi);

int bneratoprintf(EArr* tab);

#endif /* MP_H_ */
