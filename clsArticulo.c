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
#include "clsBalance.h"
#define TAMANYO 20

void anyadirComplemento(Complemento * complementos, int tamanyo,
		Balance * balance) {

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
				Contabilizar_complemento(*(complementos + i), stock, balance);
				break;
			}
		}

	} else {
		for (int i = 0; i < tamanyo; i++) {
			if (strcmp((complementos + i)->articulo.codigo, codigo) == 0) {
				printf("El articulo que ha comprado es el siguiente: \n");
				Imprimir_complemento(*(complementos + i));

				printf("�Cuantos articulos ha comprado?\n");
				fflush(stdin);
				int compra;
				scanf("%i", &compra);
				(complementos + i)->stock = ((complementos + i)->stock)
						+ compra;
				Contabilizar_complemento(*(complementos + i), compra, balance);

			}

		}
	}
}
void anyadirTextil(Textil * textiles, int tamanyo, Balance * balance) {
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
				int compra = stockXS + stockS + stockM + stockL;
				Contabilizar_textil(*(textiles + i), compra, balance);

				break;
			}
		}

	} else {
		for (int i = 0; i < tamanyo; i++) {
			if (strcmp((textiles + i)->articulo.codigo, codigo) == 0) {
				printf("El articulo que ha comprado es el siguiente: \n");
				Imprimir_textil(*(textiles + i));
				int compraXS;
				int compraS;
				int compraM;
				int compraL;

				printf("�Cuantos articulos ha comprado de la talla XS?\n");
				fflush(stdin);
				scanf("%i", &compraXS);

				printf("�Y de la talla S?\n");
				fflush(stdin);
				scanf("%i", &compraS);

				printf("�Y de la talla M?\n");
				fflush(stdin);
				scanf("%i", &compraM);

				printf("�Y de la talla L?\n");
				fflush(stdin);
				scanf("%i", &compraL);

				(textiles + i)->stockXS = ((textiles + i)->stockXS) + compraXS;
				(textiles + i)->stockS = ((textiles + i)->stockS) + compraS;
				(textiles + i)->stockM = ((textiles + i)->stockM) + compraM;
				(textiles + i)->stockL = ((textiles + i)->stockL) + compraL;

				int compra = compraXS + compraS + compraM + compraL;
				Contabilizar_textil(*(textiles + i), compra, balance);

			}

		}
	}
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

