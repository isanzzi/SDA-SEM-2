#include <stdio.h>
#include "tree.h"

int main() {
    address root;
    Create_tree (&root);
    initialize_tree (&root);
    int menu_choice;
    while (menu_choice != 5) {
        printf("\nPILIH MENU:\n");
        printf("1. Traversal InOrder\n");
        printf("2. Konversi string 'JTK Politeknik Negeri Bandung' menjadi morse\n");
        printf("3. Konversi morse di input cmd menjadi ssebuah kalimat\n");
        printf("4. Mengubah file text menjadi bentuk morse dan menyimpan ke output.txt\n");
        printf("5. EXIT\n");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                InOrder (root);
                printf("\n");
                break;
            case 2:{
                char *str = "JTK Politeknik Negeri Bandung";
                char *hasil=NULL;
                printf("Converting '%s' to Morse code:\n", str);
                toupperstring (str);
                stringtomorse (root, root, str, hasil);
                printf ("%s\n", hasil);
                break;
            }
            case 3:{
                char input[100];
                printf("Enter text to convert to Morse code: ");
                scanf(" %[^\n]", input);
            }
                break;
            case 4:
                txtstringtomorse (root);
                break;
            case 5:
                printf("Terimakasih telah menggunakan kode morse kami\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    ClearTree (&root);
    return 0;
}
