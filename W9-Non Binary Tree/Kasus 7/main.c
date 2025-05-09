#include <stdio.h>
#include "tree.h"

int main() {
    Isi_Tree alldata;
    int node_count, choice;

    printf("Pilih opsi:\n");
    printf("1. Gunakan pohon yang sudah ada dari gambar\n");
    printf("2. Buat pohon sendiri\n");
    printf("Pilihan: ");
    scanf("%d", &choice);

    if (choice == 1) {
        Create_tree(alldata, jml_maks);
        initialize_tree(alldata);
        node_count=10;
    } else if (choice == 2) {
        int num_nodes;
        printf("Masukkan jumlah node (maks %d): ", jml_maks);
        scanf("%d", &num_nodes);
        if (num_nodes > 0 && num_nodes <= jml_maks) {
            Create_tree(alldata, num_nodes);
        } else {
            printf("Jumlah node tidak valid.\n");
            return 1;        }
        int i = 1;
        printf ("root adalah nomor atau node 1\n");
        while (i <= num_nodes){
            printf ("\nJika tidak ada maka isi 0\n");
            printf("Masukkan nama untuk node %d: ", i);
            scanf(" %c", &alldata[i].info);
            printf("Masukkan nomor first son untuk node %d: ", i);
            scanf("%d", &alldata[i].ps_fs);
            printf("Masukkan nomor untuk next brother %d: ", i);
            scanf("%d", &alldata[i].ps_nb);
            printf("Masukkan nomor untuk parent di %d: ", i);
            scanf("%d", &alldata[i].ps_pr);
            i++;
        }
        node_count = num_nodes;
    } else {
        printf("Pilihan tidak valid.\n");
        return 1;
    }

    int menu_choice;
    while (menu_choice != 11) {
        printf("\nPILIH MENU:\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                printf("PreOrder: ");
                PreOrder(alldata, 1);
                printf("\n");
                break;
            case 2:
                printf("InOrder: ");
                InOrder(alldata, 1);
                printf("\n");
                break;
            case 3:
                printf("PostOrder: ");
                PostOrder(alldata, 1);
                printf("\n");
                break;
            case 4:
                printf("Level Order: ");
                Level_order(alldata, node_count);
                printf("\n");
                break;
            case 5:
                PrintTree(alldata, "tree.dot");
                break;
            case 6: {
                char X;
                printf("Masukkan node yang dicari: ");
                scanf(" %c", &X);
                if (Search(alldata, X)) {
                    printf("Node %c ditemukan.\n", X);
                } else {
                    printf("Node %c tidak ditemukan.\n", X);
                }
                break;
            }
            case 7:
                printf("Jumlah daun: %d\n", nbDaun(alldata));
                break;
            case 8: {
                char X;
                printf("Masukkan node untuk mencari level: ");
                scanf(" %c", &X);
                int level = Level(alldata, X);
                if (level != -1) {
                    printf("Level node %c: %d\n", X, level);
                } else {
                    printf("Node %c tidak ditemukan.\n", X);
                }
                break;
            }
            case 9:
                printf("Kedalaman tree: %d\n", Depth(alldata));
                break;
            case 10: {
                char X, Y;
                printf("Masukkan dua node untuk dibandingkan: ");
                scanf(" %c %c", &X, &Y);
                printf("Nilai terbesar: %c\n", (char)Max(X, Y));
                break;
            }
            case 11:
                printf("Keluar.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}