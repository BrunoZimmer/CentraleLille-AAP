#include <stdio.h>
#include <string.h>

#include "../include/traces.h" 

#include "../Headers/elt.h"
#include "../Headers/list.h"
#include "../Headers/fusionSort.h"
#include "../Headers/quickSort.h"
#include "../Headers/test_utils.h"

int main() {
  T_list test = NULL;
//créer la liste
  test = addNode(10, test);
  test = addNode(20, test);
  test = addNode(15, test);
  test = addNode(10, test);
  test = addNode(2, test);
  test = addNode(3, test);
  test = addNode(5, test);
  test = addNode(30, test);
  test = addNode(20, test);
  test = addNode(100, test);
  test = addNode(35, test);
  test = addNode(5, test);
  test = addNode(0, test);
  test = addNode(100000, test);
  NL();
//verifier si c'est correct par le print
  showList(test);
  NL(); NL();
//faire la organisation
  tri_fusionListe(test, 0, getSize(test) - 1);
  showList(test);
  NL(); NL();

  return 0;
}


