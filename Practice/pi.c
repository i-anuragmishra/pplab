#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

double sum1(int n) {
  double sum = 0;
  for (int i = 1; i <= n; i += 2) {
    sum += pow((2 * i - 1), -1);
  }
  return sum;
}

double sum2(int n) {
  double sum = 0;
  for (int i = 2; i <= n; i += 2) {
    sum += pow((2 * i - 1), -1);
  }
  return sum;
}

int main() {
  int n = 100000;
  double start, end;
  start = omp_get_wtime();
  double part1, part2;
#pragma omp parallel sections
  {
#pragma omp section
    { part1 = sum1(n); }
#pragma omp section
    { part2 = sum2(n); }
  }
  double pi = 4 * (part1 - part2);
  end = omp_get_wtime();
  printf("Value of pi: %f\n", pi);
  printf("Execution Time: %f\n", end - start);
  return 0;
}


/*
// for parallel and time
#include <omp.h>

// pi , merge sort , quick sort
#pragma omp parallel sections
{
    #pragma omp section
    {
        fun1
    }
    #pragma omp section
    {
        fun2
    }
}

exectution time :

double start, end;
start = omp_get_wtime();  
function();
end = omp_get_wtime();   

printf(" Exec %f",end-start);
*/

/*
Matrix
  #pragma omp parallel for private (i,j,k) shared (A,B,C)
    for (int i = 0; i < R1; i++) {
      for (int j = 0; j < C2; j++) {
        for (int k = 0; k < R2; k++) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }

*/

/*
  Odd Even
  #pragma omp parallel for
    for (int i = 0; i < n; i += 2) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        flag0 = 1;
      }
    }
*/