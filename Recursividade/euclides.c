#include <stdio.h>


int euclides(int a, int b)
{
    if (b == 0)
        return a;

    return euclides(b,a%b);
}


int main()
{
    int a, b;

    printf("Digite dois números para calcular o MDC:\n");

    scanf("%d", &a);
    scanf("%d", &b);

    printf("O MDC é: %d\n", euclides(a,b));

    return 0;
}