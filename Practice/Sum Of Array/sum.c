#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 10000;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 1;
  }
  int thread_sum = 0, result_sum = 0;
  omp_set_num_threads(4);
#pragma omp parallel
  {
    int i;
#pragma omp for
    for (i = 0; i < 2500; i++) {
#pragma omp critical
      { thread_sum += arr[i]; }
    }
    printf("Sum of array Thread %d : %d\n", omp_get_thread_num(), thread_sum);
#pragma omp critical
    { result_sum += thread_sum; }
  }
  printf("Array Sum : %d\n", result_sum);
  return 0;
}