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
    char nome[MAX_CHAR_NOME];
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


// Função que imprime o tempo gasto do algoritmo de busca, o indice e seu custo //
void analise_busca(uint64_t numComp, int indice, int start, int end)
{
	double tempo = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo gasto: %f\n", tempo);
	printf("Indice: %d, Comparacoes: %ld\n", indice, numComp);
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


	// INSERTION SORT //

    printf("\n----- Insertion Sort Iterativo -----\n");
	start = clock();
	numComp = insertionSort(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);
	reinicia_vetor(vetor, vetAux, tam);


	printf("\n----- Insertion Sort  Recursivo -----\n");
	start = clock();
	numComp = insertionSortRec(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);
	reinicia_vetor(vetor, vetAux, tam);


	// SELECTION SORT //

	printf("\n----- Selection Sort Iterativo-----\n");
	start = clock();
	numComp = selectionSort(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);
	reinicia_vetor(vetor, vetAux, tam);


	printf("\n----- Selection Sort Recursivo----\n");
	start = clock();
	numComp = selectionSortRec(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);
	reinicia_vetor(vetor, vetAux, tam);


	// MERGE SORT //

	printf("\n----- Merge Sort Recursivo----\n");
	start = clock();
	numComp = mergeSortRec(vetor, tam);
	end = clock();

	imprimir_analise(numComp, start, end);


	////// BUSCAS ////// 


	long valor, indice;

	printf("\nDigite o valor que deseja buscar:\n");

	scanf("%ld", &valor);


	//  BUSCA SEQUENCIAL //

	numComp = 0;

	printf("\n----- Busca Sequencial Iterativa -----\n");
	start = clock();
	indice = buscaSequencial(vetor, tam, valor, &numComp);
	end = clock();

	analise_busca(numComp, indice, start, end);


	numComp = 0;

	printf("\n----- Busca Sequencial Recursiva -----\n");
	start = clock();
	indice = buscaSequencialRec(vetor, tam, valor, &numComp);
	end = clock();

	analise_busca(numComp, indice, start, end);


	//  BUSCA BINÁRIA //

	numComp = 0;

	printf("\n----- Busca Binária Iterativa -----\n");
	start = clock();
	indice = buscaBinaria(vetor, tam, valor, &numComp);
	end = clock();

	analise_busca(numComp, indice, start, end);


	numComp = 0;

	printf("\n----- Busca Binária Recursiva -----\n");
	start = clock();
	indice = buscaBinariaRec(vetor, tam, valor, &numComp);
	end = clock();

	analise_busca(numComp, indice, start, end);

	printf("\n");


	// LIBERAÇÃO DA MEMÓRIA //

    free(vetor);
    free(vetAux);

    return 0;
}
