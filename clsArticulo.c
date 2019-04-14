/*
 * clsArticulo.c
 *
 *  Created on: 13/4/2019
 *      Author: ALUMNO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "clsArticulo.h"
#define TAMANYO 20

void anyadirComplemento(Complemento * complementos, int tamanyo) {

	char codigo[10];
	printf("Introduce el codigo:\n");
	fflush(stdin);
	scanf("%s", codigo);
	if (comprobar_complemento(complementos, tamanyo, codigo)) {
		char cod_vacio[] = "0000000000";
		for (int i = 0; i < tamanyo; i++) {
			if (strcmp((complementos + i)->articulo.codigo, cod_vacio) == 0) {
				char *nom;
				nom = (char*) malloc(TAMANYO * sizeof(char));
				printf("Introduce el nombre:\n");
				fflush(stdin);
				scanf("%s", nom);

				int len = strlen(nom);
				char *nombre = (char*) malloc(len * sizeof(char));
				strcpy(nombre, nom);

				float precio;
				printf("Introduce el precio:\n");
				scanf("%f", &precio);
				fflush(stdin);

				int stock;
				printf("Introduce stock\n");
				scanf("%i", &stock);

				(complementos + i)->articulo.codigo = codigo;
				(complementos + i)->articulo.nombre = nombre;
				(complementos + i)->articulo.precio = precio;
				(complementos + i)->stock = stock;

				escrituraComplemento(*(complementos + i));
				free(nom);
				break;
			}
		}

	} else {
		for (int i = 0; i < tamanyo; i++) {
			if (strcmp((complementos + i)->articulo.codigo, codigo) == 0) {
				printf("El articulo que ha comprado es el siguiente: \n");
				Imprimir_complemento(*(complementos + i));

				printf("¿Cuantos articulos ha comprado?\n");
				fflush(stdin);
				int compra;
				scanf("%i", &compra);
				(complementos + i)->stock = ((complementos + i)->stock)+ compra;

			}

		}
	}
}
	void anyadirTextil(Textil * textiles, int tamanyo) {
		char codigo[10];
		printf("Introduce el codigo:\n");

		scanf("%s", codigo);
		fflush(stdin);
		if (comprobar_textil(textiles, tamanyo, codigo)) {

			char cod_vacio[] = "0000000000";

			for (int i = 0; i < tamanyo; i++) {

				if (strcmp((textiles + i)->articulo.codigo, cod_vacio) == 0) {

					char *nom;
					nom = (char*) malloc(TAMANYO * sizeof(char));
					printf("Introduce el nombre:\n");
					fflush(stdin);
					scanf("%s", nom);

					int len = strlen(nom);
					char *nombre = (char*) malloc(len * sizeof(char));
					strcpy(nombre, nom);

					float precio;
					printf("Introduce el precio:\n");
					scanf("%f", &precio);
					fflush(stdin);

					/*		Articulo a;
					 a.codigo = codigo;
					 a.nombre = nombre;
					 a.precio = precio;

					 escrituraAFic(a);
					 */

					int stockXS;
					printf("Introduce stock de talla XS\n");
					scanf("%i", &stockXS);

					int stockS;
					printf("Introduce stock de talla S\n");
					scanf("%i", &stockS);

					int stockM;
					printf("Introduce stock de talla M\n");
					scanf("%i", &stockM);

					int stockL;
					printf("Introduce stock de talla L\n");
					scanf("%i", &stockL);

					char *col;
					col = (char*) malloc(TAMANYO * sizeof(char));
					printf("Introduce color del articulo\n");
					scanf("%s", col);

					len = strlen(col);
					char *color = (char*) malloc(len * sizeof(char));
					strcpy(color, col);

					(textiles + i)->articulo.codigo = codigo;
					(textiles + i)->articulo.nombre = nombre;
					(textiles + i)->articulo.precio = precio;
					(textiles + i)->stockXS = stockXS;
					(textiles + i)->stockS = stockS;
					(textiles + i)->stockM = stockM;
					(textiles + i)->stockL = stockL;
					(textiles + i)->color = color;

					escrituraTextil(*(textiles + i));
					break;
				}
			}

		}
		else
		{

		}
	}
	void escrituraAFic(Articulo a) {

		FILE *fp;
		fp = fopen("Articulos.txt", "a");

		fprintf(fp, "%s ", a.codigo);
		fprintf(fp, "%s ", a.nombre);
		fprintf(fp, "%.2f\n", a.precio);

		fprintf(fp, "------------------------\n");

		fclose(fp);

	}

	bool comprobar_textil(Textil * textiles, int tamanyo, char * codigo) {
		char cod_vacio[] = "0000000000";
		bool unico = true;
		for (int i = 0; i < tamanyo; i++) {
			if (strcmp((textiles + i)->articulo.codigo, cod_vacio) != 0) {
				if (strcmp((textiles + i)->articulo.codigo, codigo) == 0) {
					unico = false;
				}

			}
		}
		return unico;
	}

	bool comprobar_complemento(Complemento * complementos,int tamanyo, char * codigo) {
		char cod_vacio[] = "0000000000";
		bool unico = true;
		for (int i = 0; i < tamanyo; i++) {
			if (strcmp((complementos + i)->articulo.codigo, cod_vacio) != 0) {
				if (strcmp((complementos + i)->articulo.codigo, codigo) == 0) {
					unico = false;
				}

			}
		}
		return unico;
	}

	void Imprimir_complemento(Complemento complemento) {
		printf("Nombre: %s, Codigo: %s, Precio: %f, Stock: %i \n",
				complemento.articulo.nombre, complemento.articulo.codigo,
				complemento.articulo.precio, complemento.stock);
	}

	void Imprimir_textil(Textil textil) {
			printf("Nombre: %s, Codigo: %s, Precio: %f, Color: %s, StockXS: %i, StockS: %i, StockM: %i, StockL: %i \n",
					textil.articulo.nombre, textil.articulo.codigo,
					textil.articulo.precio, textil.color, textil.stockXS,textil.stockS,textil.stockM,textil.stockL);
		}


	void escrituraTextil(Textil t) {

		FILE *fp;
		fp = fopen("Textil.txt", "a");

		fprintf(fp, "%s ", t.articulo.codigo);
		fprintf(fp, "%s ", t.articulo.nombre);
		fprintf(fp, "%.2f ", t.articulo.precio);
		fprintf(fp, "%s ", t.color);
		fprintf(fp, "%i unidades L ", t.stockL);
		fprintf(fp, "%i unidades M ", t.stockM);
		fprintf(fp, "%i unidades S ", t.stockS);
		fprintf(fp, "%i unidades XS \n", t.stockXS);

		fprintf(fp, "------------------------\n");

		fclose(fp);

	}

	void escrituraComplemento(Complemento c)
	{

		FILE *fp;
		fp = fopen("Complementos.txt", "a");

		fprintf(fp, "%s ", c.articulo.codigo);
		fprintf(fp, "%s ", c.articulo.nombre);
		fprintf(fp, "%.2f ", c.articulo.precio);
		fprintf(fp, "%i unidades\n", c.stock);

		fprintf(fp, "------------------------\n");

		fclose(fp);

	}

