#include <stdio.h>
#include <omp.h>

int main() {
    int counter = 0;

    #pragma omp parallel for
    for (int i = 0; i < 100000; i++) {
        counter++;
    }

    printf("Final counter = %d\n", counter);

    return 0;
}
