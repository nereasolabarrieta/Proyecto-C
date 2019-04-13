/*
 * clsArticulo.c
 *
 *  Created on: 13/4/2019
 *      Author: ALUMNO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clsArticulo.h"

void anyadirArticulo()
{
	int opcion;
	do{

	printf("¿Que tipo de articulo desea introducir?\n");
	printf("1-Complemento\n");
	printf("2-Textil\n");

	fflush(stdin);
	scanf("%d", &opcion);
	switch (opcion)
	{
	case 1: anyadirComplemento();
		break;
	case 2: anyadirTextil();
		break;

	default: printf("Esa opcion no existe.");
	}
	}while(opcion != 3);



}

void anyadirComplemento()
{
	char codigo[10];
	printf("Introduce el codigo:\n");
	fflush(stdin);
	scanf("%s", codigo);


	char *descripcion;
	descripcion = (char*) malloc (sizeof(char));
	printf("Introduce la descripcion:\n");
	fflush(stdin);
	scanf("%s", descripcion);

	float precio;
	printf("Introduce el precio:\n");
	fflush(stdin);
	scanf("%f", precio);
}

void anyadirTextil()
{
	char codigo[10];
	printf("Introduce el codigo:\n");
	fflush(stdin);
	scanf("%s", codigo);


	char *descripcion;
	descripcion = (char*) malloc (sizeof(char));
	printf("Introduce la descripcion:\n");
	fflush(stdin);
	scanf("%s", descripcion);

	float precio;
	printf("Introduce el precio:\n");
	fflush(stdin);
	scanf("%f", precio);
}
