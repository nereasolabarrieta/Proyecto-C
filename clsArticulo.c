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
#define TAMANYO 10
void anyadirArticulo() {
	int opcion;
	do {

		printf("Que tipo de articulo desea introducir?\n");
		printf("1-Complemento\n");
		printf("2-Textil\n");

		fflush(stdin);
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			anyadirComplemento();
			break;
		case 2:
			anyadirTextil();
			break;

		default:
			printf("Esa opcion no existe.");
		}
	} while (opcion != 3);

}

void anyadirComplemento() {
	char codigo[10];
	printf("Introduce el codigo:\n");

	scanf("%s", codigo);
	fflush(stdin);

	char *descripcion;
	descripcion = (char*) malloc(sizeof(char));
	printf("Introduce la descripcion:\n");

	scanf("%s", descripcion);
	fflush(stdin);

	float precio;
	printf("Introduce el precio:\n");

	scanf("%f", &precio);
	fflush(stdin);

	Articulo a;
	a.codigo = codigo;
	a.descripcion = descripcion;
	a.precio = precio;

	escrituraAFic(a);

	Complemento t;
	t.articulo = a;

	int stock;
	printf("Introduce stock\n");
	scanf("%i", &stock);

	t.stock = stock;
	escrituraComplemento(t);
}

void anyadirTextil() {
	char codigo[10];
	printf("Introduce el codigo:\n");

	scanf("%s", codigo);
	fflush(stdin);

	char *descripcion;
	descripcion = (char*) malloc(sizeof(char));
	printf("Introduce la descripcion:\n");

	scanf("%s", descripcion);
	fflush(stdin);

	float precio;
	printf("Introduce el precio:\n");
	scanf("%f", &precio);

	fflush(stdin);

	Articulo a;
	a.codigo = codigo;
	a.descripcion = descripcion;
	a.precio = precio;

	escrituraAFic(a);

	Textil t;
	t.articulo = a;

	int stockXS;
	printf("Introduce stock de talla XS\n");
	scanf("%i", &stockXS);

	t.stockXS = stockXS;

	int stockS;
	printf("Introduce stock de talla S\n");
	scanf("%i", &stockS);

	t.stockS = stockS;

	int stockM;
	printf("Introduce stock de talla M\n");
	scanf("%i", &stockM);

	t.stockM = stockM;

	int stockL;
	printf("Introduce stock de talla L\n");
	scanf("%i", &stockL);

	t.stockL = stockL;

	char *color;
	color = (char*) malloc(TAMANYO * sizeof(char));
	printf("Introduce color del articulo\n");
	scanf("%s", color);

	t.color = color;

	escrituraTextil(t);

}
void escrituraAFic(Articulo a) {

	FILE *fp;
	fp = fopen("Articulos.txt", "a");

	fprintf(fp, "%s ", a.codigo);
	fprintf(fp, "%s ", a.descripcion);
	fprintf(fp, "%.2f\n", a.precio);

	fprintf(fp, "------------------------\n");

	fclose(fp);

}

void escrituraTextil(Textil t) {

	FILE *fp;
	fp = fopen("Textil.txt", "a");

	fprintf(fp, "%s ", t.articulo.codigo);
	fprintf(fp, "%s ", t.articulo.descripcion);
	fprintf(fp, "%.2f ", t.articulo.precio);
	fprintf(fp, "%s ", t.color);
	fprintf(fp, "%i unidades L ", t.stockL);
	fprintf(fp, "%i unidades M ", t.stockM);
	fprintf(fp, "%i unidades S ", t.stockS);
	fprintf(fp, "%i unidades XS \n", t.stockXS);

	fprintf(fp, "------------------------\n");

	fclose(fp);

}

void escrituraComplemento(Complemento c) {

	FILE *fp;
	fp = fopen("Complementos.txt", "a");

	fprintf(fp, "%s ", c.articulo.codigo);
	fprintf(fp, "%s ", c.articulo.descripcion);
	fprintf(fp, "%.2f ", c.articulo.precio);
	fprintf(fp, "%i unidades\n", c.stock);

	fprintf(fp, "------------------------\n");

	fclose(fp);

}
