#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return exp(x);
}

double trapezoidal_rule_parallel(double a, double b, int n, int num_threads) {
    double h = (b - a) / n;
    double sum = 0.0;
    double *local_sums = (double *)malloc(num_threads * sizeof(double));

    omp_set_num_threads(num_threads);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        local_sums[tid] = 0.0;

        #pragma omp for
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            local_sums[tid] += f(x);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        sum += local_sums[i];
    }

    sum += (f(a) + f(b)) / 2.0;
    sum *= h;

    free(local_sums);
    return sum;
}

int main() {
    int num_threads;
    double a, b;
    int n;
    double result;
    double total_time = 0.0;

    printf("Digite o número de threads a serem usadas: ");
    scanf("%d", &num_threads);

    printf("Digite o limite inferior (a): ");
    scanf("%lf", &a);

    printf("Digite o limite superior (b): ");
    scanf("%lf", &b);

    printf("Digite o número de subdivisões (n): ");
    scanf("%d", &n);

    for (int i = 0; i < 10; i++) {
        double start_time = omp_get_wtime();
        result = trapezoidal_rule_parallel(a, b, n, num_threads);
        double end_time = omp_get_wtime();
        total_time += (end_time - start_time);
    }

    printf("Resultado: %f\n", result);
    printf("Tempo médio de execução: %f segundos\n", total_time / 10.0);

    return 0;
}
