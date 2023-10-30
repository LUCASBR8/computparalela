#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return exp(x);
}

double trapezoidal_rule_parallel(double a, double b, int n) {
    double h = (b - a) / n;
    double *local_sums = (double *)malloc(sizeof(double) * omp_get_max_threads());
    
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

    double sum = 0.0;
    for (int i = 0; i < omp_get_max_threads(); i++) {
        sum += local_sums[i];
    }

    sum += (f(a) + f(b)) / 2.0;

    free(local_sums);
    return sum * h;
}

int main() {
    double a = 0.0;   // Limite inferior
    double b = 1.0;   // Limite superior
    int n = 1000000;  // Número de subdivisões

    double result = trapezoidal_rule_parallel(a, b, n);
    printf("Resultado: %f\n", result);

    return 0;
}
