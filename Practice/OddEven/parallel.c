#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void oddEvenSort(int *arr, int n) {
  int flag0, flag1 = 1;
  while (flag1) {
    flag0 = 0;
    flag1 = 0;
#pragma omp parallel for
    for (int i = 0; i < n; i += 2) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        flag0 = 1;
      }
    }
    if (flag0) {
#pragma omp parallel for
      for (int i = 1; i < n; i += 2) {
        if (arr[i] > arr[i + 1]) {
          swap(&arr[i], &arr[i + 1]);
          flag1 = 1;
        }
      }
    }
  }
}

int main() {
  int n = 100000;
  int arr[n];
  double start, end;
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  start = omp_get_wtime();
  oddEvenSort(arr, n - 1);
  end = omp_get_wtime();
  //   for (int i = 0; i < n; i++) {
  //     printf("%d ", arr[i]);
  //   }
  printf("Execution Time Parallel: %f\n", end - start);
  return 0;
}