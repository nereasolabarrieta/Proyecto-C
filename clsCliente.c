/*
 * clsCliente.c
 *
 *  Created on: 13/4/2019
 *      Author: ALUMNO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clsCliente.h"

#define TAMANYO 30

void introducirCliente(Cliente * nuevoCliente) {
	nuevoCliente->dni = malloc(10 * sizeof(char));
	printf("Introduce DNI:\n");
	fflush(stdin);
	scanf("%s", nuevoCliente->dni);

	char *nom;
	nom = (char*) malloc(TAMANYO * sizeof(char));
	printf("Introduce NOMBRE\n");
	fflush(stdin);
	scanf("%s", nom);

	int len = strlen(nom);
	nuevoCliente->nom = (char*) malloc(len * sizeof(char));
	strcpy(nuevoCliente->nom, nom);

	char *ape;
	ape = (char*) malloc(TAMANYO * sizeof(char));
	printf("Introduce APELLIDO\n");
	fflush(stdin);
	scanf("%s", ape);

	len = strlen(ape);
	nuevoCliente->ape = (char*) malloc(len * sizeof(char));
	strcpy(nuevoCliente->ape, ape);

	nuevoCliente->acumulado = 0;

	fflush(stdin);
	escribirClienteEnFic(*nuevoCliente);

}

void escribirClienteEnFic(Cliente c) {

	FILE *fp;
	fp = fopen("Clientes.txt", "a");

	fprintf(fp, "%s,", c.nom);
	fprintf(fp, "%s,", c.ape);
	fprintf(fp, "%s,", c.dni);
	fprintf(fp, "%i\n", c.acumulado);

	fprintf(fp, "------------------------\n");

	fclose(fp);

}

void lecturaFicheroCliente() {
	FILE *f;
	f = fopen("Clientes.txt", "r");
	char *c;
	char caracter;
	c = (char*) malloc(sizeof(char));
	while ((caracter = fgetc(f)) != EOF) {
		fgets(c, sizeof(Cliente), f);
		printf("%s\n", c);
	}
	fclose(f);
}

void imprimirCliente(Cliente cl) {
	printf("Nombre %s %s, dni: %s, dinero: %i euro\n", cl.nom, cl.ape, cl.dni,
			cl.acumulado);
}

