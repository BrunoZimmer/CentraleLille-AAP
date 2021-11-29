
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "test_utils.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

void echanger(T_elt t[], int i1, int i2);
int Partitionner (T_elt t [], int g, int d); 
void Tri_rapide( T_elt t[], int debut, int fin);
T_data quickSort(T_data d, int n);