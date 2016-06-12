/*
 * lista.h
 *
 *  Created on: 12/06/2016
 *      Author: marco
 */

#ifndef LISTA_H_
#define LISTA_H_

struct Nodo {
	int info;
	struct Nodo* sig;
};

typedef struct Nodo* TipoLista;

extern TipoLista lista_vacia(void);

extern int es_lista_vacia(TipoLista lista);

extern TipoLista inserta_por_cabeza(TipoLista lista, int valor);

extern int longitud_lista(TipoLista lista);

extern void muestra_lista(TipoLista lista);

extern TipoLista inserta_por_cola(TipoLista lista, int valor);

extern TipoLista borra_cabeza(TipoLista lista);

extern TipoLista borra_cola(TipoLista lista);

extern int pertenece(TipoLista lista, int valor);

extern TipoLista borra_primer_ocurrencia(TipoLista lista, int valor);



#endif /* LISTA_H_ */
