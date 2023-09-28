#include <stdio.h>

// Defina o tamanho da matriz e do vetor
#define m 3
#define n 3

// Declare as matrizes e vetores globais
double A[m][n];
double x[n];
double y[m];

// Função para multiplicação da matriz por vetor (serial)
void mat_vect_mult_serial() {
    int i, j;

    // Inicialize o vetor de resultado y com zeros
    for (i = 0; i < m; i++) {
        y[i] = 0.0;
    }

    // Realize a multiplicação da matriz por vetor
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    // Preencha a matriz A e o vetor x (exemplo)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;  // Exemplo: Preencha a matriz A com valores arbitrários
        }
        x[i] = i;  // Exemplo: Preencha o vetor x com valores arbitrários
    }

    // Realize a multiplicação da matriz por vetor (serial)
    mat_vect_mult_serial();

    // Imprima o vetor resultante y
    printf("Resultado (vetor y):\n");
    for (int i = 0; i < m; i++) {
        printf("%f ", y[i]);
    }
    printf("\n");

    return 0;
}
