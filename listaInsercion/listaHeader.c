/*
 * listaHeader.c
 *
 *  Created on: 12/06/2016
 *      Author: marco
 */

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

TipoLista lista_vacia(void){
	return NULL;
}

int es_lista_vacia(TipoLista lista) {
	return lista == NULL;
}

TipoLista inserta_por_cabeza(TipoLista lista, int valor) {
	struct Nodo* nuevo = malloc(sizeof(struct Nodo));
	nuevo -> info = valor;
	nuevo -> sig = lista;
	lista = nuevo;

	return lista;
}

TipoLista inserta_por_cola(TipoLista lista, int valor) {
	struct Nodo* aux = lista;
	struct Nodo* nuevo = malloc(sizeof(struct Nodo*));

	nuevo -> info = valor;
	nuevo -> sig = NULL;

	if(aux != NULL) {
		while(aux -> sig != NULL) {
			aux = aux -> sig;
		}
		aux -> sig = nuevo;
	} else {
		lista = nuevo;
	}
	return lista;
}

TipoLista borra_cabeza(TipoLista lista){
	if (lista != NULL) {
		struct Nodo* aux = lista;
		lista = lista -> sig;
		free(aux);
	}
	return lista;
}

TipoLista borra_cola(TipoLista lista) {
	if (lista != NULL) {
		struct Nodo* actual = lista;
		struct Nodo* anterior;
		while (actual -> sig != NULL) {
			anterior = actual;
			actual = actual -> sig;
		}
		if (lista != actual) {
			anterior -> sig = NULL;
			free(actual);
		} else {
			free(lista);
		}
	}

	return lista;
}

TipoLista borra_primer_ocurrencia(TipoLista lista, int valor) {
	struct Nodo* actual = lista;
	struct Nodo* anterior;

	while (actual != NULL) {
		if (actual -> info == valor) {
			if (actual != lista) {
				anterior -> sig = actual -> sig;
				free(actual);
			} else {
				lista = lista -> sig;
				free(actual);
			}
		}
		anterior = actual;
		actual = actual -> sig;
	}
	return lista;
}

int longitud_lista(TipoLista lista) {
	struct Nodo* aux;
	int contador = 0;

	for (aux = lista; aux != NULL; aux = aux -> sig)
		contador++;

	return contador;
}

void muestra_lista(TipoLista lista) {
	struct Nodo* aux;

	for(aux = lista; aux != NULL; aux = aux -> sig)
		printf("%d - > ", aux -> info);
	printf("NULL\n");
}

int pertenece(TipoLista lista, int valor) {
	struct Nodo* aux;

	for (aux = lista; aux != NULL; aux = aux -> sig) {
		if (aux -> info == valor)
			return 1;
	}
	return 0;
}

int main(void) {
	TipoLista lista;
	lista = lista_vacia();

	lista = inserta_por_cabeza(lista, 2);
	lista = inserta_por_cabeza(lista, 8);
	lista = inserta_por_cabeza(lista, 3);
	lista = inserta_por_cabeza(lista, 5);
	lista = inserta_por_cabeza(lista, 7);
	lista = inserta_por_cabeza(lista, 3);
	lista = inserta_por_cabeza(lista, 3);

	lista = inserta_por_cola(lista, 4);
	lista = inserta_por_cola(lista, 10);
	lista = inserta_por_cola(lista, 5);
	lista = inserta_por_cola(lista, 7);
	lista = inserta_por_cola(lista, 15);
	lista = inserta_por_cola(lista, 4);
	lista = inserta_por_cola(lista, 7);

	printf("Longitud: %d\n", longitud_lista(lista));

	muestra_lista(lista);

	printf("----BORRAR CABEZA----\n");

	//lista = borra_cabeza(lista);
	//muestra_lista(lista);

	printf("----BORRAR COLA----\n");

	//lista = borra_cola(lista);
	//muestra_lista(lista);

	printf("----BUSCAR 7----\n");

	printf("%d\n",pertenece(lista, 7));

	printf("----BORRAR 7----\n");

	lista = borra_primer_ocurrencia(lista, 7);
	muestra_lista(lista);

	return 0;
}
