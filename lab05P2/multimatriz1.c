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

    #pragma omp parallel num_threads(num_threads) 
    {
        int tid = omp_get_thread_num();
        double local_sum = 0.0;

        #pragma omp for
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            local_sum += f(x);
        }

        #pragma omp atomic
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

    double result_parallel;
    double result_serial;
    
    // Medida de tempo para a versão sequencial
    double start_time_serial = omp_get_wtime();
    result_serial = trapezoidal_rule_parallel(a, b, n, 1); // Versão sequencial
    double end_time_serial = omp_get_wtime();
    double total_time_serial = end_time_serial - start_time_serial;
    
    // Medida de tempo para a versão paralela
    double start_time_parallel = omp_get_wtime();
    result_parallel = trapezoidal_rule_parallel(a, b, n, num_threads);
    double end_time_parallel = omp_get_wtime();
    double total_time_parallel = end_time_parallel - start_time_parallel;

    // Calcula o speedup
    double speedup = total_time_serial / total_time_parallel;

    printf("Resultado (Paralelo): %f\n", result_parallel);
    printf("Tempo de execução (Paralelo): %f segundos\n", total_time_parallel);
    printf("Speedup: %f\n", speedup);

    return 0;
}
