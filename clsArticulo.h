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
	char *nombre;
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

void anyadirComplemento();
void anyadirTextil();
void escrituraAFic(Articulo);
void escrituraTextil(Textil);
void escrituraComplemento(Complemento);
bool comprobar_textil(Textil * textiles, int tamanyo, char * codigo);
bool comprobar_complemento(Complemento * complementos,int tamanyo, char * codigo);
void Imprimir_complemento(Complemento complemento);
void Imprimir_textil(Textil textil);
#endif /* CLSARTICULO_H_ */
