#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
#include <string.h>

/*#include <assert.h>
#include "stack_cld.h"
#include "elt.h"*/

#define MAX 25

int main(int argc, char **argv) {
  T_node *list;
	T_node *p = NULL;
	char mot[4*MAX];
	char mot1 [MAX] = "Vive";
	char mot2 [MAX] = "le";
	char mot3 [MAX] = "langage";
	char mot4 [MAX] = "C";
	
	T_node *aux = p;
	p = newNode(mot4);
	p->next = aux;
	aux = p; /////////////////
	p = newNode(mot3);
	p->next = aux;
	aux = p; ////////////////
	p = newNode(mot2);
	p->next = aux;
	aux = p; ///////////////
	p = newNode(mot1);
	p->next = aux;
	///////////////////////
	list = p;
	

	aux = list;
	while(aux != NULL){
		printf("%s ", aux->mot);
		aux = aux->next;
	}
	printf("\n");

	char *tab[3] = {"Vamos", "comer", "Kebab"};
	list = genListFromTab(tab, 3);
	aux = list;
	while(aux != NULL){
		printf("%s ", aux->mot);
		aux = aux->next;
	}
	printf("\n");


	list = genListFromTab(argv+1, argc-1);
	aux = list;
	while(aux != NULL){
		printf("%s ", aux->mot);
		aux = aux->next;
	}
	printf("\n");

  return 0;
}