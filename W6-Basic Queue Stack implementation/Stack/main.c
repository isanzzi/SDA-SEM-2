#include <stdio.h>
#include "stack.h"

void convertbiner(address *q, infotype desimal);

int main(){
    int desimal;
    printf("Masukkan angka desimal: ");
    scanf("%d", &desimal);
    Stack q;
    CreateEmpty (&q);
    convertbiner(&q, desimal);
    if (desimal == 0){
        printf ("0");
    }
    popallandprint(&q);
    return 0;
}

void convertbiner(address *q, infotype desimal){
    if (desimal > 0){
        Push(q, desimal % 2);
        convertbiner(q, desimal/2);
    }
}