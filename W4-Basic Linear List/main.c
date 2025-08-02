#include <stdio.h>
#include "linked.h"

int main() {
    address list = nil;
    address node;
    infotype val;

    Create_Node(&node);
    Isi_Node(&node, 7);
    Ins_Awal(&list, node);
    printf("Elemen List = ");
    Tampil_List(list);

    Create_Node(&node);
    Isi_Node(&node, 11);
    Ins_Akhir(&list, node);
    printf("Elemen List = ");
    Tampil_List(list);

    Create_Node(&node);
    Isi_Node(&node, 9);
    address temp = Search(list, 7);
    InsertAfter(&temp, node);
    printf("Elemen List = ");
    Tampil_List(list);

    Create_Node(&node);
    Isi_Node(&node, 5);
    Ins_Awal(&list, node);
    printf("Elemen List = ");
    Tampil_List(list);

    Create_Node(&node);
    Isi_Node(&node, 13);
    Ins_Akhir(&list, node);
    printf("Elemen List = ");
    Tampil_List(list);

    Del_Akhir(&list, &val);
    printf("Elemen List = ");
    Tampil_List(list);

    DeleteValue(&list, 7, &val);
    printf("Elemen List = ");
    Tampil_List(list);

    Del_Awal(&list, &val);
    printf("Elemen List = ");
    Tampil_List(list);

    DeAlokasi(&list);
    printf("Elemen List = ");
    Tampil_List(list);

    return 0;
}
