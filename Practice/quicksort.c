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
    QuickSort(arr, low, pidx - 1);
    QuickSort(arr, pidx + 1, high);
  }
}

int main() {
  int n = 100;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  printf("Unsorted Array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  QuickSort(arr, 0, n - 1);
  printf("\nSorted Array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}