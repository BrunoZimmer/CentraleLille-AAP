#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char mot[25];
	struct node *next;
}T_node;

T_node * newNode(char *str){
	T_node *p = malloc(sizeof(T_node));
	strcpy(p->mot, str);
	p->next = NULL;

	return p;
}

T_node * genListFromTab(char **tab, int taille){
	T_node * p = NULL;
	T_node * aux;
	int i = 0;
	for(i=taille-1; i>=0; i--){
		aux = p;
		p = newNode(tab[i]);
		p->next = aux;
	}

	return p;
}





//T_node * creeList(char* chaine){}