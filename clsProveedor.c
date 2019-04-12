/*
 * clsProveedor.c
 *
 *  Created on: 9 abr. 2019
 *      Author: nereasolabarrieta
 */


#include "clsProveedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introducirProveedor()
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

		Proveedor nuevoProveedor;

		for (int i=0; i<strlen(dni); i++)
		{
			nuevoProveedor.dni[i] = dni[i];
		}

		nuevoProveedor.nombre = nom;

		fflush(stdin);
		escribirProveedorEnFic(nuevoProveedor);
}

void escribirProveedorEnFic(Proveedor p)
{

	FILE *fp;
	fp = fopen ( "Proveedores.txt", "a" );

	fprintf(fp, "Nombre: %s\n",p.nombre);
	fprintf(fp, "Dni: %s\n",p.dni);

	fprintf(fp, "------------------------\n");
	fclose(fp);

}

