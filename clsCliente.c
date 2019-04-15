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

	fprintf(fp, "%s\n%s\n%s\n%d\n",c.nom,c.ape,c.dni,c.acumulado);

	fclose(fp);

}
void lecturaFicheroCliente(Cliente *c) {
	FILE* file = fopen("Clientes.txt", "r");
	int num;
	char buffer[250];
	int numLineas =0;
	char caracter;
	while((caracter= fgetc(file))!= EOF)
	{
		if(caracter == '\n')
		{
			numLineas++;

		}
	}
	num = numLineas/4;
	rewind(file);
	for (int i=0; i<num; i++)
	{
		c[i].nom = malloc (TAMANYO * sizeof(char));
		fscanf(file, "%s", buffer);
		strcpy(c[i].nom, buffer);

		c[i].ape = malloc (TAMANYO* sizeof(char));
		fscanf(file, "%s", buffer);
		strcpy(c[i].ape, buffer);

		c[i].dni = malloc (10 * sizeof(char));
		fscanf(file, "%s", buffer);
		strcpy(c[i].dni, buffer);


		fscanf(file, "%d", &(c[i].acumulado));
		imprimirCliente(c[i]);
	}


	    fclose(file);
}
//void escribirFic_bin(Cliente c) {
//
//	FILE *f;
//	f = fopen("Clientes.dat", "ab");
//
//	fputc(c.acumulado,f);
//	int len=strlen(c.nom);
//	fputc(len,f);
//	fwrite(c.nom,sizeof(char),len,f);
//	len=strlen(c.ape);
//	fputc(len,f);
//	fwrite(c.ape,sizeof(char),len,f);
//	fputc(10,f);
//	fwrite(c.dni,sizeof(char),10,f);
//
//	fclose(f);
//
//}
//
//void leer_bin(Cliente c,int tamanyo) {
//
//	FILE *f;
//	f = fopen("Clientes.dat", "a");
//
//	fputc(c.acumulado,f);
//	int len=strlen(c.nom);
//	fputc(len,f);
//	fwrite(c.nom,sizeof(char),len,f);
//	len=strlen(c.ape);
//	fputc(len,f);
//	fwrite(c.ape,sizeof(char),len,f);
//	fputc(10,f);
//	fwrite(c.dni,sizeof(char),10,f);
//
//	fclose(f);
//
//}
//
//void LeerFic_bin(Cliente *c, int tamanyo) {
//
//	FILE *f;
//	f = fopen("Clientes.dat", "rb");
//
//	while(!feof(f))
//	{
//		int len;
//		for(int i=0;i<tamanyo;i++)
//			{
//			(c+i)->acumulado=fgetc(f);
//			len=fgetc(f);
//			fread(c->nom,sizeof(char),len,f);
//			len=fgetc(f);
//			fread(c->ape,sizeof(char),len,f);
//			len=fgetc(f);
//			fread(c->dni,sizeof(char),len,f);
//
//	}
//
//
//	}
//
//	fclose(f);
//
//}


void imprimirCliente(Cliente cl) {
	printf("Nombre %s %s, dni: %s, dinero: %i euro\n", cl.nom, cl.ape, cl.dni,
			cl.acumulado);
}

