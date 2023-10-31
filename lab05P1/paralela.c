#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

double f(double x) {
    return exp(x);
}

double trapezoidal_rule_parallel(double a, double b, int n, int num_threads) {
    double h = (b - a) / n;
    double sum = 0.0;

    #pragma omp parallel num_threads(num_threads) 
    {
        int tid = omp_get_thread_num();
        double local_sum = 0.0;

        #pragma omp for
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            local_sum += f(x);
        }

        #pragma omp critical
        sum += local_sum;
    }

    sum += (f(a) + f(b)) / 2.0;
    return sum * h;
}

int main() {
    double a = 0.0; // Limite inferior
    double b = 1.0; // Limite superior
    int n = 1000000; // Número de subdivisões

    int num_threads;
    printf("Digite o número de threads: ");
    scanf("%d", &num_threads);

    double result;
    clock_t start_time, end_time;

    start_time = clock();
    result = trapezoidal_rule_parallel(a, b, n, num_threads);
    end_time = clock();

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Resultado: %f\n", result);
    printf("Tempo de execução: %f segundos\n", total_time);

    return 0;
}

