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
        printf ("\nyou can add city from 1 to %d", jmlkota);
        printf ("\n1. add/init city\n");
        printf ("2. add name in city\n");
        printf ("3. print name\n");
        printf ("4. delete first name\n");
        printf ("5. modify city name\n"); // Add new menu option
        printf ("6. exit\n");
        printf ("input the number you choose : ");

        char menu;
        scanf (" %c", &menu);
        getchar();

        switch (menu){
            case '1':
                printf("\nWhich city number do you want to initialize? (1-%d): ", jmlkota);
                scanf("%d", &kotake);
                if (kotake > 0 && kotake <= jmlkota) {
                    kotake--; // Adjust index
                    infotype cityName;  // Use infotype array
                    InsertTitle(cityName);  // Changed to pass array directly
                    strcpy(kota[kotake].info, cityName);
                } else {
                    printf("Invalid city number. Please enter 1-%d\n", jmlkota);
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
                            Tampil_List(kota[kotake].elekt);
                            infotype name;  // Use infotype array
                            InsertTitle(name);  // Changed to pass array directly
                            address newNode = SetNode(&name);
                            Ins_Awal(&(kota[kotake].elekt), newNode);
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
                            } else {
                                printf("\nCity-%d (%s):", kotake+1, kota[kotake].info);
                                if (kota[kotake].elekt == nil) {
                                    printf(" No names registered\n");
                                } else {
                                    Tampil_List(kota[kotake].elekt);
                                }
                            }
                        } else {
                            printf ("Invalid city number\n");
                        }
                        break;
                    case '2' :
                        i=0;
                        while (i<jmlkota){
                            if (isCityInitialized(kota[i])){
                                printf("\nCity-%d (%s):", i+1, kota[i].info);
                                if (kota[i].elekt == nil) {
                                    printf(" No names registered\n");
                                } else {
                                    Tampil_List(kota[i].elekt);
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
                    } else if (kota[kotake].info[0] != '\0'){ // Fixed: check first character instead of pointer
                        printf ("name city - %s", kota[kotake].info);
                    } else if (isEmpty(kota[kotake].elekt)) { // Changed from NULL check
                        printf("No names in this city\n");
                    } else {
                        printf("Current list: ");
                        Tampil_List(kota[kotake].elekt);
                        infotype deleted;
                        Del_Awal(&(kota[kotake].elekt), &deleted);
                        printf("Deleted name: %s\n", deleted);
                        printf("Updated list: ");
                        Tampil_List(kota[kotake].elekt);
                    }
                } else {
                    printf("Invalid city number. Please enter 1-%d\n", jmlkota);
                }
                break;

            case '5':
                printf("\nWhich city to modify? (1-%d): ", jmlkota);
                scanf("%d", &kotake);
                kotake--;
                if (kotake >= 0 && kotake < jmlkota) {
                    if (!isCityInitialized(kota[kotake])) {
                        printf("City not initialized\n");
                    } else {
                        ModifyString(kota[kotake].info);
                    }
                }
                break;

            case '6': // Changed from 5 to 6
                i=0;
                while (i<jmlkota){
                    DeAlokasi(&(kota[i].elekt)); // Only need to free linked list
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