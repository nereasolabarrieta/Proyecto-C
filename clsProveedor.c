
#include "clsProveedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANYO 20

void introducirProveedor(Proveedor *nuevoProveedor) {
	nuevoProveedor->NIF = malloc(10 * sizeof(char));
	printf("Introduce NIF:\n");
	fflush(stdin);
	scanf("%s", nuevoProveedor->NIF);

	char *nom;
	nom = (char*) malloc(TAMANYO * sizeof(char));
	printf("Introduce NOMBRE\n");
	fflush(stdin);
	scanf("%s", nom);


	int len = strlen(nom);
	nuevoProveedor->nom = (char*) malloc(len * sizeof(char));
	strcpy(nuevoProveedor->nom, nom);



	fflush(stdin);

	escribirProveedorEnFic(*nuevoProveedor);
}

void escribirProveedorEnFic(Proveedor p) {

	FILE *fp;
	fp = fopen("Proveedores.txt", "a");

	fprintf(fp, "%s ", p.nom);
	fprintf(fp, "%s\n", p.NIF);

	fprintf(fp, "------------------------\n");
	fclose(fp);

}
void lecturaFicheroProv() {
	FILE *f;
	f = fopen("Proveedores.txt", "r");
	char *c;
	char caracter;
	c = (char*) malloc(sizeof(char));
	while ((caracter = fgetc(f)) != EOF) {
		fgets(c, sizeof(Proveedor), f);
		printf("%s\n", c);
	}
	fclose(f);
}
void ImprimirProv(Proveedor prov) {
	printf("[Nombre: %s, NIF: %s ]\n", prov.nom, prov.NIF);
}

