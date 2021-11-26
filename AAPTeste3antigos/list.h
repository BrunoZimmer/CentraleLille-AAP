typedef struct node{
	struct node *previous;
	char lettre;
	struct node *next;
}T_node;

T_node * newNode(char c);
T_node * addresseTail(T_node *n);
int verifPalindrome (T_node *head, T_node *tail);
T_node * creeList(char* chaine);