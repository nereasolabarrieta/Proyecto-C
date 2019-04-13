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
	char dni_vacio []="0000000000";

		clientes= (Cliente *)malloc(NUM_CLIENTES*sizeof(Cliente));
		for (int i=0; i<NUM_CLIENTES;i++)
			{
				(clientes+i)->dni=dni_vacio;
			}

		proveedores = (Proveedor *)malloc(NUM_PROV*sizeof(Proveedor));
		for (int i=0; i<NUM_PROV;i++)
			{
				(proveedores+i)->NIF=dni_vacio;
			}
		free(dni_vacio);

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
				printf("\n 7. Visualizar todos los clientes");
				printf("\n 8. Visualizar todos los proveedores");
				printf("\n 9. Editar balance");
				printf("\n 0. Salir");

				printf(" \n\n Introduzca una opcion del 1-7:");

				fflush(stdin);
				scanf("%d", &opcion);
				switch (opcion)
				{
				case 1: Introducir_C();
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
				case 7: Imprimir_Clientes ();
					break;
				case 8: Imprimir_Prov();
					break;
				case 9:
					break;
				case 0: printf("Agur");
					break;
				default : printf("Esa opcion no esta disponible\n");
								}
				}while(opcion != 0);
}
void introducir()
{
	printf("A continuacion introduzca su balance en masas patrimoniales:\n");
	nuestro_balance = (Balance *)malloc(sizeof(Balance));
	introducirBalance(nuestro_balance);
}



void Introducir_C()
{
	char dni_vacio []="0000000000";
	for( int i =0; i<NUM_CLIENTES;i++)
	{
		if (strcmp((clientes+i)->dni,dni_vacio)==0)
		{
			printf("entra %i \n",i+1);
			introducirCliente(clientes+i);

			break;
		}
	}
}


void Introducir_P()
{
	char dni_vacio []="0000000000";
		for( int i =0; i<NUM_PROV;i++)
		{
			if (strcmp((proveedores+i)->NIF,dni_vacio)==0)
			{
				introducirProveedor(proveedores+i);
				break;
			}
		}

}

void Imprimir_Clientes ()
{
	char dni_vacio []="0000000000";
	for( int i =0; i<NUM_CLIENTES;i++)
		{
			if (strcmp((clientes+i)->dni,dni_vacio)!=0)
			{
				ImprimirCliente(*(clientes+i));
			}
		}
}

void Imprimir_Prov ()
{
	char dni_vacio []="0000000000";
	for( int i =0; i<NUM_PROV;i++)
		{
			if (strcmp((proveedores+i)->NIF,dni_vacio)!=0)
			{

				ImprimirProv(*(proveedores+i));
			}
		}
}
