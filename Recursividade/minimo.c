#include <stdio.h>


void ler_vetor(int vet[] , int tam)
{
    int i , x;

    for (i = 0 ; i < tam ; i++) {
        scanf("%d", &x);
        vet[i] = x;
    }
}


void imprime_vetor(int vet[], int tam)
{
    int i;

    for (i = 0 ; i < tam ; i++)
        printf("%d ", vet[i]);
}


int minimo(int vet[] , int tam)
{
    int m;

    if (0 == tam)
        return 0;
    
    m = minimo(vet,tam-1);

    if (vet[tam] < vet[m])
        m = tam;

    return m;
}


int main()
{
    int tam;

    printf("Digite o tamanho do vetor:\n");

    scanf("%d", &tam);

    int vet[tam];

    printf("Digite os elementos do vetor:\n");

    ler_vetor(vet,tam);

    imprime_vetor(vet,tam);

    printf("\n");

    printf("O minimo está no indice: %d\n", minimo(vet,tam-1));
}