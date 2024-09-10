#include <stdio.h>

#define M 20
#define N 18
#define PAREDE 64
#define PASSAGEM 32
#define PASSOU 46

void lerLabirinto(int labirinto[][N], int* linInicio, int* colInicio, int* linFim, int* colFim){
	scanf("%d %d %d %d", linInicio, colInicio, linFim, colFim);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &labirinto[i][j]);
}

void imprimirLabirinto(int labirinto[][N]){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%c", labirinto[i][j]);
		}
		printf("\n");
	}
}

int encontrarSaida(int labirinto[][N], int linAtual, int colAtual, int linFim, int colFim) {
	// Verificar se a posição atual está fora dos limites do labirinto ou é uma parede ou já passou por ela
	if (linAtual < 0 || linAtual >= M || colAtual < 0 || colAtual >= N || labirinto[linAtual][colAtual] == PAREDE || labirinto[linAtual][colAtual] == PASSOU) {
		return 0;
	}

	// Verificar se chegou na saída
	if (linAtual == linFim && colAtual == colFim) {
		labirinto[linAtual][colAtual] = PASSOU; // marcar a saída no caminho
		return 1;
	}

	// Marcar a posição atual como parte do caminho
	labirinto[linAtual][colAtual] = PASSOU;

	// Tentar mover para cima
	if (encontrarSaida(labirinto, linAtual - 1, colAtual, linFim, colFim)) {
		return 1;
	}

	// Tentar mover para a direita
	if (encontrarSaida(labirinto, linAtual, colAtual + 1, linFim, colFim)) {
		return 1;
	}

	// Tentar mover para baixo
	if (encontrarSaida(labirinto, linAtual + 1, colAtual, linFim, colFim)) {
		return 1;
	}

	// Tentar mover para a esquerda
	if (encontrarSaida(labirinto, linAtual, colAtual - 1, linFim, colFim)) {
		return 1;
	}

	// Se nenhuma das direções funcionou, desmarcar a posição atual (backtracking)
	labirinto[linAtual][colAtual] = PASSAGEM;
	return 0;
}

int main()
{
	int labirinto[M][N];
	int linhaInicio, colInicio, linhaFim, colFim;
	lerLabirinto(labirinto, &linhaInicio, &colInicio, &linhaFim, &colFim);

	if (encontrarSaida(labirinto, linhaInicio, colInicio, linhaFim, colFim)) {
		printf("Caminho encontrado:\n");
	} else {
		printf("Não há caminho para a saída.\n");
	}

	imprimirLabirinto(labirinto);

	return 0;
}