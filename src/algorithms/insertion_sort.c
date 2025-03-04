#include "../../include/algorithms/insertion_sort.h"
#include "../../include/utils/array_utils.h"

void insertion_sort(int arr[], int n) {
  // Initially, the first element is considered sorted.
  visualize_sorting(arr, n, -1, -1, -1, 1, n - 1, 1, "Insertion Sort", 100000);

  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    // Visualize the key element about to be inserted.
    visualize_sorting(arr, n, i, -1, -1, 0, n - 1, i, "Insertion Sort", 100000);
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      // Visualize the shifting of element at index j.
      visualize_sorting(arr, n, j, j + 1, -1, 0, n - 1, i, "Insertion Sort",
                        100000);
      j--;
    }
    arr[j + 1] = key;
    // Visualize after the key is inserted.
    visualize_sorting(arr, n, j + 1, -1, -1, 0, n - 1, i + 1, "Insertion Sort",
                      100000);
  }
  // Final visualization: entire array is sorted.
  visualize_sorting(arr, n, -1, -1, -1, 0, n - 1, n, "Insertion Sort", 500000);
}
