#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1000

int A[N][N];
int B[N][N];
int C[N][N];

int main() {
  double start, end;
  int i, j, k;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = 2;
      B[i][j] = 2;
    }
  }
  start = omp_get_wtime();
#pragma omp parallel for private(i, j, k) shared(A, B, C)
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  end = omp_get_wtime();
  printf("Execution Time: %f\n", end - start);
  //   for (int i = 0; i < N; i++) {
  //     for (int j = 0; j < N; j++) {
  //       printf("%d ", C[i][j]);
  //     }
  //     printf("\n");
  //   }
  return 0;
}