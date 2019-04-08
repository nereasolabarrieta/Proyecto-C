/*
 * clsMenu.c
 *
 *  Created on: 8 abr. 2019
 *      Author: nereasolabarrieta
 */

#include <stdio.h>
int main(void) {
	int opcion;

	do {
		printf("1. Introducir balance");
		printf("\n 2. Gestionar compras");
		printf("\n 3. Salir");
		printf(" \n\n Introduzca una opción del 1-3:");

		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			break;
		case 2:
			break;
		}
	} while (opcion != 3);
	return 0;
}

int existsFile(char* filename) {
	FILE* f = NULL;
	f = fopen(filename, "r");
	if (f == NULL)
		return 0;
	else {
		fclose(f);
		return 1;
	}
}
