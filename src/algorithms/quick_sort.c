#include "../../include/algorithms/quick_sort.h"
#include "../../include/utils/array_utils.h"

// Modified partition that takes an additional parameter "n" (total array
// length)
int partition(int arr[], int low, int high, int n) {
  int pivot = arr[high];
  int i = low - 1;

  // Visualize the active partition with the pivot highlighted.
  // highlight1 and highlight2 are -1 (unused) at this point.
  visualize_sorting(arr, n, -1, -1, // no immediate highlights
                    high,           // pivot_index at high
                    low, high,      // active partition from low to high
                    -1,             // no sorted boundary
                    "Quick Sort", 30000);

  for (int j = low; j < high; j++) {
    // Visualize the current comparison: highlight index j.
    visualize_sorting(arr, n, j, -1, high, low, high, -1, "Quick Sort", 30000);

    if (arr[j] < pivot) {
      i++;
      // Swap elements arr[i] and arr[j]
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;

      // Visualize the swap: highlight indices i and j.
      visualize_sorting(arr, n, i, j, high, low, high, -1, "Quick Sort", 30000);
    }
  }
  // Swap the pivot into its correct position.
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  // Visualize the pivot swap. Here we pass -1 for pivot_index
  visualize_sorting(arr, n, -1, -1, -1, low, high, i + 1, "Quick Sort", 30000);

  return i + 1;
}

// Modified quick_sort that accepts the total number of elements (n)
void quick_sort(int arr[], int low, int high, int n) {
  if (low < high) {
    int pi = partition(arr, low, high, n);
    quick_sort(arr, low, pi - 1, n);
    quick_sort(arr, pi + 1, high, n);
  }
}
