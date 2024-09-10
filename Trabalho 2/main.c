#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include "ordenacao.h"


////// FUNÇÕES AUXILIARES QUE SERÃO USADAS NO MAIN ////// 


// Função para printar nome e grr //
void nome_GRR()
{
	printf("\n");
    char nome[MAX_CHAR];
	getNome(nome);
	printf("Trabalho feito por: %s\n", nome);
	printf("GRR: %u\n\n", getGRR());
}


// Função para alocar vetores dinâmicamente //
int *cria_vetor(size_t tam)
{
	int *vetor;

	if (!(vetor = malloc(tam * sizeof(int))))
		return NULL;
	
	if (vetor == NULL) {
		printf("Erro ao alocar memória para o vetor");
		return NULL;
	}

	return vetor;
}


// Função que preenche um vetor com números aléatórios ded 0 a 100 //
void vetor_aleatorio(int vetor[], size_t tam)
{
	srand(time(NULL));

	for (long i = 0; i < tam; i++)
		vetor[i] = rand() % 100;
}


// Função para ler o tamanho do vetor //
size_t tamanho_vetor()
{
	size_t tam;

	printf("Insira o tamanho do vetor: ");
	scanf("%ld", &tam);

	return tam;
}


// Função para copiar o vetor para um vetor auxiliar //
void copiar_vetor(int vetor[], int vetAux[], size_t tam)
{
	for (long i = 0; i < tam; i++)
		vetAux[i] = vetor[i];
}


// Função para reinicializar o vetor para o estado desordenado novamente //
void reinicia_vetor(int vetor[], int vetAux[], size_t tam)
{
	for (long i = 0; i < tam; i++)
		vetor[i] = vetAux[i];
}


// Função que imprime o tempo gasto do algoritmo de ordenação e seu custo //
void imprimir_analise(uint64_t numComp, int start, int end)
{
	double tempo = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo gasto: %f\n", tempo);
	printf("Comparacoes: %ld\n", numComp);
}


//Função imprime utilizada para testar funcionamento dos algoritmos
void imprime(int vet[], size_t tam)
{
    long i;

    for (i = 0 ; i < tam ; i++)
        printf("%d ", vet[i]);
}


////// MAIN ////// 


int main() 
{
    clock_t start, end;
    uint64_t numComp;
    size_t tam;

    nome_GRR();

    tam = tamanho_vetor();

    int *vetor = cria_vetor(tam);
	int *vetAux = cria_vetor(tam);

    vetor_aleatorio(vetor,tam);
    copiar_vetor(vetor,vetAux,tam);


	// MERGE SORT //
	

	printf("\n----- Merge Sort Recursivo----\n");
	start = clock();
	numComp = mergeSort(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);
	reinicia_vetor(vetor, vetAux, tam);

	printf("\n----- Merge Sort Iterativo----\n");
	start = clock();
	numComp = mergeSortSR(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);
	reinicia_vetor(vetor, vetAux, tam);

	
	// QUICK SORT //
	

	printf("\n----- Quick Sort Recursivo----\n");
	start = clock();
	numComp = quickSort(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);
	reinicia_vetor(vetor, vetAux, tam);

	printf("\n----- Quick Sort Iterativo----\n");
	start = clock();
	numComp = quickSortSR(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);
	reinicia_vetor(vetor, vetAux, tam); 


	// HEAP SORT //
 

	printf("\n----- Heap Sort Recursivo----\n");
	start = clock();
	numComp = heapSort(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end); 
	reinicia_vetor(vetor, vetAux, tam); 

	printf("\n----- Heap Sort Iterativo----\n");
	start = clock();
	numComp = heapSortSR(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end); 
	printf("\n");


	// LIBERAÇÃO DA MEMÓRIA //


    free(vetor);
    free(vetAux);

    return 0;
}