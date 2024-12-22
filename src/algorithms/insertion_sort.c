#include "../../include/algorithms/insertion_sort.h"
#include "../../include/utils/array_utils.h"

void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      // Visualize the shifting
      visualize_array(arr, n, j, j + 1, i);
      j--;
    }
    arr[j + 1] = key;
  }
}
