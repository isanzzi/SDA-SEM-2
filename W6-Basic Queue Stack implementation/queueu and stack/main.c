#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"
#include "print.h"

void PushStacktoQueue (Queue *Q, Stack *S);

int main(){
    boolean lanjut=true;
    char pilih;
    Queue Q;
    Stack S;
    Stack History;
    createinitQueue(&Q);
    createinitStack(&S, &History);
    while (lanjut==true){
        printf("\n");
        printf("now playing : ");
        SongNow(&Q);
        PrintNextSong(&Q);
        MainMenu();
        char menu;
        scanf(" %c", &menu);
        getchar();

        switch (menu) {
            case '1':
                Tampil_List(Q.head);
                printf("tekan enter untuk kembali ");
                getchar();
                break;

            case '2':
                Tampil_List(S.top);
                printf("tekan enter untuk kembali ");
                getchar();
                break;

            case '3': {
                printf("Queue sebelum: ");
                Tampil_List(Q.head);
                PushStacktoQueue(&Q, &S);
                printf("Queue sesudah: ");
                Tampil_List(Q.head);
                printf("Playlist sesudah: ");
                Tampil_List(S.top);
                printf("tekan enter untuk kembali ");
                getchar();
                break;
            }

            case '4':
                printf ("apakah anda yakin ingin menghapus : y/n \nMasukkan jawaban anda : ");
                scanf (" %c", &pilih);
                switch (pilih){
                    case 'y':
                    if (!isEmpty(Q.head)){
                        Push(&History, (Q).head->info);
                        dequeueandprint(&Q);
                    } else{
                        printf("tidak ada yang bisa dihapus\n");
                    }
                    break;
                    case 'n':
                    break;
                    default :
                    break;
                }
                printf("tekan enter untuk kembali ");
                getchar();
                break;

            case '5':
                printf ("isi queue : ");
                Tampil_List (Q.head);
                enqueue (&Q, InsertTitle());
                printf("isi list sekarang : ");
                Tampil_List (Q.head);
                printf ("tekan enter untuk kembali ke menu");
                getchar();
                break;

            case '6':
                printf ("isi Playlist : ");
                Tampil_List (S.top);
                Push (&S, InsertTitle());
                printf ("isi list sekarang : ");
                Tampil_List (S.top);
                printf ("tekan enter untuk kembali ke menu");
                getchar();
                break;
            
            case '7': {
                printf ("isi Playlist sekarang : ");
                Tampil_List (S.top);
                printf ("apakah anda yakin ingin menghapus : y/n \nMasukkan jawaban anda : ");
                scanf (" %c", &pilih);
                infotype nilai;
                switch (pilih){
                    case 'y':
                        if (!isEmpty(S.top)) {
                            Pop(&S, &nilai);
                            printf("Lagu yang di-undo: %s\n", nilai);
                        } else {
                            printf("Playlist kosong\n");
                        }
                        break;
                    case 'n':
                        break;
                    default:
                        break;
                }
                printf("tekan enter untuk kembali ");
                getchar();
                break;
            }
            
            case '8':
                printf ("History Song\n");
                Tampil_List (History.top);
                printf("tekan enter untuk kembali ");
                getchar();
                break;

            case '9':
                ExitStack (&S, &History);
                ExitQueue (&Q);
                printf ("cek apakah dealokasi sudah nil\n");
                Tampil_List (Q.head);
                Tampil_List (S.top);
                Tampil_List (History.top);
                lanjut = false;
                break;
            default :
            break;
        }
    }
    return 0;
}

void PushStacktoQueue(Queue *Q, Stack *S) {
    if (!isEmpty(S->top)) {
        address current = S->top;
        // simpan tail awal jika queue tidak kosong
        address lastTail = Q->tail;
        
        // Transfer each node from stack to queue
        while (current != nil) {
            char* temp = current->info;  // Store original string pointer
            enqueue(Q, temp);  // tail sudah diupdate di dalam enqueue
            current = current->next;
        }
        
        // Now properly deallocate the stack
        address temp;
        while (S->top != nil) {
            temp = S->top;
            S->top = next(S->top);
            free(info(temp));  // Free the string
            free(temp);        // Free the node
        }
    } else {
        printf("Playlist kosong, tidak ada yang bisa dipindahkan\n");
    }
}