#include <stdio.h>
int main()
{
float d, *pd; //deklarasi float d, dan pd bertipe pointer float
d = 54.5; // d diisi 54.5
printf("Isi d semula = %g\n", d); //print d awal
pd = &d; //pd diisi alamat yang sama dengan d
*pd = *pd + 10;//pointer pd mengakses nilai d melalui pointer lalu menambahkan 10.000
printf("Isi d kini = %g\n", d); //print d terbaru
return 0;
}