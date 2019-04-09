/*
 * clsBalance.c
 *
 *  Created on: 9 abr. 2019
 *      Author: nereasolabarrieta
 */

#include "clsBalance.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void introducirBalance()
{
	printf("Introducir datos\n");

	float importeStock;
	printf("Introducir STOCK\n");
	scanf("%f", &importeStock);

	float importeRealizable;
	printf("Introducir REALIZABLE\n");
	scanf("%f", &importeRealizable);

	float importeDisponible;
	printf("Introducir DISPONIBLE\n");
	scanf("%f", &importeDisponible);

	float importeANC;
	printf("Introducir ACTIVO NO CORRIENTE\n");
	scanf("%f", &importeANC);

	float importePC;
	printf("Introducir PASIVO CORRIENTE\n");
	scanf("%f", &importePC);

	float importePNC;
	printf("Introducir PASIVO NO CORRIENTE\n");
	scanf("%f", &importePNC);

	float importePN;
	printf("Introducir PATRIMONIO NETO\n");
	scanf("%f", &importePN);

	Balance nuevoBalance;
	nuevoBalance.importeANC = importeANC;
	nuevoBalance.importeDisponible = importeDisponible;
	nuevoBalance.importePC = importePC;
	nuevoBalance.importePN = importePN;
	nuevoBalance.importePNC = importePNC;
	nuevoBalance.importeRealizable = importeRealizable;
	nuevoBalance.importeStock = importeStock;

}
void escribirFichero(Balance balance)
{

}
bool existsFile(char* filename) {
	FILE* f = NULL;
	f = fopen(filename, "r");
	if (f == NULL)
		return false;
	else {
		fclose(f);
		return true;
	}
}
