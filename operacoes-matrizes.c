#include <stdio.h> // Asenate de Melo Protti
#include <stdlib.h>

void somarMatrizes(int **matriz1, int **matriz2, int **resultado, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void subtrairMatrizes(int **matriz1, int **matriz2, int **resultado, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void multiplicarMatrizes(int **matriz1, int **matriz2, int **resultado, int linhas1, int colunas1, int colunas2) {
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void exibirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas1, colunas1;
    int linhas2, colunas2;

    printf("Digite o numero de linhas da matriz1: ");
    scanf("%d", &linhas1);

    printf("Digite o numero de colunas da matriz1: ");
    scanf("%d", &colunas1);

    printf("Digite o numero de linhas da matriz2: ");
    scanf("%d", &linhas2);

    printf("Digite o numero de colunas da matriz2: ");
    scanf("%d", &colunas2);

    // verificando dimensao
    if (colunas1 != linhas2) {
        printf("Erro: O numero de colunas da matriz1 deve ser igual ao numero de linhas da matriz2 para realizar a multiplicacao.\n");
        return 0;
    }

    // alocando memoria
    int **matriz1 = (int **)malloc(linhas1 * sizeof(int *)); //  aloca um bloco de memoria no heap para armazenar um array de ponteiros para inteiros. o numero de elementos no array eh igual ao numero de linhas da matriz
    int **matriz2 = (int **)malloc(linhas2 * sizeof(int *));
    int **resultado = (int **)malloc(linhas1 * sizeof(int *));
    for (int i = 0; i < linhas1; i++) {
        matriz1[i] = (int *)malloc(colunas1 * sizeof(int));
        resultado[i] = (int *)malloc(colunas2 * sizeof(int));
    }
    for (int i = 0; i < linhas2; i++) {
        matriz2[i] = (int *)malloc(colunas2 * sizeof(int));
    }

    // entrada de valor
    printf("Digite os valores para a matriz1:\n");
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas1; j++) {
            printf("Digite o valor da coluna %d linha %d: ", j+1, i+1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // entrada de valor
    printf("Digite os valores para a matriz2:\n");
    for (int i = 0; i < linhas2; i++) {
        for (int j = 0; j < colunas2; j++) {
            printf("Digite o valor da coluna %d linha %d: ", j+1, i+1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    int opcao;
    printf("Escolha a operacao:\n");
    printf("1 - Soma das matrizes\n");
    printf("2 - Subtracao das matrizes\n");
    printf("3 - Multiplicacao das matrizes\n");
    scanf("%d", &opcao);

    // realizando calculos
    switch (opcao) {
        case 1:
            // somar matrizes
            somarMatrizes(matriz1, matriz2, resultado, linhas1, colunas1);
            printf("Soma das matrizes:\n");
            exibirMatriz(resultado, linhas1, colunas1);
            break;
        case 2:
            // subtrair matrizes
            subtrairMatrizes(matriz1, matriz2, resultado, linhas1, colunas1);
            printf("Subtracao das matrizes:\n");
            exibirMatriz(resultado, linhas1, colunas1);
            break;
        case 3:
            // multiplicar matrizes
            multiplicarMatrizes(matriz1, matriz2, resultado, linhas1, colunas1, colunas2);
            printf("Multiplicacao das matrizes:\n");
            exibirMatriz(resultado, linhas1, colunas2);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    // liberando memoria para as matrizes
    for (int i = 0; i < linhas1; i++) {
        free(matriz1[i]);
        free(resultado[i]);
    }
    for (int i = 0; i < linhas2; i++) {
        free(matriz2[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0;
}
