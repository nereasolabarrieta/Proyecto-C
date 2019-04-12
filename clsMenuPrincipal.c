#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "clsBalance.h"
#include "clsProveedor.h"
#include "clsCliente.h"

#define NUM_PROV 20
#define NUM_CLIENTES 100


Balance * nuestro_balance;
Cliente * clientes;
Proveedor * proveedores;

int main(void) {

	clientes= (Cliente *)malloc(NUM_CLIENTES*sizeof(Cliente));
	proveedores = (Proveedor *)malloc(NUM_CLIENTES*sizeof(Proveedor));

// si existe clientes.txt meterlos en el array
// si existe provedorees.txt meterlos en el array

	if (!existsFile("Balance.txt"))
	{
		introducir();
		Menu();
	} else
	{
		Menu();
	}
	return 0;
}



void Menu()
{
	int opcion;

	do {

		printf("\n 1. Introducir cliente");
		printf("\n 2. Introducir proveedor");
		printf("\n 3. Contabilizar venta");
		printf("\n 4. Contabilizar compra");
		printf("\n 5. Otros gastos");
		printf("\n 6. Visualizar estado contable");
		printf("\n 7. Editar balance");
		printf("\n 8. Salir");

		printf(" \n\n Introduzca una opcion del 1-7:");

		fflush(stdin);
		scanf("%d", &opcion);
		switch (opcion)
		{
		case 1: introducirCliente();
			break;
		case 2: Introducir_P();
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
		}while(opcion != 3);

}
void introducir()
{
	printf("A continuacion introduzca su balance en masas patrimoniales:\n");
	nuestro_balance = (Balance *)malloc(sizeof(Balance));
	introducirBalance(nuestro_balance);
}

void Introducir_P()
{
	Proveedor *nuevo_proveedor;
	nuevo_proveedor=(Proveedor *)malloc(sizeof(Proveedor));
	introducirProveedor(nuevo_proveedor);
}
