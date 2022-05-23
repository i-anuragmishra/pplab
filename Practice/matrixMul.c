#include <stdio.h>
#include <stdlib.h>
#define R1 2
#define C1 2
#define R2 2
#define C2 2

int A[R1][C1];
int B[R2][C2];
int C[R1][C2];

int main() {
  // initialization of A
  for (int i = 0; i < R1; i++) {
    for (int j = 0; j < C1; j++) {
      A[i][j] = 2;
    }
  }
  // initialization of B
  for (int i = 0; i < R2; i++) {
    for (int j = 0; j < C2; j++) {
      B[i][j] = 2;
    }
  }
  /*int A[R1][C1];
    int B[R2][C2];
    int C[R1][C2];*/
  if (C1 == R2) {
    for (int i = 0; i < R1; i++) {
      for (int j = 0; j < C2; j++) {
        for (int k = 0; k < R2; k++) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    for (int i = 0; i < R1; i++) {
      for (int j = 0; j < C2; j++) {
        printf("%d ", C[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("\n Not Possible");
  }
  return 0;
}