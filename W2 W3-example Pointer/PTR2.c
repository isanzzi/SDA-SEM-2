#include <stdio.h>
int main()
{
    float *pu; //deklarasi pointer pu bertipe float
    float nu; //deklarasi nu bertipe float
    float u = 1234; //u diisi integer 1234
    pu = &u; //pu diisi alamat u
    nu = *pu; //nu diisi nilai dari alamat pu 
    printf("u = %f\n", u); //print nilai u
    printf("nu = %f\n", nu); //print nilai nu
    return 0;

    //error karena pu bertipe pointer float tetapi u integer
    //oleh karena itu tidak bisa build
}