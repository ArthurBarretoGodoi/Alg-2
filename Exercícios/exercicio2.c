#include <stdio.h>
#include <stdlib.h>

int main()
{
    int anterior , proximo, soma , n;

    soma = 0;
    anterior = 0;
    proximo = 1;

    printf("Digite um número para usar no fibonacci\n");

    scanf("%d", &n);

    for (int i = 0 ; i < n ; i++ ) {
        soma = anterior + proximo;
        anterior = proximo; 
        proximo = soma;      
        printf("%d\n",soma);
    }
    
    return 0;
}