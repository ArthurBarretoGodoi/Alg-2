#include <stdio.h>


int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n-1)+fib(n-2); 
}


int main()
{
    int n;

    printf("Digite o número para calcular o fibonacci:\n");

    scanf("%d", &n);

    printf("O Fibonacci é: %d\n", fib(n));
}