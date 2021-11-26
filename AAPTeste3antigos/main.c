#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*#include <assert.h>
#include "stack_cld.h"
#include "elt.h"*/



int main(void) {
  //T_node * l = NULL;
	T_node * p = NULL;
	T_node * head = NULL;
	T_node * tail = NULL;

	char mot[10] = {'r', 'a', 'd', 'a', 'r','\0'};

	char c = mot[0];
	int i = 0;
	T_node *aux;
	while(c != '\0'){
		aux = p;
		p = newNode(c);
		p->next = aux;
		c = mot[i+1];
		if(i>=1){
			p->next->previous = p;
		}
		i++;
	}
	
	head = p;
	head->previous = NULL;
	tail = addresseTail(head);



	T_node *d = head;
	while(d != NULL){
		printf("%c \n", d->lettre);
		d = d->next;
	}
	printf("tail : %c \n", tail->lettre);
	printf("'%s' est palindrome ? %d \n", mot, verifPalindrome(head, tail));


	char mot2[10] = {'g', 'a', 'y', 'a', 'k','\0'};
	head = creeList(mot2);
	tail = addresseTail(head);
	d = head;
	while(d != NULL){
		printf("%c \n", d->lettre);
		d = d->next;
	}
	printf("head : %c \n", head->lettre);
	printf("tail : %c \n", tail->lettre);
	printf("'%s' est palindrome ? %d \n", mot2, verifPalindrome(head, tail));


  return 0;
}