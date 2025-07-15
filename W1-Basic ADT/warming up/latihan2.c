#include <stdio.h>

int main(){
    int i=0,j;
    while(i<=4
    ){
        j=1;
        while(j<=5){
            if (j<=(4-i)){
                printf(" ");
            }else{
                printf("*");
            }
        j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}