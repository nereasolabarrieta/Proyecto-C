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
	char dni[10];
	char *nombre;
	char *ape;
}Cliente;

void introducirCliente();
#endif /* CLSCLIENTE_H_ */
