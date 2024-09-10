#include <stdio.h>


int binario (int n)
{
    if (n == 0)
        return 0;
    
    return (n % 2) + (10 * binario(n/2));
}



int main()
{
    int n;

    printf("Digite o número que quer calcular o binário:\n");

    scanf("%d", &n);

    printf("O binário é: %d\n", binario(n));
}