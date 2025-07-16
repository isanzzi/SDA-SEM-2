#include <stdio.h>

int main(){
    int i=0,j;
    while(i<=4){
        j=0;
        while(j<=4){
            if (j<=(4-i)){
                printf(" ");
            }else{
                printf("*");
            }
            if(j>=(4-i)){
                printf("*");
            }
        j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}