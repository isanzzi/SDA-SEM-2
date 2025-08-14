#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"
#include "menu.h"

int main(){
    boolean lanjut=true;
    int i=0, maxkota = 0;
    char tambah;
    addrkt kota=nil;

    while (lanjut==true){
        MainMenu();
        char menu;
        scanf(" %c", &menu);
        getchar();

        switch (menu){
            case '1': //init city
            {
                addrkt new;
                Createkt(&new);
                Initkt (new);
                infotype title=InsertTitle();
                Isikt (&new, title);
                if (!isCityInitialized(*new)){
                    printf("Input nama berhasil\n");
                }
                Addkt (&kota, new);
                maxkota+=1;
                break;
            }

            case '2': //add name
            { 
                while (1) {
                    printf("Add people? (y/n): ");
                    scanf(" %c", &tambah);
                    getchar();

                    if (tambah=='y') {
                        addrkt temp = kota; 
                        Tampil_ListKota(temp);
                        SearchOptions();
                        char tambah2;
                        scanf(" %c", &tambah2);
                        
                        switch (tambah2) {
                            case '1': 
                                temp = ByNumberInput(kota, maxkota);
                                break;
                            case '2': 
                                temp = BySearchKota(kota);
                                break;
                            default:
                                printf("Invalid option\n");
                                continue;
                        }
                        
                        if (temp != nil && !isEmptykt(temp)){
                            address new;
                            PrintFirstLast();
                            char tambah3;
                            scanf(" %c", &tambah3);
                            
                            switch (tambah3) {
                                case '1':
                                    Create_Node(&new);
                                    Isi_Node(&new, InsertTitle());
                                    Ins_Awal(&(temp->elekt), new);
                                    Tampil_List(temp->elekt);
                                    break;
                                case '2':
                                    Create_Node(&new);
                                    Isi_Node(&new, InsertTitle());
                                    Ins_Akhir(&(temp->elekt), new);
                                    Tampil_List(temp->elekt);
                                    break;
                                default:
                                    printf("Invalid option\n");
                                    break;
                            }
                        } else {
                            printf("City not found or not initialized\n");
                        }
                    } else if (tambah == 'n') {
                        break;
                    } else {
                        printf("Invalid option\n");
                    }
                }
                break;
            }

            case '3': //delete city
            {
                while (1) {
                    printf("Do you want to delete a city? (y/n): ");
                    scanf(" %c", &tambah);
                    getchar();

                    if (tambah=='y') {
                        addrkt temp = kota; 
                        Tampil_ListKota(temp);
                        SearchOptions();
                        char tambah2;
                        scanf(" %c", &tambah2);
                        
                        switch (tambah2) {
                            case '1':
                                {
                                    int kotake;
                                    printf("Masukkan nomor kota: ");
                                    scanf("%d", &kotake);
                                    
                                    DeleteKotaByNumber(&kota, &maxkota, &kotake);
                                }
                                break;
                            case '2': 
                                {
                                    char *cari = InsertTitle();
                                    
                                    DeleteKotaByName(&kota, &maxkota, cari);
                                    
                                    free(cari);
                                }
                                break;
                            default:
                                printf("Invalid option\n");
                                continue;
                        }
                    } else if (tambah == 'n') {
                        break;
                    } else {
                        printf("Invalid option\n");
                    }
                }
                break;
            }

            case '4': //delete name in city
            { 
                while (1) {
                    printf("Do you want to delete people from city? (y/n): ");
                    scanf(" %c", &tambah);
                    getchar();

                    if (tambah=='y') {
                        addrkt temp = kota; 
                        Tampil_ListKota(temp);
                        SearchOptions();
                        char tambah2;
                        scanf(" %c", &tambah2);
                        
                        switch (tambah2) {
                            case '1':
                                temp = ByNumberInput(temp, maxkota);
                                break;
                            case '2': 
                                temp = BySearchKota(temp);
                                break;
                            default:
                                printf("Invalid option\n");
                                continue;
                        }
                        
                        if (temp != nil && !isEmptykt(temp)){
                            if (temp->elekt == nil || isEmpty(temp->elekt)) {
                                printf("No people in this city\n");
                                continue;
                            }
                            
                            PrintForDelete();
                            infotype deleted = NULL;
                            char tambah3;
                            scanf(" %c", &tambah3);
                            
                            switch (tambah3) {
                                case '1':
                                    Del_Awal(&(temp->elekt), &deleted);
                                    if (deleted != NULL) {
                                        printf("Name deleted is %s\n", deleted);
                                        free(deleted);
                                    } else {
                                        printf("No people to delete\n");
                                    }
                                    break;
                                case '2':
                                    Del_Akhir(&(temp->elekt), &deleted);
                                    if (deleted != NULL) {
                                        printf("Name deleted is %s\n", deleted);
                                        free(deleted);
                                    } else {
                                        printf("No people to delete\n");
                                    }
                                    break;
                                case '3':
                                    {
                                        char *searching = InsertTitle();
                                        // Periksa terlebih dahulu apakah nama ada dalam list
                                        address find = temp->elekt;
                                        boolean nameFound = false;
                                        
                                        while (find != nil && !nameFound) {
                                            if (strcmp(info(find), searching) == 0) {
                                                nameFound = true;
                                            }
                                            find = next(find);
                                        }
                                        
                                        if (nameFound) {
                                            DeleteValue(&temp->elekt, searching, &deleted);
                                            if (deleted != NULL) {
                                                printf("Name deleted is %s\n", deleted);
                                                free(deleted);
                                            } else {
                                                printf("Error deleting name\n");
                                            }
                                        } else {
                                            printf("Name not found in this city\n");
                                        }
                                        
                                        free(searching);
                                    }
                                    break;
                                default:
                                    printf("Invalid option\n");
                                    break;
                            }
                        } else {
                            printf("City not found or not initialized\n");
                        }
                    } else if (tambah == 'n') {
                        break;
                    } else {
                        printf("Invalid option\n");
                    }
                }
                break;
            }

            case '5': //print name
            {
                while (1){
                    PrintOptions();
                    char menu2;
                    scanf(" %c", &menu2);
                    getchar();
                    
                    switch (menu2){
                        case '1':
                        {
                            addrkt temp = kota;
                            Tampil_ListKota(temp);
                            SearchOptions();
                            char menu3;
                            scanf(" %c", &menu3);
                            getchar();
                            
                            switch (menu3){
                                case '1': 
                                    temp = ByNumberInput(kota, maxkota);
                                    break;
                                case '2':
                                    temp = BySearchKota(kota);
                                    break;
                                default:
                                    printf("Invalid option\n");
                                    continue;
                            }
                            
                            if (temp != nil) {
                                if (temp->elekt != nil) {
                                    Tampil_List(temp->elekt);
                                } else {
                                    printf("No names in this city\n");
                                }
                            } else {
                                printf("City not found\n");
                            }
                            break;
                        }
                        
                        case '2':
                        {
                            i = 1;
                            addrkt temp = kota;
                            
                            if (temp == nil) {
                                printf("No cities available\n");
                            } else {
                                while (temp != nil && i <= maxkota){
                                    if (isCityInitialized(*temp)){
                                        printf("\nCity-%d (%s):", i, temp->info);
                                        if (temp->elekt != NULL) {
                                            Tampil_List(temp->elekt);
                                        } else {
                                            printf(" No names registered\n");
                                        }
                                    }
                                    temp = nextkt(temp);
                                    i++;
                                }
                            }
                            break;
                        }
                        
                        case '3': 
                            break;
                            
                        default: 
                            printf("Invalid option\n");
                            break;
                    }
                    
                    if (menu2 == '3'){
                        break;
                    }
                }
                break;
            }

            case '6': //exit
            {
                DeAlokasiKota(&kota);
                printf("Dealokasi success\n");
                lanjut = false;
                break;
            }

            default:
                printf("Invalid option\n");
                break;
        }
    }
    
    return 0;
}