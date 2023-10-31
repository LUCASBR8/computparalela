#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
void matrix_multiply_parallel(int **A, int **B, int **C, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int local_sum = 0;  // Soma local para cada thread
            for (int k = 0; k < size; k++) {
                local_sum += A[i][k] * B[k][j];
            }
            #pragma omp critical
            C[i][j] = local_sum;  // Região crítica para atualizar C
        }
    }
}

int main() {
    int size;
    printf("Digite o tamanho das matrizes: ");
    scanf("%d", &size);

    int **A, **B, **C;

    // Aloque memória para as matrizes A, B e C
    A = (int **)malloc(size * sizeof(int *));
    B = (int **)malloc(size * sizeof(int *));
    C = (int **)malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        A[i] = (int *)malloc(size * sizeof(int));
        B[i] = (int *)malloc(size * sizeof(int));
        C[i] = (int *)malloc(size * sizeof(int));
    }

    // Preencha as matrizes A e B (por simplicidade, deixe como exemplo)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    double start_time = omp_get_wtime();
    matrix_multiply_parallel(A, B, C, size);
    double end_time = omp_get_wtime();

    // Exiba o resultado ou faça qualquer outra operação necessária

    printf("Tempo de execução: %f segundos\n", end_time - start_time);

    // Libere a memória alocada
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
