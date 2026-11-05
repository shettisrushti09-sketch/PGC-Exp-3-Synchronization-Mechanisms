#include <stdio.h>
#include <omp.h>

int main() {
    int counter = 0;
    omp_lock_t lock;

    omp_init_lock(&lock);

    #pragma omp parallel for
    for (int i = 0; i < 100000; i++) {
        omp_set_lock(&lock);
        counter++;
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);

    printf("Final counter = %d\n", counter);

    return 0;
}
