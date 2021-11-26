#include <stdio.h>
#include <math.h>

#define MAX 1000
int amies(int num);

int main() {
    //int save[2][MAX];

    int n=1000;
    int i=0,j=0;
    int num2=0;

    for(i=0; i<=n;i++){                         // percorrer todos os numeros ate o n
        num2 = amies(i);                        //funcao que verifica se sao amigos e se for devolve o valor

        if(num2 > 0 && num2 <= n){              //condição para ver se os  numeros eram amigos ou não
            //save[0][j] = i;
            //save[1][j] = num2;
            printf("\n%d && %d\n", i, num2);
        }
    }
    
    return 0;
}

int amies(int num){
    int som1 = 0;
    int som2 = 0;
    int div;

    for(div=1;div<=sqrt(num);div++){                  //percorre todaspossibilidades de divisores e os soma
        if(num%div == 0){
            if(num/div == div){
                som1+= div;
            }else{
                som1+= div;
                som1+= num/div;
            }
        }
    }
    //printf("\n%d && %d\n", som1, num);
    for(div=1;div<=sqrt(num);div++){  
        if(som1%div == 0){
            if(som1/div == div)
                som2+= div;
            else{
                som2+= div;
                som2+= som1/div;
            }
        }
    }

    if(num == som2){
        return som1;
    }else{
        return -1;
    }
}