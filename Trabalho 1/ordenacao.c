#include "ordenacao.h"
#include <string.h>


void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Arthur Barreto Godoi", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}


// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20224377; }


//////  FUNÇÕES AUXILIARES QUE SERÃO USADAS NOS SORTS RECURSIVOS ////// 


// Guarda o elemento do último índice do vetor //
// Move todos os elementos maiores que o último elemento para a direita //
// Substitui o primeiro elemento menor encontrado pelo último elemento //
void insere(int vetor[], long a, long b, uint64_t *numComparacoes)
{
	long elemento;
	long i;

	elemento = vetor[b];

    (*numComparacoes)++;
	for (i = b - 1; i >= 0 && vetor[i] > elemento; i--)
		vetor[i + 1] = vetor[i];

	vetor[i + 1] = elemento;
}


// Retorna o índice do maior elemento do vetor //
long maximo(int vetor[], long a, long b, uint64_t *numComparacoes)
{
	long maior = a;

	for (long i = a + 1; i < b; i++) {

		(*numComparacoes)++;

		if (vetor[i] > vetor[maior])
			maior = i;
	}

	return maior;
}


// Realiza a troca  de v[a] por v[b] //
void troca(int vetor[], long a, long b)
{
	long aux;

	aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}


// Intercala os subvetores criados pelo Merge Sort e os ordena //
int intercala(int vetor[], long a, long m, long b, uint64_t *numComparacoes)
{
	if (a >= b)
		return *vetor;

	long i = a;
	long j = m + 1;
	long VetAux[b - a];

	// Ordena e insere no VetAux //
	for (long k = 0; k <= b - a; k++) {

		(*numComparacoes)++;
		if (j > b || (i <= m && vetor[i] <= vetor[j])) {
			VetAux[k] = vetor[i];
			i++;
		}
		else {
			VetAux[k] = vetor[j];
			j++;
		}
	}

	for (long i = 0; i <= b - a; i++)
		vetor[a + i] = VetAux[i];

	return *vetor;
}


///////////////// INSERTION SORT /////////////////


uint64_t insertionSort(int vetor[], size_t tam) 
{
    long i, j, aux;
    
    uint64_t count = 1;

    for(i = 1 ; i < tam ; i++) {
        aux = vetor[i];
        j = i - 1;

        while((j >= 0) && (aux < vetor[j])) {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
        count++;
    }

    return count;
}


uint64_t insertionRec(int vetor[], size_t tam, uint64_t *numComparacoes)
{
    if (tam <= 0)
	    return *vetor;

	insertionRec(vetor, tam - 1, numComparacoes);
	insere(vetor, 0, tam - 1, numComparacoes);

	return *vetor;
}


uint64_t insertionSortRec(int vetor[], size_t tam) 
{
    uint64_t i = 0;

    insertionRec(vetor, tam, &i);

    return i;
}


///////////////// SELECTION SORT /////////////////


uint64_t selectionSort(int vetor[], size_t tam)
{
    long i, j, min, temp;

	uint64_t count = 0;
    
    for (i = 0; i < tam - 1; i++) {
        min = i;
        for (j = i + 1; j < tam; j++) {
            count++;
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        
        temp = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = temp;
    }

    return count;
}


uint64_t selectionRec(int vetor[], size_t tam, uint64_t *numComparacoes)
{
    long maior;

    if (tam <= 1)
		return 0;

	maior = maximo(vetor, 0, tam, numComparacoes);

	troca(vetor, maior, tam - 1);
	selectionRec(vetor, tam - 1, numComparacoes);

	return 0;
}


uint64_t selectionSortRec(int vetor[], size_t tam) 
{
    uint64_t i = 0;

    selectionRec(vetor, tam, &i);

    return i;
}


///////////////// MERGE SORT /////////////////


uint64_t mergeRec(int vetor[], long a, long b, uint64_t *numComparacoes)
{
    if (a >= b)
		return *vetor;

	long m = (a + b) / 2;

	mergeRec(vetor, a, m, numComparacoes);
	mergeRec(vetor, m + 1, b, numComparacoes);

	return intercala(vetor, a, m, b, numComparacoes);
}


uint64_t mergeSortRec(int vetor[], size_t tam) 
{
    uint64_t i = 0;

    mergeRec(vetor, 0, tam-1, &i);

    return i;
}


///////////////// BUSCA SEQUENCIAL /////////////////

ssize_t buscaSequencial(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) 
{
    long i;

    for(i = 0 ; i < tam ; i++) {

        (*numComparacoes)++;

        if(vetor[i] == valor)
            return i;
    }

    return -1;
}


ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) 
{

	long aux = tam;

	if (aux - 1 < 0)
		return -1;

	(*numComparacoes)++;
	if (valor == vetor[tam - 1])
		return tam - 1;

	return buscaSequencialRec(vetor, aux - 1, valor, numComparacoes);
}


///////////////// BUSCA BINÁRIA  /////////////////


ssize_t buscaBinaria(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) 
{
	long inicio = 0;
	long fim = tam-1;
	long meio = (inicio+fim)/2;

	while(inicio <= fim) {

		(*numComparacoes)++;
		if(valor == vetor[meio])
			return meio;

		else {
			(*numComparacoes)++;
			if(valor < vetor[meio])
				fim = meio - 1;
			else
				inicio = meio + 1;
		}

		meio = (inicio+fim)/2;
	}
	
	return -1;
}


ssize_t BinariaRec(int vetor[], long a, long b, int valor, uint64_t* numComparacoes)
{
	if (a > b)
		return -1;

	long m = (a + b) / 2;

	(*numComparacoes)++;
	if (valor == vetor[m])
		return m;

	(*numComparacoes)++;
	if (valor < vetor[m])
		return BinariaRec(vetor, a, m - 1, valor, numComparacoes);

	return BinariaRec(vetor, m + 1, b, valor, numComparacoes);
}


ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) 
{
	return BinariaRec(vetor, 0, tam-1, valor, numComparacoes);
}