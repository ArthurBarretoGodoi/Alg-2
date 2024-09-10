#include <stdio.h>


int fatorial(int n)
{
    if (n == 1)
        return 1;
    
    return n * fatorial(n-1);
}


int main()
{
    int fat, res;

    scanf("%d", &fat);

    res = fatorial(fat);

    printf("%d\n", res);

    return 0;
}