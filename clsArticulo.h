/*
 * clsArticulo.h
 *
 *  Created on: 9 abr. 2019
 *      Author: nereasolabarrieta
 */

#ifndef CLSARTICULO_H_
#define CLSARTICULO_H_

typedef struct
{
	char *codigo;
	char *descripcion;
	float precio;
}Articulo;

typedef struct
{
	Articulo articulo;
	int stockXS;
	int stockS;
	int stockM;
	int stockL;
	char *color;

}Textil;

typedef struct
{
	Articulo articulo;
	int stock;

}Complemento;

#endif /* CLSARTICULO_H_ */
