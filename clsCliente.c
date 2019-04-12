/*
 * clsCliente.c
 *
 *  Created on: 9 abr. 2019
 *      Author: nereasolabarrieta
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clsCliente.h"

void introducirCliente()
{

	char dni[10];
	printf("Introduce DNI\n");
	scanf("%s", dni);
	fflush(stdin);

	char *nom;
	nom = (char*) malloc (sizeof(char));
	printf("Introduce NOMBRE\n");
	scanf("%s", nom);
	fflush(stdin);

	char *ape;
	ape = (char*) malloc (sizeof(char));
	printf("Introduce APELLIDO\n");
	scanf("%s", ape);


	Cliente nuevoCliente;
	nuevoCliente.ape = ape;
	for (int i=0; i<strlen(dni); i++)
	{
		nuevoCliente.dni[i] = dni[i];
	}

	nuevoCliente.nombre = nom;

	fflush(stdin);
	escribirClienteEnFic(nuevoCliente);

}
void escribirClienteEnFic(Cliente c)
{

	FILE *fp;
	fp = fopen ( "Clientes.txt", "a" );


	fprintf(fp, "Nombre: %s\n",c.nombre);
	fprintf(fp, "Apellido: %s\n",c.ape);
	fprintf(fp, "Dni: %s\n",c.dni);

	fprintf(fp, "------------------------\n");


	fclose(fp);

}

