#include <stdio.h>
#include <stdlib.h>

int main()
{
    int segundos;
    int horas;
    int minutos;
    int aux;


    printf("Digite os segundos\n");

    scanf("%d", &segundos);

    horas = segundos/3600;
    aux = segundos%3600;
    minutos = aux/60;
    segundos = aux%60;

    printf("Os segundos em horas são %d:%d:%d\n", horas, minutos, segundos);

    return 0;
}
