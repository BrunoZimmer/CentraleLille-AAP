#include <stdio.h>

int main() {
    int b = 1;
    int *p = &b;

    printf("%d, %d\n", b, *p);

    (*p)++;
    printf("%d, %d\n", b, *p);
    
    (p)++;
    printf("%d, %d\n", b, *p);
    
    return 0;
}
