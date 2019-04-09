/*
 * clsBalance.h
 *
 *  Created on: 9 abr. 2019
 *      Author: nereasolabarrieta
 */
#include <stdbool.h>
#ifndef CLSBALANCE_H_
#define CLSBALANCE_H_

typedef struct
{
	float importeStock;
	float importeRealizable;
	float importeDisponible;
	float importeANC;
	float importePC;
	float importePNC;
	float importePN;
}Balance;

void introducirBalance();
void escribirFichero(Balance);
bool existsFile(char*);

#endif /* CLSBALANCE_H_ */
