#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int low, int high, int mid) {
  int n = mid - low + 1;
  int m = high - mid;
  int left[n], right[m];
  int i, j, k = low;
  for (i = 0; i < n; i++) {
    left[i] = arr[low + i];
  }
  for (j = 0; j < m; j++) {
    right[j] = arr[mid + 1 + j];
  }
  i = 0, j = 0;
  while (i < n && j < m) {
    if (left[i] < right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }
  while (i < n) {
    arr[k++] = left[i++];
  }
  while (j < m) {
    arr[k++] = right[j++];
  }
}

void mergeSort(int *arr, int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
#pragma omp parallel sections
    {
#pragma omp section
      { mergeSort(arr, low, mid); }
#pragma omp section
      { mergeSort(arr, mid + 1, high); }
    }
    merge(arr, low, high, mid);
  }
}

int main() {
  int n = 1000000;
  int arr[n];
  double start, end;
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  //   printf("\n");
  //   for (int i = 0; i < n; i++) {
  //     printf("%d ", arr[i]);
  //   }
  start = omp_get_wtime();
  mergeSort(arr, 0, n - 1);
  end = omp_get_wtime();
  //   printf("\nSorted");
  //   for (int i = 0; i < n; i++) {
  //     printf("%d ", arr[i]);
  //   }
  printf("Execution time : %f\n", end - start);
  return 0;
}