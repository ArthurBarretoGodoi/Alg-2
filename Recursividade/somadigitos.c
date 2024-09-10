#include <stdio.h>


int somadig(int n)
{
    int s;

    if ((n/10) == 0)
        return n;
    
    s = somadig(n/10);
    s = s + (n%10);

    return s;
}


int main()
{
    int n;

    printf("Digite o número para somar os digitos:\n");

    scanf("%d", &n);

    printf("A soma é: %d\n", somadig(n));
}