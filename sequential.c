#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    clock_t start = clock();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    clock_t end = clock();

    printf("Execution Time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
