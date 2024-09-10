#include <stdio.h>


int contadig(int k, int n)
{
    int count;

    if (n == 0)
        return count = 0;
    
    count = contadig(k,n/10);

    if ((n % 10) == k)
        count++;
    
    return count;
}


int main()
{
    int k, n;

    printf("Digite o número que quer contar e um número:\n");

    scanf("%d", &k);
    scanf("%d", &n);

    printf("O digito %d ocoore %d vezes em %d\n", k , contadig(k,n), n);

    return 0;
}