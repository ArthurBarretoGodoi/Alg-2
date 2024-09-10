#include "ordenacao.h"
#include "pilha.h"
#include <string.h> 
#include <stdlib.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Arthur Barreto Godoi", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20224377; }


//////  FUNÇÕES AUXILIARES //////


int intercala(int vetor[], long a, long m, long b, uint64_t *numComparacoes)
{
    if (a >= b)
        return *vetor;

    long i = a;
    long j = m + 1;
    long tamanho = b - a + 1;

    int *VetAux = (int *)malloc(tamanho * sizeof(int));

    if (VetAux == NULL)
        return -1; 

    // Ordena e insere no VetAux
    for (long k = 0; k < tamanho; k++) {
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

    for (long k = 0; k < tamanho; k++)
        vetor[a + k] = VetAux[k];

    free(VetAux);

    return *vetor;
}


void troca(int vetor[], int a, int b)
{
	int aux;

	aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}


int particiona(int vetor[], int a, int b, int valor, uint64_t *numComparacoes)
{
	int m = a - 1;

	for (int i = a; i <= b; i++)
	{
		(*numComparacoes)++;
		if (vetor[i] <= valor)
		{
			m++;
			troca(vetor, m, i);
		}						
	}
	return m;
}

/////////////////  MERGE COM RECURSÃO  /////////////////


uint64_t mergeRec(int vetor[], long a, long b, uint64_t *numComparacoes)
{
    if (a >= b)
		return *vetor;

	long m = (a + b) / 2;

	mergeRec(vetor, a, m, numComparacoes);
	mergeRec(vetor, m + 1, b, numComparacoes);

	return intercala(vetor, a, m, b, numComparacoes);
}


uint64_t mergeSort(int vetor[], size_t tam) 
{
    uint64_t i = 0;
 
    mergeRec(vetor, 0, tam-1, &i);

    return i;
}


/////////////////  QUICK COM RECURSÃO  /////////////////


long quickSortRecursivo(int vetor[], int a, int b, uint64_t *numComparacoes)
{
	if (a >= b)
		return *vetor;

	int m = particiona(vetor, a, b, vetor[b], numComparacoes);

	quickSortRecursivo(vetor, a, m - 1, numComparacoes);
	quickSortRecursivo(vetor, m + 1, b, numComparacoes);

	return *vetor;
}


uint64_t quickSort(int vetor[], size_t tam) 
{
    uint64_t i = 0;

	quickSortRecursivo(vetor, 0, tam - 1, &i);

	return i;
}


/////////////////  HEAP COM RECURSÃO  /////////////////


void heapifyRecursivo(int vetor[], int n, int i, uint64_t  *numComparacoes) 
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    (*numComparacoes)++;
    if (esq < n && vetor[esq] > vetor[maior])
        maior = esq;

    (*numComparacoes)++;
    if (dir < n && vetor[dir] > vetor[maior])
        maior = dir;

    if (maior != i) {
        int aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        heapifyRecursivo(vetor, n, maior, numComparacoes);
    }
}

uint64_t heapSort(int vetor[], size_t tam) {

    uint64_t numComparacoes = 0;

    // Construindo o heap
    for (int i = tam / 2 - 1; i >= 0; i--)
        heapifyRecursivo(vetor, tam, i, &numComparacoes);

    // Extraindo elementos do heap
    for (int i = tam - 1; i > 0; i--) {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        heapifyRecursivo(vetor, i, 0, &numComparacoes);
    }

    return numComparacoes;
}


/////////////////  MERGE SEM RECURSÃO  /////////////////


uint64_t mergeSortSR(int vetor[], size_t tam) 
{
    uint64_t numComparacoes = 0;

    // Lista de intervalos para a intercalação
    struct intervalo {
        int l;
        int r;
    } *intercalacoes;

    struct pilha *pilha;
    pilha = inicializaPilha();

    int l, r, m;

    // Empilha os intervalos iniciais
    push(pilha, 0);
    push(pilha, tam - 1);

    intercalacoes = (struct intervalo *)malloc(tam * sizeof(struct intervalo));
    int intercala_indice = 0;

    while (!pilhaVazia(pilha)) {
        pop(pilha, &r);
        pop(pilha, &l);

        if (l < r) {
            m = l + (r - l) / 2;

            // Empilha os intervalos da divisão
            push(pilha, l);
            push(pilha, m);
            push(pilha, m + 1);
            push(pilha, r);

            // Guarda os intervalos para intercalação
            intercalacoes[intercala_indice].l = l;
            intercalacoes[intercala_indice].r = r;
            intercala_indice++;
        }
    }

    // Realiza a intercalação para todos os intervalos armazenados
    for (int i = intercala_indice - 1; i >= 0; i--) {
        l = intercalacoes[i].l;
        r = intercalacoes[i].r;
        m = l + (r - l) / 2;
        intercala(vetor, l, m, r, &numComparacoes);
    }

    free(intercalacoes);
    destroiPilha(pilha);

    return numComparacoes;
}


/////////////////  QUICK SEM RECURSÃO  /////////////////


uint64_t quickSortSR(int vetor[], size_t tam) 
{
    uint64_t numComparacoes = 0;

    struct pilha *pilha;
    pilha = inicializaPilha();

    // Empilha os intervalos iniciais
    push(pilha, 0);
    push(pilha, tam - 1);

    while (!pilhaVazia(pilha)) {

        int base, topo;

        pop(pilha, &topo);
        pop(pilha, &base);

        if (base < topo) {

            int valor = vetor[topo];  // Escolher o último elemento como pivô
            int particiona_indice = particiona(vetor, base, topo, valor, &numComparacoes);

            if (particiona_indice - 1 > base) {
                push(pilha, base);
                push(pilha, particiona_indice - 1);
            }

            if (particiona_indice + 1 < topo) {
                push(pilha, particiona_indice + 1);
                push(pilha, topo);
            }
        }
    }

    destroiPilha(pilha);

    return numComparacoes;
}


/////////////////  HEAP SEM RECURSÃO  /////////////////


void heapifyIterativo(int vetor[], size_t tam, int i, uint64_t *numComparacoes) 
{
    int maior = i;

    while (true) {

        int esq = 2 * maior + 1;
        int dir = 2 * maior + 2;
        int novo_maior = maior;

        if (esq < tam && vetor[esq] > vetor[novo_maior]) {
            novo_maior = esq;
        }

        (*numComparacoes)++;

        if (dir < tam && vetor[dir] > vetor[novo_maior]) {
            novo_maior = dir;
        }

        (*numComparacoes)++;

        if (novo_maior != maior) {
            int aux = vetor[maior];
            vetor[maior] = vetor[novo_maior];
            vetor[novo_maior] = aux;
            maior = novo_maior;
        } 
        else 
            break;
    }
}


uint64_t heapSortSR(int vetor[], size_t tam) 
{
    uint64_t numComparacoes = 0;

    // Construindo o heap
    for (int i = tam / 2 - 1; i >= 0; i--) {
        heapifyIterativo(vetor, tam, i, &numComparacoes);
    }

    // Extraindo elementos do heap
    for (int i = tam - 1; i > 0; i--) {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        heapifyIterativo(vetor, i, 0, &numComparacoes);
    }

    return numComparacoes;
}