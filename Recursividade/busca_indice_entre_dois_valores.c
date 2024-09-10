#include <stdio.h>


void ler_vetor(int vet[], int tam)
{
    int x, i;

    for(i = 0 ; i < tam ; i++) {
        scanf("%d", &x);
        vet[i] = x;
    }
}


int busca_iterativa(int vet[], int tam, int x, int y)
{
    if(0 >= tam)
        return -1;
    
    if (vet[tam] > x && vet[tam] < y)
        return tam;
    
    return busca_iterativa(vet,tam-1,x,y);
}


int main()
{
    int tam, x, y, busca;

    printf("Digite o tamanho do vetor\n");

    scanf("%d", &tam);

    int vet[tam];

    printf("Digite os elementos do vetor\n");

    ler_vetor(vet,tam);

    printf("Quais números delimitarão os intervalos?\n");

    scanf("%d", &x);
    scanf("%d", &y);

    busca = busca_iterativa(vet,tam,x,y);

    if (busca == -1)
        printf("O elemento não existe no vetor\n");
    else
        printf("O elemento está na posição %d\n", busca);
    
    return 0;
}