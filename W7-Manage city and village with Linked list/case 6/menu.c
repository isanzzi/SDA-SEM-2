#include <stdio.h>
#include "menu.h"

void MainMenu (){
        printf ("\n1. add city\n");
        printf ("2. add people\n");
        printf ("3. delete city\n");
        printf ("4. delete people\n");
        printf ("5. print city and name\n");
        printf ("6. exit\n");
        printf ("input the number you choose : ");
}

void SearchOptions(){
    printf("\n1. by number input\n");
    printf("2. by search kota name\n");
    printf("input your choice : ");
}

void PrintOptions(){
    printf ("\n1. print only in input city\n");
    printf ("2. print entire city\n");
    printf ("3. exit\n");
    printf ("input your choice : ");
}

void PrintFirstLast(){
    printf ("1. first\n");
    printf ("2. last\n");
    printf ("input your choice: ");
}

void PrintForDelete(){
    printf ("1. delete first\n");
    printf ("2. delete last\n");
    printf ("3. delete by name\n");
    printf ("input your choice: ");
}
