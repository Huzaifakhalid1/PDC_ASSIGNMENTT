#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 300  

int main() {
    static int A[N][N], B[N][N], C[N][N]; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }
    }

    double start = omp_get_wtime();

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            #pragma omp parallel for reduction(+:sum) schedule(static)
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    double end = omp_get_wtime();

    printf("Optimized Parallel Execution Time: %f seconds\n", end - start);

    return 0;
}