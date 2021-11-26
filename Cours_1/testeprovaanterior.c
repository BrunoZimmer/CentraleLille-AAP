#include <stdio.h>
#include <math.h>

int persistence(int num);

int main(void) {
	int teste = 2688, i=0, p=0, n=0, num=0;
    
    printf("\n\n");
    //numero
    //p = persistence(teste);

//menor n
    for(n=1; n<10;n++){}
    num=9;
    n=2;
    i = persistence(num);
    printf("\nnum = %d && i =%d\n", num,i);
    
    while (persistence(num) != n){
        printf("\nnum = %d\n", num);
        num= num+1;
        
    }
	
    printf("\nnum = %d\n", num);

    return 0;
}

int persistence(int num){
	int i=0, prod=1;
    if(num<10)
        return 0;

    for( i=0; num > 9; i++){
        prod=1;
        //printf("\n%d \n",num);
		while(num > 0){
            prod= prod*(num%10);
			num = num/10;
            //printf("\n%d & %d\n", prod, num);
		}
        num  = prod;
	}
    return i;
}
/*
int persistenceN(int num){
	int i=0, j=0, prod=1;
    for( i=1; prod != 0; i++){
        prod=1;
        printf("\n%d \n",num);
        for( j=1; prod != 0; i++){

            prod= prod*(num%10);
			num = num/10;
            //printf("\n%d & %d\n", prod, num);
		}
        num  = prod;
	}
    return i;
}*/