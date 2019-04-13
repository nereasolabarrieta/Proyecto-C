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

void introducirCliente(Cliente * nuevoCliente)
{
	char *dni=malloc(10*sizeof(char));
	printf("Introduce DNI:\n");
	fflush(stdin);
	scanf("%s", dni);

	char *nom;
	nom = (char*) malloc (TAMANYO*sizeof(char));
	printf("Introduce NOMBRE\n");
	fflush(stdin);
	scanf("%s", nom);

	char *nombre;
	int len = strlen(nom);
	nombre = (char*) malloc (len*sizeof(char));
	strcpy(nombre,nom);



	char *ape;
	ape = (char*) malloc (TAMANYO*sizeof(char));
	printf("Introduce APELLIDO\n");
	fflush(stdin);
	scanf("%s", ape);

	char *apellido;
	len = strlen(ape);
	apellido = (char*) malloc (len*sizeof(char));
	strcpy(apellido,ape);



	nuevoCliente->nom=nombre;
	nuevoCliente->ape = apellido;
	nuevoCliente->dni = dni;
	nuevoCliente->acumulado=0;

	fflush(stdin);
	escribirClienteEnFic(*nuevoCliente);
	free(nom);
	free(ape);
}
void escribirClienteEnFic(Cliente c)
{

	FILE *fp;
	fp = fopen ( "Clientes.txt", "a" );

	fprintf(fp, "Nombre: %s\n",c.nom);
	fprintf(fp, "Apellido: %s\n",c.ape);
	fprintf(fp, "Dni: %s\n",c.dni);
	fprintf(fp, "Dinero Acumulado: %i\n",c.acumulado);

	fprintf(fp, "------------------------\n");


	fclose(fp);

}
void ImprimirCliente(Cliente cl)
{

	printf("[Nombre: %s, Apellido: %s, DNI: %s, Dinero Acumulado: %i ]\n",cl.nom,cl.ape, cl.dni,cl.acumulado);
}



