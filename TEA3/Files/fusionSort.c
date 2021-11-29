#include "../Headers/fusionSort.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data fusionSort(T_data d, int n) {
  
  T_elt * A = d.pElt;
  tri_fusion(A, 0, n - 1);

  return d;
}

void tri_fusion(T_elt t [], int debut, int fin) {
  int milieu;

  stats.nbComparisons++;
  if (debut < fin)
  {
    milieu = (debut + fin)/2;
    tri_fusion(t, debut, milieu);
    tri_fusion(t, milieu + 1, fin);
    fusionner(t, debut, milieu, fin);
  }
}


void fusionner(T_elt t [], int d, int m, int f) {
	T_elt aux[f - d + 1]; // !! Allocation dynamique sur la pile (standard C99) 
	int i, j, k;

	memcpy(aux, &t[d], (f - d + 1) * sizeof(T_elt));	// Copie des données à fusionner
	stats.nbOperations += (f - d + 1);

	i = 0; j = m - d + 1; k = 0;
	while (i <= m - d && j <= f - d) {
    stats.nbComparisons+=2;
	  stats.nbOperations++;
		if (aux[i] <= aux[j]) 	{
			t[d + k++] = aux[i++];	// aux[i] est plus petit : on le place dans t 
		}
		else {
	 		t[d + k++] = aux[j++];	// aux[j] est plus petit : on le place dans t 
		}
	}
  stats.nbOperations += (m - d - i > 0) ? m - d - i : 0;
	for (; i <= m - d; t[d + k++] = aux[i++]); // le reste du tableau gauche
  stats.nbOperations += (f - d - j > 0) ? f - d - j : 0;
	for (; j <= f - d; t[d + k++] = aux[j++]); // le reste du tableau droit
}

T_list scrollVector(T_list l, int i) {
  int j;
  T_list aux = l;

  for (j = 0; j < i; j++) {
    aux = aux->pNext;
  }

  return aux;
}

void fusionnerListe(T_list l, int d, int m, int f) {
	T_elt aux[f - d + 1]; // !! Allocation dynamique sur la pile (standard C99) 
	int i, j, k;

	T_list listDebut = scrollVector(l, d);

	k = 0;
	T_list aux2 = listDebut;

  	stats.nbOperations += (j <= f) ? f-d : 0;
	for(j=d; j<=f; j++){
		aux[k++] = aux2->data;
		aux2 = aux2->pNext;
	}

	i = 0; j = m - d + 1; k = 0;
	while (i <= m - d && j <= f - d) {
    	stats.nbComparisons+=2;
		stats.nbOperations++;
		if (aux[i] <= aux[j]){
			scrollVector(listDebut, k++)->data = aux[i++];	// aux[i] est plus petit : on le place dans t 
		}
		else {
	 		scrollVector(listDebut, k++)->data = aux[j++];	// aux[j] est plus petit : on le place dans t 
		}
	}
  stats.nbOperations += (m - d - i > 0) ? m - d - i : 0;
	for (; i <= m - d; scrollVector(listDebut, k++)->data = aux[i++]); // le reste du tableau gauche
  stats.nbOperations += (f - d - j > 0) ? f - d - j : 0;
	for (; j <= f - d; scrollVector(listDebut, k++)->data = aux[j++]); // le reste du tableau droit
}

void tri_fusionListe(T_list l, int debut, int fin) {
  int milieu;

  stats.nbComparisons++;
  if (debut < fin)
  {
    milieu = (debut + fin)/2;
    tri_fusionListe(l, debut, milieu);
    tri_fusionListe(l, milieu + 1, fin);
    fusionnerListe(l, debut, milieu, fin);
  }
}