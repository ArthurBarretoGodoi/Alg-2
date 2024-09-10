#include <stdio.h>


int potencia(int n, int x)
{
    if (n == 1)
        return x;
    return x * potencia(n-1,x);
}


int main()
{
    int n, x;

    printf("Digite um número e a potência:\n");

    scanf("%d", &x);
    scanf("%d", &n);
    
    printf("A potência é: %d\n", potencia(n,x));

    return 0;
}