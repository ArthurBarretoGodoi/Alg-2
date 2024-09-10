#include <stdio.h>


void olamundo(int n)
{
    if (n == 0)
        return;

    olamundo(n-1);

    printf("Olá mundo %d\n", n);
}


int main()
{
    int n;

    printf("Quantas vezes quer printar Olá mundo?\n");

    scanf("%d", &n);

    olamundo(n);

    return 0;
}