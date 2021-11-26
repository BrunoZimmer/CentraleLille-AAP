#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *previous;
	char lettre;
	struct node *next;
}T_node;

T_node * newNode(char c){
	T_node * p = malloc(sizeof(T_node));

	p->lettre = c;
	p->next = NULL;
	p->previous = NULL;

	return p;
}

T_node * addresseTail(T_node *n){
	T_node * tail = n;

	if(tail->next != NULL){
		tail = addresseTail(tail->next);
	}

	return tail;
}

int verifPalindrome (T_node *head, T_node *tail){
	while (head != tail){
		if(head->lettre != tail->lettre){
			return 0;
		}

		head = head->next;
		tail = tail->previous;
	}

	return 1;
}

T_node * creeList(char* chaine){
	char c = chaine[0];
	T_node *p;
	T_node *head;
	T_node *tail;

	int i = 0;
	T_node *aux;
	while(c != '\0'){
		aux = p;
		p = newNode(c);
		p->lettre = c;
		p->next = aux;
		c = chaine[i+1];
		if(i>=1){
			p->next->previous = p;
		}
		i++;
	}
	
	head = p;
	head->previous = NULL;
	tail = addresseTail(head);

	return head;
}