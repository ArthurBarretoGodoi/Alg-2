#include <stdio.h>


void ler_vetor(int vet[], int tam)
{
    int x, i;

    for(i = 0 ; i < tam ; i++) {
        scanf("%d", &x);
        vet[i] = x;
    }
}


int busca_iterativa(int vet[], int tam, int x)
{
    if(0 >= tam)
        return -1;
    
    if (vet[tam] == x)
        return tam;
    
    return busca_iterativa(vet,tam-1,x);
}


int main()
{
    int tam, x, busca;

    printf("Digite o tamanho do vetor\n");

    scanf("%d", &tam);

    int vet[tam];

    printf("Digite os elementos do vetor\n");

    ler_vetor(vet,tam);

    printf("Qual valor quer procurar?\n");

    scanf("%d", &x);

    busca = busca_iterativa(vet,tam,x);

    if (busca == -1)
        printf("O elemento não existe no vetor\n");
    else
        printf("O elemento está na posição %d\n", busca);
    
    return 0;
}