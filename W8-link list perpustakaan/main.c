#include <stdio.h>
#include <stdbool.h>

void mainarray();
void maindll();
int mainsll();

int main() {
    int mode;
    bool lanjut=true;
    while (lanjut==true){
    	printf("Pilih mode:\n1. Array\n2. DLL\n3. SLL\n0. Exit\nPilihan: ");
	    scanf("%d", &mode);
	    getchar();
	    if (mode == 1) {
	        mainarray();
	    } else if (mode == 2) {
	        maindll();
	    } else if (mode == 3) {
	        mainsll();
	    } else if (mode == 0) {
	    	lanjut = false;
	    	printf("Terimakasih telah menggunakan sistem perpustakaan saya");
		} else {
	        printf("Pilihan tidak valid.\n");
	    }
	}
return 0;
}
