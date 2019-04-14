#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "clsBalance.h"
#include "clsProveedor.h"
#include "clsCliente.h"
#include "clsMenuPrincipal.h"
#include "clsArticulo.h"

#define NUM_PROV 20
#define NUM_CLIENTES 100
#define NUM_ARTIC 30

Balance *nuestro_balance;
Cliente *clientes;
Proveedor *proveedores;
Textil * textiles;
Complemento * complementos;

int main(void) {

	clientes = (Cliente *) malloc(NUM_CLIENTES * sizeof(Cliente));
	proveedores = (Proveedor *) malloc(NUM_PROV * sizeof(Proveedor));
	nuestro_balance = (Balance *) malloc(sizeof(Balance));
	textiles= (Textil*)malloc(NUM_ARTIC*sizeof(Textil));
	complementos= (Complemento*)malloc(NUM_ARTIC*sizeof(Complemento));
	menuPrincipal();
	return 0;

}
void menuPrincipal() {
	char dni_vacio[] = "0000000000";

	for (int i = 0; i < NUM_CLIENTES; i++) {
		(clientes + i)->dni = dni_vacio;
	}

	for (int i = 0; i < NUM_PROV; i++) {
		(proveedores + i)->NIF = dni_vacio;
	}

	for (int i = 0; i < NUM_ARTIC; i++) {
			((textiles + i)->articulo).codigo= dni_vacio;
			((complementos + i)->articulo).codigo= dni_vacio;
		}

	free(dni_vacio);

// si existe clientes.txt meterlos en el array
// si existe provedorees.txt meterlos en el array

	if (!existsFile("Balance.txt")) {
		introducirBalance();

		menu();
	} else {

		menu();
	}

}

void menu() {
	char opcion;

	do {

		printf("\n 1. Introducir cliente");
		printf("\n 2. Introducir proveedor");
		printf("\n 3. Contabilizar venta"); // identificar cliente--> dni (sacarle por pantalla),identificar articulo (textil o complemento) introducir codigo, (talla) stock-1.,
		printf("\n 4. Contabilizar compra");
		printf("\n 5. Otros gastos");
		printf("\n 6. Visualizar estado contable"); //imprimier balance
		printf("\n 7. Visualizar todos los clientes");
		printf("\n 8. Visualizar todos los proveedores");
		printf("\n 9. Editar balance");
		printf("\n 0. Salir");

		printf(" \n\n Introduzca una opcion del 1-7:");

		fflush(stdin);
		scanf("%c", &opcion);
		switch (opcion) {
		case '1':
			introducirC();
			break;
		case '2':
			introducirP();
			break;
		case '3':ContabilizarVenta();
			break;
		case '4': compra();
			break;
		case '5':
			break;
		case '6': imprimirBalance();
			break;
		case '7':
			imprimirClientes();
			break;
		case '8':
			imprimirProv();
			break;
		case '9':
			break;
		case '0':
			printf("Agur");
			break;
		default:
			printf("Esa opcion no esta disponible\n");
		}
	} while (opcion != '0');
}
void introducirBalance() {
	printf("A continuacion introduzca su balance en masas patrimoniales:\n");
	introducir(nuestro_balance);
}

void introducirC() {
	char dni_vacio[] = "0000000000";
	for (int i = 0; i < NUM_CLIENTES; i++) {
		if (strcmp((clientes + i)->dni, dni_vacio) == 0) {
			printf("entra %i \n", i + 1);
			introducirCliente(clientes + i);

			break;
		}
	}
}

void introducirP() {
	char dni_vacio[] = "0000000000";
	for (int i = 0; i < NUM_PROV; i++) {
		if (strcmp((proveedores + i)->NIF, dni_vacio) == 0) {
			introducirProveedor(proveedores + i);
			break;
		}
	}

}



void compra() {
	char opcion;
	do {

		printf("Que tipo de articulo desea introducir?\n");
		printf("1-Complemento\n");
		printf("2-Textil\n");

		fflush(stdin);
		scanf("%c", &opcion);
		switch (opcion) {
		case '1':
			anyadirComplemento(complementos,NUM_ARTIC,nuestro_balance);
			break;
		case '2':
			anyadirTextil(textiles,NUM_ARTIC,nuestro_balance);
			break;

		default:
			printf("Esa opcion no existe.");
		}
	} while (!(opcion == '1' || opcion == '2') );

}

void imprimirClientes() {
	char dni_vacio[] = "0000000000";
	for (int i = 0; i < NUM_CLIENTES; i++) {
		if (strcmp((clientes + i)->dni, dni_vacio) != 0) {
			imprimirCliente(*(clientes + i));
		}
	}
}

void imprimirProv() {
	char dni_vacio[] = "0000000000";
	for (int i = 0; i < NUM_PROV; i++) {
		if (strcmp((proveedores + i)->NIF, dni_vacio) != 0) {

			ImprimirProv(*(proveedores + i));
		}
	}
}

void imprimirBalance ()
{
	float totalA= nuestro_balance->importeANC+nuestro_balance->importeDisponible+nuestro_balance->importeStock+nuestro_balance->importeRealizable;
	float totalP= nuestro_balance->importePC+nuestro_balance->importePN+nuestro_balance->importePNC;
	printf( "TOTAL ACTIVO: %i eu\n",totalA);
		printf( "Activo no corriente: %f\n",nuestro_balance->importeANC);
		printf( "Activo corriente: %f\n",nuestro_balance->importeDisponible+nuestro_balance->importeStock+nuestro_balance->importeRealizable);
		printf( "1. Stock: %f\n",nuestro_balance->importeStock);
		printf( "2. Realizable: %f\n",+nuestro_balance->importeRealizable);
		printf( "3. Disponible: %f\n",nuestro_balance->importeDisponible);

		printf( "--------------------------\n");


		printf( "TOTAL PASIVO Y PATRIMONIO NETO: %f\n",totalP);
		printf( "PAtrimonio neto: %f\n",nuestro_balance->importePN);
		printf("Pasivo no corriente: %f\n",nuestro_balance->importePNC);
		printf( "Pasivo corriente: %f\n",nuestro_balance->importePC);
}

void ContabilizarVenta(){
	bool existe=false;
	char *dni = malloc(10 * sizeof(char));
	do
	{
	printf("Introduce el DNI del cliente que ha realizado la compra:\n");

	fflush(stdin);
	scanf("%s", dni);


	for (int i = 0; i < NUM_CLIENTES; i++) {
		if (strcmp((clientes + i)->dni, dni) == 0) {
			printf("El cliente correspondiente a este DNI es el siguiente: \n");
			imprimirCliente(*(clientes + i));
			existe=true;
		}
	}
	if(existe==false)
	{
		printf("No existe ningun cliente con ese DNI\n");
	}

	}while(existe==false);

	char opcion;
	do {

		printf("Que tipo de venta desea contabilizar?\n");
		printf("1-Complemento\n");
		printf("2-Textil\n");

		fflush(stdin);
		scanf("%c", &opcion);
		switch (opcion) {
		case '1':
			VentaComplemento(complementos,NUM_ARTIC, nuestro_balance);
			break;
		case '2':
			VentaTextil(textiles,NUM_ARTIC, nuestro_balance);
			break;

		default:
			printf("Esa opcion no existe.");
		}
	} while (opcion != 1 && opcion != 2 );
}
