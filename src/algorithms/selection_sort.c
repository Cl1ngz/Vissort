#include "../../include/algorithms/selection_sort.h"
#include "../../include/utils/array_utils.h"

void selection_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex])
        minIndex = j;
      // Vizualization after each iteration
      visualize_array(arr, n, j, j + 1, j);
    }
    int temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}
