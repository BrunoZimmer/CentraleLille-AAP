typedef struct node{
	char mot[25];
	struct node *next;
}T_node;
T_node * newNode(char *mot);
T_node * genListFromTab(char **tab, int taille);