

#include "clsProveedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANYO 20

void introducirProveedor(Proveedor *nuevoProveedor)
{
	char *NIF=malloc(10*sizeof(char));
			printf("Introduce NIF:\n");
			fflush(stdin);
			scanf("%s", NIF);


			char *nom;
			fflush(stdin);
			nom = (char*) malloc (TAMANYO*sizeof(char));
			printf("Introduce NOMBRE\n");
			scanf("%s", nom);

			char *nombre;
			int len = strlen(nom);
			nombre = (char*) malloc (len*sizeof(char));
			strcpy(nombre,nom);
			free(nom);

			nuevoProveedor->NIF=NIF;
			nuevoProveedor->nom=nombre;
			fflush(stdin);

			escribirProveedorEnFic(*nuevoProveedor);
}

void escribirProveedorEnFic(Proveedor p)
{

	FILE *fp;
	fp = fopen ( "Proveedores.txt", "a" );

	fprintf(fp, "Nombre: %s\n",p.nom);
	fprintf(fp, "NIF: %s\n",p.NIF);

	fprintf(fp, "------------------------\n");
	fclose(fp);

}
void ImprimirProv(Proveedor prov)
{
	printf("[Nombre: %s, NIF: %s ]\n",prov.nom,prov.NIF);
}


