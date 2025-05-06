#include <stdio.h>

void mainarray();
void maindll();
int mainsll();

int main() {
    int mode;
    printf("Pilih mode:\n1. Array\n2. DLL\n3. SLL\nPilihan: ");
    scanf("%d", &mode);
    getchar();
    if (mode == 1) {
        mainarray();
    } else if (mode == 2) {
        maindll();
    } else if (mode == 3) {
        mainsll();
    } else {
        printf("Pilihan tidak valid.\n");
    }
    return 0;
}