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


int somatorio(int vet[], int tam)
{
    int s;

    if (0 == tam)
        return vet[tam];
    
    s = somatorio(vet,tam-1);
    s = s + vet[tam];

    return s;
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

    printf("O somatório é: %d\n", somatorio(vet,tam-1));

    return 0;
}