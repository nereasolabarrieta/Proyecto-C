/*
 * clsMenu.c
 *
 *  Created on: 8 abr. 2019
 *      Author: nereasolabarrieta
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "clsBalance.h"
#include "clsProveedor.h"
#include "clsCliente.h"

int main(void) {
	int opcion, opcion2;

	do {
		printf(" 1. Introducir balance");
		printf("\n 2. Gestionar compras");
		printf("\n 3. Salir");
		printf(" \n\n Introduzca una opción del 1-3:");

		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			introducirBalance();
			break;
		case 2:

			if (existsFile("Balance.txt") == false) {
				introducirBalance();
			} else {


				do {
					printf(" 1. Introducir cliente");
					printf("\n 2. Introducir proveedor");
					printf("\n 3. Contabilizar venta");
					printf("\n 4. Contabilizar compra");
					printf("\n 5. Otros gastos");
					printf("\n 6. Visualizar estado contable");
					printf("\n 7. Salir");
					printf(" \n\n Introduzca una opción del 1-7:");

				scanf("%d", &opcion2);
				switch (opcion2) {
				case 1: introducirCliente();
					break;
				case 2: introducirProveedor();
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				}
			} while (opcion2 != 7);
			}

			break;
		}
	} while (opcion != 3);
	return 0;
}
