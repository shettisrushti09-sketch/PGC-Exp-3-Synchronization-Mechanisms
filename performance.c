#include <stdio.h>
#include <omp.h>

int main() {
    int counter = 0;
    double start, end;

    start = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < 1000000; i++) {
        #pragma omp critical
        counter++;
    }

    end = omp_get_wtime();

    printf("Critical counter = %d\n", counter);
    printf("Critical time = %f seconds\n", end - start);

    counter = 0;

    start = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < 1000000; i++) {
        #pragma omp atomic
        counter++;
    }

    end = omp_get_wtime();

    printf("Atomic counter = %d\n", counter);
    printf("Atomic time = %f seconds\n", end - start);

    return 0;
}
