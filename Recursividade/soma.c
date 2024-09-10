#include <stdio.h>


int soma(int n)
{
    int s;

    if (n == 0)
        return 0;
    
    s = soma(n-1);
    s = s + n;
    return s;
}


int main()
{
    int n;

    printf("Digite um número para somar seus anteriores:\n");

    scanf("%d", &n);

    printf("A soma é: %d\n", soma(n));

    return 0;
}