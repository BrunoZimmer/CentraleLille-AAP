#include <assert.h>
#include <string.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h"

//#define DEBUG
#include "../include/check.h"

#include "../Headers/elt.h"  // T_elt
#include "../Headers/list.h" // prototypes

/*
typedef struct node {
	T_elt data;
	struct node *pNext;
} T_node, * T_list;
*/

static T_node *newNode(T_elt e)
{
	// Créer une nouvelle cellule contenant l'élément e

	T_node *pNode;
	CHECK_IF(pNode = malloc(sizeof(T_node)), NULL, "malloc allocateNode");
	pNode->data = e;
	pNode->pNext = NULL;

	return pNode;
}



T_node *addNode(T_elt e, T_node *n)
{
	// Créer une maille (node), la remplir
	// et l'accrocher en tête d'une liste existante (ou vide)
	// Renvoyer la nouvelle tête

	T_node *pNode;
	pNode = newNode(e);
	pNode->pNext = n;
	return pNode;
}

void showList(T_list l)
{
	// Afficher la liste en commençant par sa tête
	// A faire en itératif

	if (l == NULL)
	{
		printf("Liste Vide !\n");
		return;
	}

	while (l != NULL)
	{
		printf("%s ", toString(l->data));
		l = l->pNext;
	}
}

void freeList(T_list l)
{
	// Libérer la mémoire de toutes les cellules de la liste l
	// A faire en itératif

	T_node *pAux;
	// Il faut un pointeur auxiliaire :
	// on ne doit libérer qu'après avoir enregistré quelque part
	// l'adresse de la maille suivante

	assert(l != NULL);

	while (l != NULL)
	{
		//printf("Libération de %s\n", toString(l->data));
		pAux = l->pNext;
		free(l);
		l = pAux;
	}
}

T_elt getFirstElt(T_list l)
{
	// Renvoyer l'élément contenu dans la cellule de tête de la liste

	assert(l != NULL);

	return l->data;
}

T_list removeFirstNode(T_list l)
{
	// Supprimer la tête de la liste
	// Renvoyer la nouvelle liste privée de sa première cellule

	assert(l != NULL);
	T_node *p = l->pNext;
	free(l);
	return p;
}

// A produire en version récursive (+ tard dans le sujet)

void showList_rec(T_list l)
{
	// Afficher la liste en commençant par sa tête
	// A faire en récursif

	if (l == NULL)
	{
		// case de base
		return;
	}
	else
	{
		// cas général
		printf("%s ", toString(l->data));
		showList_rec(l->pNext);
	}
}

void showList_inv_rec(T_list l)
{
	// Afficher la liste en commençant par sa queue
	// A faire en récursif

	if (l == NULL)
	{
		// case de base
		return;
	}
	else
	{
		// cas général
		showList_inv_rec(l->pNext);
		printf("%s ", toString(l->data));
	}
}

void freeList_rec(T_list l)
{
	// Libérer la mémoire de toutes les cellules de la liste l
	// A faire en récursif

	if (l == NULL)
	{
		return;
	}
	else
	{
		freeList_rec(l->pNext);
		printf("Libération de %s\n", toString(l->data));
		free(l);
	}
}

//             WHAT I DID

unsigned int getSize(const T_list l)
{ // Chercher dans la pile jusq'au fin et après par rec. compter
//Renvoyer la taille d’une liste
	/*
	if(l != NULL){
		return getSize(l->pNext) +1
	}
	if l == NULL{
		return 0
	}
	*/
	return l ? getSize(l->pNext) + 1 : 0;
}

T_list tailAddNode(T_elt e, T_list l){//insérer un élément en queue d'une liste chaînée
/*  if(l != NULL )
		if(l->pNext != NULL)
		 return  tailAddNode(e, l->pNext);
		else 
		return l->pNext = newNode(e)	
	else
		return newNode(e);*/
	if(l)
		return l->pNext ? tailAddNode(e, l->pNext) : (l->pNext = newNode(e));
	else
		return newNode(e);
}

T_list sortAddNode(T_elt e, T_list l){
	//Insérer un élément dans une liste chaînée triée par ordre croissant à la bonne place
	//Que faut-il ajouter à notre module de gestion de T_elt pour permettre de comparer deux
	//T_elt ?  Réaliser les modifications nécessaires
	T_node *newN;
	if (compElt(e, l->data)>=0 && l->pNext)
	{
		return sortAddNode(e, l->pNext);
	}else if(compElt(e, l->data)>=0 && !l->pNext){
		newN = newNode(e);
		newN->pNext = l->pNext;
		l->pNext = newN;
		return l;
	}
	else
	{
		newN = newNode(l->data);
		newN->pNext = l->pNext;
		l->pNext = newN;
		l->data = e;
		return l;
	}
}

int inList(T_elt e, const T_list l)
{
	//Vérifier si un élément appartient à une liste chaînée
	return (l && (e == l->data)) ? 1 : (l->pNext &&(e != l->data)) ? inList(e, l->pNext) : 0;
	// if (l && (e == l->data)){
	// 	return 1;
	// }else if (l->pNext && (e != l->data)){
	// 	return inList(e, l->pNext);
	// }else{
	// 	return 0;
	// }
}

T_list removeDuplicates(T_list l){
	//Éliminer les doublons d'une liste chaînée tout en libérant la mémoire devenue inutile.
	//Cette fonction doit afficher quels éléments sont supprimés si la constante symbolique
	//DEBUG est déclarée dans le fichier list.h.
	T_list lAux = NULL, lAuxToDel = NULL;
	if (l){
		lAux = l;
		while (lAux->pNext){//while pour rechercher le comparison
			if (compElt(l->data, (lAux->pNext)->data) == 0){
				showDuplicates((lAux->pNext)->data);
				if ((lAux->pNext)->pNext){//moyen de la liste avec duplicate
					lAuxToDel = lAux->pNext;
					lAux->pNext = lAuxToDel->pNext;

					free(lAuxToDel);
				}
				else{
					free(lAux->pNext);//fin de la liste
					lAux->pNext = NULL;
					break;
				}
			}else{
				lAux = lAux->pNext;
			}
		}
		removeDuplicates(l->pNext); //le deuxième boucle pour rechercher nombre
	}
	return l;
}
#ifdef DEBUG
	void showDuplicates(T_elt e){
		printf("Duplicate: %s\n", toString(e));
	}
#else
	void showDuplicates(T_elt e){
		
	}
#endif

