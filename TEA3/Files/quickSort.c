
#include "../Headers/quickSort.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

void echanger(T_elt t[], int i1, int i2) {
  T_elt aux = t[i1];
  t[i1] = t[i2];
  t[i2] = aux;
}

T_data quickSort(T_data d, int n) {
	T_elt * A = d.pElt;

  Tri_rapide(A, 0, n - 1);

  return d;
}


void Tri_rapide( T_elt t[], int debut, int fin) {
  int iPivot;

  stats.nbComparisons++;
  if (fin > debut) {
    //partie pour ameliorer
    int random = debut + rand() % (fin - debut);
    echanger(t, random, fin);

    //division au millieu pour rechercher
    iPivot = Partitionner(t, debut, fin);
    Tri_rapide(t, debut, iPivot - 1);
    Tri_rapide(t, iPivot + 1, fin);
  }
}

int Partitionner (T_elt t [], int d, int f){ 
	int i=d , j=f-1; // On utilise i et j comme « pointeurs » qui se déplacent

	while (i<j) {
    stats.nbComparisons++;
		// On déplace i et j jusqu’à trouver des valeurs incohérentes % pivot
		while ((i<j) && (t[i]<=t[f])) {
      stats.nbComparisons++;
      i++ ;	
    }
		while ((i<j) && (t[j]>t[f])) {
      stats.nbComparisons++;
      j-- ;	
    }

		if (i < j) {
      stats.nbOperations++;
			echanger(t,i,j);
			i++ ; j-- ; 
		}
	}
  stats.nbComparisons++;
	if (t[i]<=t[f]) i++ ; // Cf. ci-contre 

  stats.nbOperations+=3;
	echanger(t, i, f) ;

	return  i; 

}