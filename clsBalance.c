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
#include <time.h>

void introducirBalance()
{

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

	escribirFichero(nuevoBalance);

	// habria que mirar si coincide y cuadra

}
void escribirFichero(Balance balance)
{
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];
	strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);

	FILE *fp;
	fp = fopen ( "Balance.txt", "w" );

	fprintf(fp, "Balance a %s\n\n",output);

	float totalA = balance.importeANC + balance.importeRealizable + balance.importeDisponible + balance.importeStock;
	fprintf(fp, "TOTAL ACTIVO: %.2f\n",totalA);
	fprintf(fp, "Activo no corriente: %2.f\n",balance.importeANC);
	fprintf(fp, "Activo corriente: %2.f\n",balance.importeStock+balance.importeDisponible + balance.importeRealizable);
	fprintf(fp, "1. Stock: %2.f\n",balance.importeStock);
	fprintf(fp, "2. Realizable: %2.f\n",balance.importeRealizable);
	fprintf(fp, "3. Disponible: %2.f\n",balance.importeDisponible);

	fprintf(fp, "--------------------------\n");

	float totalP = balance.importePC + balance.importePN + balance.importePNC;
	fprintf(fp, "TOTAL PASIVO Y PATRIMONIO NETO: %.2f\n",totalP);
	fprintf(fp, "PAtrimonio neto: %2.f\n",balance.importePN);
	fprintf(fp, "Pasivo no corriente: %2.f\n",balance.importePNC);
	fprintf(fp, "Pasivo corriente: %2.f\n",balance.importePC);

	fclose(fp);

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
