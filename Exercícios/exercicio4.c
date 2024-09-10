#include <stdio.h>


int main()
{
    int n , quadrado , original , aux , digito ,inverso;

    digito = 0;
    inverso = 0;

    printf("Digite um número:\n");

    scanf("%d", &n);

    original = n;

    quadrado = n*n;

    while (n != 0 ) {
        aux = quadrado%10;
        digito = digito * 10 + aux;
        n = n/10;
        quadrado = quadrado/10;
    }

    while (digito != 0) {
        aux = digito%10;
        inverso = inverso *10 + aux;
        digito = digito/10;
    }

    if (inverso == original)
        printf("Satisfaz\n");
    else
        printf("Não satisfaz\n");
    
    return 0;
}