bool comprobar_complemento(Complemento * complementos, int tamanyo,
		char * codigo) {
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

void Contabilizar_complemento(Complemento complemento, int cantidad,
		Balance * balance) {

	float precio = complemento.articulo.precio;
	float cuantia = cantidad * precio;
	(balance->importePC) = (balance->importePC) + cuantia;
	(balance->importeStock) = (balance->importeStock) + cuantia;

}

void Contabilizar_textil(Textil textil, int cantidad, Balance * balance) {
	float precio = textil.articulo.precio;
	float cuantia = cantidad * precio;
	balance->importePC = balance->importePC + cuantia;
	balance->importeStock = balance->importeStock + cuantia;

}

void Contabilizar_Ventacomplemento(Complemento complemento, int cantidad,
		Balance * balance) {

	float precio = complemento.articulo.precio;
	float cuantia = cantidad * precio;
	(balance->importeRealizable) = (balance->importePC) + cuantia;
	(balance->importeStock) = (balance->importeStock) - cuantia;

}

void Contabilizar_Ventatextil(Textil textil, int cantidad, Balance * balance) {
	float precio = textil.articulo.precio;
	float cuantia = cantidad * precio;
	(balance->importeRealizable) = (balance->importePC) + cuantia;
	(balance->importeStock) = (balance->importeStock) - cuantia;

}

void Imprimir_complemento(Complemento complemento) {
	printf("Nombre: %s, Codigo: %s, Precio: %f, Stock: %i \n",
			complemento.articulo.nombre, complemento.articulo.codigo,
			complemento.articulo.precio, complemento.stock);
}

void Imprimir_textil(Textil textil) {
	printf(
			"Nombre: %s, Codigo: %s, Precio: %f, Color: %s, StockXS: %i, StockS: %i, StockM: %i, StockL: %i \n",
			textil.articulo.nombre, textil.articulo.codigo,
			textil.articulo.precio, textil.color, textil.stockXS, textil.stockS,
			textil.stockM, textil.stockL);
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

void escrituraComplemento(Complemento c) {

	FILE *fp;
	fp = fopen("Complementos.txt", "a");

	fprintf(fp, "%s ", c.articulo.codigo);
	fprintf(fp, "%s ", c.articulo.nombre);
	fprintf(fp, "%.2f ", c.articulo.precio);
	fprintf(fp, "%i unidades\n", c.stock);

	fprintf(fp, "------------------------\n");

	fclose(fp);

}

void VentaComplemento(Complemento *complementos, int tamanyo, Balance *balance) {

	char *codigo = malloc(10 * sizeof(char));
	int cantidad;
	do {
		printf("Introduce el codigo del complemento:\n");

		fflush(stdin);
		scanf("%s", codigo);

		char dni_vacio[] = "0000000000";
		for (int i = 0; i < tamanyo; i++) {
			if (strcmp((complementos + i)->articulo.codigo, dni_vacio) != 0) {
				Imprimir_complemento(*(complementos + i));
			}
		}
		if (comprobar_complemento(complementos, tamanyo, codigo)) {

			printf("No existe ningun complemento con ese codigo.\n");

		} else {

			for (int i = 0; i < tamanyo; i++) {
				printf("%s", (complementos + i)->articulo.codigo);
				printf("%s", codigo);
				if (strcmp((complementos + i)->articulo.codigo, codigo) == 0) {
					printf("El articulo que ha vendido es el siguiente: \n");
					Imprimir_complemento(*(complementos + i));

					printf("Cuantos articulos ha vendido?\n");
					fflush(stdin);

					scanf("%i", &cantidad);
					(complementos + i)->stock = ((complementos + i)->stock)
							- cantidad;
					Contabilizar_Ventacomplemento(*(complementos + i), cantidad,
							balance);

				}

			}
			printf("La venta se ha guardado correctamente:");
		}

	} while (comprobar_complemento(complementos, tamanyo, codigo));

}
void VentaTextil(Textil *textiles, int NUM_ARTIC, Balance *balance) {
	char *codigo = malloc(10 * sizeof(char));
		int cantidadXS;
		int cantidadS;
		int cantidadM;
		int cantidadL;
		do {
			printf("Introduce el codigo del complemento:\n");

			fflush(stdin);
			scanf("%s", codigo);

			char dni_vacio[] = "0000000000";
			for (int i = 0; i < NUM_ARTIC; i++) {
				if (strcmp((textiles + i)->articulo.codigo, dni_vacio) != 0) {
					Imprimir_textil(*(textiles + i));
				}
			}
			if (comprobar_textil(textiles, NUM_ARTIC, codigo)) {

				printf("No existe ningun textil con ese codigo.\n");

			} else {

				for (int i = 0; i < NUM_ARTIC; i++) {
					printf("%s", (textiles + i)->articulo.codigo);
				printf("%s", codigo);
				if (strcmp((textiles + i)->articulo.codigo, codigo) == 0) {
					printf("El articulo que ha vendido es el siguiente: \n");
					Imprimir_textil(*(textiles + i));

					printf("Cuantos articulos ha vendido de la talla XS?\n");
					fflush(stdin);

					scanf("%i", &cantidadXS);
					(textiles + i)->stockXS = ((textiles + i)->stockXS)
							- cantidadXS;

					printf("Cuantos articulos ha vendido de la talla S?\n");
					fflush(stdin);

					scanf("%i", &cantidadS);
					(textiles + i)->stockS = ((textiles + i)->stockS)
							- cantidadS;
					printf("Cuantos articulos ha vendido de la talla M?\n");
					fflush(stdin);

					scanf("%i", &cantidadM);
					(textiles + i)->stockM = ((textiles + i)->stockM)
							- cantidadM;
					printf("Cuantos articulos ha vendido de la talla L?\n");
					fflush(stdin);

					scanf("%i", &cantidadL);
					(textiles + i)->stockL = ((textiles + i)->stockL)
							- cantidadL;
					int total = cantidadXS + cantidadS + cantidadM + cantidadL;
					Contabilizar_Ventatextil(*(textiles + i), total,
							balance);

				}

			}
			printf("La venta se ha guardado correctamente:");
		}

	} while (comprobar_textil(textiles, NUM_ARTIC, codigo));
}

