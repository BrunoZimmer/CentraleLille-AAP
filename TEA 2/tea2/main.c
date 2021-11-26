#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "./Headers/elt.h"
#include "./Headers/list.h"
#include "./Headers/stack_cld.h"
#include "./Headers/test.h"

int main(int argc, char ** argv) {
	
	// T_stack s = NULL;

	CLRSCR();
	WHOAMI(); 

	// if(argv[1] && argv[2])
	// 	testChangementBase(atoi(argv[1]), atoi(argv[2]), s);
	// else if(argv[1] && !argv[2])
	// 	testChangementBase(atoi(argv[1]), 2, s);

	testPNG();

	// testGetSize();

	// testTaillAdd();

	// testSortAdd();

	// testInList();
	
	//testRemDup();
 	
	return 0;
}







