#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 26


typedef struct node {
	char data[MAXLEN];
	struct node *pNext;
	int quantite; // nombre de elements restant sur la liste
} T_node, * T_list;

T_node * newNode(char c[MAXLEN], int q);
void showStuff(T_list l);
void freeList(T_list l);
void updateStuff(T_list l, char newData[MAXLEN], int quant, char oldName[MAXLEN]);


int main() {

	return 0;
}

void showStuff(T_list l){
	T_list aux; //aux commence en next pour être le premiere element
	for(aux = l->pNext; aux != l; aux = aux->pNext){
		//quand il n'y a plus des elements le boucle s'arrêtera
		puts(l->data);
		printf("\n quantite = %d", l->quantite);
	}
}


T_node * newNode(char c[MAXLEN], int q)
{
	T_node * p = malloc(sizeof(T_node));

	strcpy(p->data, c);
	p->pNext = NULL;
	p->quantite = q;

	return p;
}


void updateStuff(T_list l, char newData[MAXLEN], int quant, char oldName[MAXLEN]){
	T_list aux, new;
	new = newNode(newData, quant);
	
	for(aux = l->pNext; !strcmp(aux->pNext->data, oldName); aux = aux->pNext){
		if(strcmp(newData, oldName)){
			new->pNext = aux->pNext->pNext;
			new = aux->pNext;

			free(aux);
		}

		if(aux->pNext == l){
			printf("il n'y a pas d'élement requis");
			break;
		}
	}
}

void freeList(T_list l){
	T_list aux;
	if(l->pNext){
		aux = l;
		l = l->pNext;
		free(aux);
		freeList(l);
	}
}