#include <stdio.h>
#include <stdlib.h>
#include "../include/traces.h"

#include "../Headers/elt.h"
#include "../Headers/list.h"
#include "../Headers/fusionSort.h"
#include "../Headers/quickSort.h"
#include "../Headers/test_utils.h"

// quel mode pour rech. dicho ?
// mode, label, x, checkOrder 
T_mode m[] = {
	{MODE_TAB_ORDONNE, "ordonne", 0, 1}, 
	{MODE_TAB_ALEATOIRE, "aleatoire", 0, 1}, 
	{MODE_TAB_INVERSE, "inverse", 0, 1}, 
	{MODE_EVAL_X, "x=2.0", 2.0, 0}, 
	{MODE_TAB_ORDONNE, "ordonne (x=59)", 59, 0}, 
	{MODE_TAB_ORDONNE, "hanoi", 1, 0}
};

int main(int argc, char *argv[])
{
  T_elt tab [MAX_ELT];

	outputPath = "exo2/output"; // indiquer le chemin du répertoire où créer les fichiers
	// NB: s'il est relatif, il sera relatif au répertoire depuis lequel l'exercice est exécuté
	
    // Initialisation du générateur de nombres pseudo-aléatoires 
    srand((unsigned int)time(NULL));

	Test_Fn("QUICK SORT", quickSort, tab, MAX_ELT, m[MODE_TAB_ORDONNE] );
	Test_Fn("QUICK SORT", quickSort, tab, MAX_ELT, m[MODE_TAB_ALEATOIRE] );
	Test_Fn("QUICK SORT", quickSort, tab, MAX_ELT, m[MODE_TAB_INVERSE] );

	Test_FnV2("QUICK SORT", quickSort, tab, 512, m[MODE_TAB_ORDONNE] );
	Test_FnV2("QUICK SORT", quickSort, tab, 512, m[MODE_TAB_ALEATOIRE] );
	Test_FnV2("QUICK SORT", quickSort, tab, 512, m[MODE_TAB_INVERSE] );

	
}



