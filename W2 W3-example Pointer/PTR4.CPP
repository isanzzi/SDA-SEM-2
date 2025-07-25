#include <stdio.h>

int main()
{
int z, s, *pz, *ps; //deklarasi integer z, s, lalu pointer integer pz dan ps
z = 20;//z diisi 20
s = 30;//s diisi 30
pz = &z; // alamat pz menunjuk ke z
ps = &s;//alamat ps menunjuk ke s
*pz = *pz + *ps; //mengambil nilai pz dan ps
printf("z = %d, s = %d\n", z , s);
return 0;
}