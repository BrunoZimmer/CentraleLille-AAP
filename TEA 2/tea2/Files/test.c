#include <stdio.h>
#include <assert.h>
#include "../../include/traces.h" 

#include "../Headers/stack_cld.h"
#include "../Headers/list.h"
#include "../Headers/test.h"

void testPNG(void){
    printf("########    TEST PNG      ##############");NL();NL();
	T_stack s = NULL;
    int i;
    
    for(i=5; i>0;i--){// Crée  une liste ordinaire
        push(i*10,&s);
    }
	showStack(&s);NL();
	generatePNG(s, "./Output/listPNG.dot");// utiliser la fonction 

    printf("######################################################");NL();NL();
    
}

void testChangementBase(int value, int base, T_list s){
    printf("########    TEST Changement Base      ##############");NL();NL();
    printf("Base dec : %d\n", value );
    s = changeBase(value, base, s);NL();// utiliser la fonction 
    printf("Base %d \n\n", base );// afficher le resultat
    printf("              ");
	showStack(&s);NL();
    printf("######################################################");NL();NL();
}

void testGetSize(void){
    T_stack s = NULL;
    int i;
    printf("########    TEST Get Size      ##############");NL();NL();
    for(i=10; i>0;i--){ // Crée  une liste ordinaire
        push(i,&s);
    }
	showStack(&s);NL();
    printf("%u \n", getSize(s)); // utiliser la fonction et afficher le resultat
    
    printf("######################################################");NL();NL();
}

void testTaillAdd(void){
    T_stack s = NULL;
    int i;
    printf("########    TEST Add Tail      ##############");NL();NL();
    
    for(i=10; i>0;i--){ // Crée  une liste ordinaire
        push(i,&s);
    }
	showStack(&s);NL();NL();
    printf("Maintenant ajouter '5'");NL();NL();
    tailAddNode(5, s); // utiliser la fonction
	showStack(&s);NL();NL(); // afficher le resultat

    
    printf("######################################################");NL();NL();
}

void testSortAdd(void){
    T_stack s = NULL;
    int i;
    printf("########    TEST Sort Add      ##############");NL();NL();
      
    for(i=10; i>0;i--){ // Crée  une liste ordinaire
        push(i,&s);
    }
	showStack(&s);NL();NL();
    printf("Maintenant ajouter '5'");NL();NL();
    sortAddNode(5, s);// utiliser la fonction avec differents values
	showStack(&s);NL();NL(); // afficher le resultat
    printf("Maintenant ajouter '13'");NL();NL();
    sortAddNode(13, s);
	showStack(&s);NL();NL();
    printf("Maintenant ajouter '0'");NL();NL();
    sortAddNode(0, s);
	showStack(&s);NL();NL();

    
    printf("######################################################");NL();NL();
}
void testInList(void){
    T_stack s = NULL;
    int i;
    printf("########    TEST In List      ##############");NL();NL();
    for(i=10; i>0;i--){ // Crée  une liste ordinaire
        push(i,&s);
    }
	showStack(&s);NL();NL();
    printf("Maintenant ajouter '5'");NL();
    if(inList(5, s))// utiliser la fonction avec differents values
	    printf("5 esta na lista \n\n\n"); // afficher le resultat
    else
	    printf("5 não esta na lista \n\n\n");
    printf("Maintenant ajouter '13'");NL();

    if(inList(13, s))
	    printf("13 esta na lista \n\n\n");
    else
	    printf("13 não esta na lista \n\n\n");
    
    printf("######################################################");NL();NL();
}
void testRemDup(void){
    T_stack s = NULL;
    int i;
    printf("########    TEST Remove Duplicate      ##############");NL();NL();
    for(i=5; i>0;i--){ // Crée  une liste ordinaire
        push(i,&s);
        push(5,&s);
    }
    printf("Liste");
	showStack(&s);NL();NL();
    printf("Maintenant retirer '5'");NL();NL();
	s = removeDuplicates (s);// utiliser la fonction 
	showStack(&s);NL();NL(); // afficher le resultat
    printf("######################################################");NL();NL();
}