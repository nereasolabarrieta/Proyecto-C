/*
 * clsProveedor.h
 *
 *  Created on: 9 abr. 2019
 *      Author: nereasolabarrieta
 */

#ifndef CLSPROVEEDOR_H_
#define CLSPROVEEDOR_H_

typedef struct
{
	char dni[10];
	char *nombre;
}Proveedor;

void introducirProveedor();
void escribirProveedorEnFic(Proveedor);
#endif /* CLSPROVEEDOR_H_ */
