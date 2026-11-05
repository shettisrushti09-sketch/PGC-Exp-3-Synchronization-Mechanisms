#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        printf("Thread %d reached barrier\n", id);

        #pragma omp barrier

        printf("Thread %d passed barrier\n", id);
    }

    return 0;
}
