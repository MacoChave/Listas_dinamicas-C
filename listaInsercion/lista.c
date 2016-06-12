/*
 * lista.c
 *
 *  Created on: 12/06/2016
 *      Author: marco
 */
#include <stdlib.h>
#include <stdio.h>

struct Nodo {
	int id;
	char nombre;
	struct Nodo *sig;
};

void insercionInicio(struct Nodo *lista, struct Nodo *temp) {
	if (lista == NULL) {
		lista = malloc(sizeof(struct Nodo));
		lista -> id = 5;
		lista -> nombre = 'a';
		lista -> sig = NULL;
	} else if (lista -> sig == NULL || lista -> sig != NULL) {
		temp = lista;
		lista -> id = 6;
		lista -> nombre = 'b';
		lista -> sig = temp;
		temp = NULL;
	}
}

int main(void) {
	//INICIAR LA LISTA A NULL
	struct Nodo *lista = NULL, *actual, *temp;
	int id;
	char nombre;
	/*
	 * INSERCION AL INICIO
	 */
		if (lista == NULL) {
			lista = malloc(sizeof(struct Nodo));
			lista -> id = 5;
			lista -> nombre = "alberto";
			lista -> sig = NULL;
		} else if (lista -> sig == NULL || lista -> sig != NULL) {
			temp = lista;
			lista -> id = 7;
			lista -> nombre = "juan";
			lista -> sig = temp;
			temp = NULL;
		}
		while (lista -> sig != NULL) {
			temp = lista;
			printf("id: %d, nombre: %hhd", temp -> id, temp -> nombre);
			lista = lista -> sig;
		}
		printf("id: %d, nombre: %hhd", temp -> id, temp -> nombre);

	return 0;
}
