#include "../../include/algorithms/selection_sort.h"
#include "../../include/utils/array_utils.h"

void selection_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    // Visualize the beginning of a new pass.
    // Sorted portion: indices [0, i) (represented by sorted_index = i)
    // Active partition: indices [i, n-1]
    visualize_sorting(arr, n, -1, -1, -1, i, n - 1, i, "Selection Sort",
                      100000);

    for (int j = i + 1; j < n; j++) {
      // Visualize the comparison between current minimum and candidate.
      visualize_sorting(arr, n, minIndex, j, -1, i, n - 1, i, "Selection Sort",
                        100000);
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
        // Visualize the update when a new minimum is found.
        visualize_sorting(arr, n, minIndex, j, -1, i, n - 1, i,
                          "Selection Sort", 100000);
      }
    }
    // Swap the found minimum element with the first element of the unsorted
    // part.
    if (minIndex != i) {
      int temp = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = temp;
      // Visualize after the swap; the sorted portion increases.
      visualize_sorting(arr, n, -1, -1, -1, i, n - 1, i + 1, "Selection Sort",
                        100000);
    }
    // Visualize the end of this pass.
    visualize_sorting(arr, n, -1, -1, -1, i + 1, n - 1, i + 1, "Selection Sort",
                      100000);
  }
  // Final visualization: entire array is now sorted.
  visualize_sorting(arr, n, -1, -1, -1, 0, n - 1, n, "Selection Sort", 500000);
}
