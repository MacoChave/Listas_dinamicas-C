#include <stdlib.h>
#include <stdio.h>

/*
 * TIPO Nodo CON APUNTADOR A OTRO Nodo
 * SE PODRÍA HACER UN TIPO PARA VARIOS VALORES,
 * E INGRESARLO EN Nodo
 */
struct Nodo {
	int info;
	struct Nodo * sig;
};

/*
 * CREAR LISTA DE ENTEROS
 */
int main(void) {
	//INDICAR QUE LA LISTA ESTÁ VACÍA
	struct Nodo *lista = NULL, *aux;

	/*
	 * INSERCION AL INICIO
	 */

	//RESERVAR ESPACIO EN MEMORIA LISTO PARA EL PRIMER VALOR
	lista = malloc(sizeof(struct Nodo));

	//ASIGNAR VALOR AL ESPACIO RESERVADO
	lista -> info = 8;
	//ASIGNAR SIGUIENTE NULL
	lista -> sig = NULL;

	aux = lista;
	lista = malloc(sizeof(struct Nodo));
	lista -> info = 3;
	lista -> sig = aux;
	aux = NULL;

	while (lista -> sig != NULL) {
		aux = lista;
		printf("%d\n", aux -> info);
		lista = lista -> sig;
	}
	printf("%d\n", lista -> info);
	return 0;
}
