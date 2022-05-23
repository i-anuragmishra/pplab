

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
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, high, mid);
  }
}

int main() {
  int n = 20;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  mergeSort(arr, 0, n - 1);
  printf("\nSorted");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}