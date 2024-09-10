#include <stdio.h>


void ler_vetor(int vet[], int tam)
{
    int x, i;

    for(i = 0 ; i < tam ; i++) {
        scanf("%d", &x);
        vet[i] = x;
    }
}


int palindromo(int vet[], int tam, int comeco)
{
    if (comeco >= tam)
        return 2;
    
    if (vet[comeco] != vet[tam])
        return -1;
    
    return palindromo(vet, comeco++,tam-1);
}


int main()
{
    int tam, comeco, palin;

    comeco = 0;

    printf("Digite o tamanho do vetor\n");

    scanf("%d", &tam);

    int vet[tam];

    printf("Digite os elementos do vetor\n");

    ler_vetor(vet,tam);

    palin = palindromo(vet,tam-1,comeco);

    if (palin == 2)
        printf("O vetor é palíndromo\n");
    else
        printf("O vetor não é palíndromo\n");
        
    return 0;
}