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

    int x=1,y=0;
    while(x<=4){
        y=0;
        while(y<=4){
            if (y<=x){
                printf(" ");
            }else{
                printf("*");
            }
            if(y>=x){
                printf("*");
            }
        y++;
        }
        printf("\n");
        x++;
    }


    return 0;


}