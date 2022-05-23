#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[j], &arr[i]);
    }
  }
  i++;
  swap(&arr[i], &arr[high]);
  return i;
}

void QuickSort(int *arr, int low, int high) {
  if (low < high) {
    int pidx = partition(arr, low, high);
#pragma omp parallel sections
    {
#pragma omp section
      { QuickSort(arr, low, pidx - 1); }
#pragma omp section
      { QuickSort(arr, pidx + 1, high); }
    }
  }
}

int main() {
  int n = 1000000;
  int arr[n];
  double start, end;
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  //   printf("Unsorted Array: \n");
  //   for (int i = 0; i < n; i++) {
  //     printf("%d ", arr[i]);
  //   }

  start = omp_get_wtime();
  QuickSort(arr, 0, n - 1);
  end = omp_get_wtime();
  //   printf("\nSorted Array: \n");
  //   for (int i = 0; i < n; i++) {
  //     printf("%d ", arr[i]);
  //   }
  printf("Serial Execution Time: %f", end - start);
  printf("\n");
  return 0;
}