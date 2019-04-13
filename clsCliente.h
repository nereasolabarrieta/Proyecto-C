/*
 * clsCliente.h
 *
 *  Created on: 9 abr. 2019
 *      Author: nereasolabarrieta
 */

#ifndef CLSCLIENTE_H_
#define CLSCLIENTE_H_

typedef struct
{
	char* dni;
	char *nom;
	char *ape;
	int acumulado;
}Cliente;

void introducirCliente(Cliente *);
void escribirClienteEnFic(Cliente);
void imprimirCliente(Cliente *);
void lecturaFicheroCliente();

#endif /* CLSCLIENTE_H_ */
