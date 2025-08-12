#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

int main(){
    boolean lanjut=true;
    int jmlkota, kotake, i=0;
    char tambah;

    printf ("How many city : ");
    scanf ("%d", &jmlkota);
    getchar();
    kt kota [jmlkota];
    while (i<jmlkota){
        Initkt (&kota [i]);
        i++;
    }

    while (lanjut==true){
        printf ("\n1. add/init city\n");
        printf ("2. add name in city\n");
        printf ("3. print name\n");
        printf ("4. delete first name\n");
        printf ("5. exit\n");
        printf ("input the number you choose : ");

        char menu;
        scanf (" %c", &menu);
        getchar();

        switch (menu){
            case '1':
                printf("\nWhich city number do you want to initialize? (1-%d): ", jmlkota);
                scanf ("%d", &kotake);
                if (kotake > 0 && kotake <= jmlkota) {
                    kotake--; // Adjust index
                    if (kota[kotake].info != NULL) {
                        free(kota[kotake].info);
                    }
                    kota[kotake].info = InsertTitle();
                    if (kota[kotake].info == NULL) {
                        printf("Failed to allocate memory for city name\n");
                    }
                } else {
                    printf ("Invalid city number. Please enter 1-%d\n", jmlkota);
                }
            break;

            case '2':
                while (1) {
                    printf("Add people? (y/n): ");
                    scanf(" %c", &tambah);
                    getchar();

                    if (tambah=='y'){
                        printf("Which city number do you want to add name (1-%d): ", jmlkota);
                        scanf ("%d", &kotake);
                        kotake--; // Adjust index
                        if (kotake >= 0 && kotake < jmlkota) {
                            if (!isCityInitialized(kota[kotake])){
                                printf ("City not initialized. Please initialize city first\n");
                                break;
                            }
                            Tampil_List(kota[kotake].knama);
                            char *nama = InsertTitle();
                            address newNode = SetNode(&nama);
                            Ins_Awal(&(kota[kotake].knama), newNode);
                        } else {
                            printf ("Invalid city number. Please enter 1-%d\n", jmlkota);
                        }
                    }
                    if (tambah=='n'){
                        break;
                    }
                }
            break;

            case '3':
            while (1){
                printf ("\n1. print only in input city");
                printf ("\n2. print entire city");
                printf ("\n3. exit");
                printf ("\ninput your choice : ");
                char menu2;
                scanf (" %c", &menu2);
                getchar();
                switch (menu2){
                    case '1' :
                        printf ("Input which city you want to print (1-%d): ", jmlkota);
                        scanf("%d", &kotake);
                        kotake--; // Adjust index
                        if (kotake >= 0 && kotake < jmlkota){
                            if (!isCityInitialized(kota[kotake])) {
                                printf("City not initialized\n");
                            } else if (kota[kotake].knama == NULL) {
                                printf("No names in this city\n");
                            } else {
                                printf ("\nCity-%d (%s):", kotake+1, kota[kotake].info);
                                Tampil_List(kota[kotake].knama);
                            }
                        } else {
                            printf ("Invalid city number\n");
                        }
                        break;
                    case '2' :
                        i=0;
                        while (i<jmlkota){
                            if (isCityInitialized(kota[i])){
                                printf ("\nCity-%d (%s):", i+1, kota[i].info);
                                if (kota[i].knama != NULL) {
                                    Tampil_List(kota[i].knama);
                                } else {
                                    printf(" No names registered\n");
                                }
                            }
                            i++;
                        }
                        break;
                    case '3' : 
                        break;
                    default:
                        printf ("Invalid option\n");
                        break;
                }
                if (menu2 == '3'){
                    break;
                }
            }
            break;

            case '4':
                printf("\nWhich city number do you want to delete from (1-%d): ", jmlkota);
                scanf("%d", &kotake);
                kotake--; // Adjust index
                if (kotake >= 0 && kotake < jmlkota) {
                    if (!isCityInitialized(kota[kotake])) {
                        printf("City not initialized\n");
                    } else if (kota[kotake].knama == NULL) {
                        printf("No names in this city\n");
                    } else {
                        printf("Current list: ");
                        Tampil_List(kota[kotake].knama);
                        infotype deleted;
                        Del_Awal(&(kota[kotake].knama), &deleted);
                        printf("Deleted name: %s\n", deleted);
                        free(deleted); // Free the deleted name
                        printf("Updated list: ");
                        Tampil_List(kota[kotake].knama);
                    }
                } else {
                    printf("Invalid city number. Please enter 1-%d\n", jmlkota);
                }
                break;

            case '5':
                i=0;
                while (i<jmlkota){
                    if (kota[i].info != NULL) {
                        free(kota[i].info); // Free city name
                    }
                    DeAlokasi(&(kota[i].knama)); // Free linked list
                    i++;
                }
                printf ("dealokasi success\n");
                lanjut = false;
            break;

            default :
            break;
        }
    }
    return 0;
}