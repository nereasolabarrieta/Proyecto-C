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
	char *NIF;
	char *nom;
}Proveedor;

void introducirProveedor(Proveedor *nuevoProveedor);
void escribirProveedorEnFic(Proveedor);
void ImprimirProv(Proveedor prov);
#endif /* CLSPROVEEDOR_H_ */
