#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    int n , original, aux , inverso;

    inverso = 0;

    printf("Digite um número para verificar se ele é palíndromo:\n ");

    scanf("%d", &n);

    original = n;

    while (n != 0) {
        aux = n%10;
        inverso = inverso *10 + aux;
        n = n/10;
    } 

    if (original == inverso)
        printf("É um palindromo\n");
    else
        printf("Não é um palindromo\n");

    return 0;
}