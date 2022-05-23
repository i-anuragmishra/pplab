#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void OddEvenSort(int *arr, int n) {
  int flag0 = 0, flag1 = 1;  // flag variable 0 or 1 flag0 -> Odd  flag1 -> even
  while (flag1) {
    flag0 = 0;
    flag1 = 0;
    for (int i = 0; i < n; i += 2) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        flag0 = 1;
      }
    }
    if (flag0) {
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
  int n = 10;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  OddEvenSort(arr, n - 1);
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}