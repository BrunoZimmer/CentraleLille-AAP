#include <string.h>
#include <stdio.h>

#include "test_utils.h"
#include "list.h"
#include "../include/traces.h"

void fusionner(T_elt t [], int d, int m, int f); 
void tri_fusion(T_elt t [], int debut, int fin);
T_data fusionSort(T_data d, int n);

void fusionnerListe(T_list l, int d, int m, int f);
T_list scrollVector(T_list l, int i);
void tri_fusionListe(T_list l, int debut, int fin);