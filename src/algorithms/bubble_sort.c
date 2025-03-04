#include "../../include/algorithms/bubble_sort.h"
#include "../../include/utils/array_utils.h"

void bubble_sort(int arr[], int n) {
  int sorted_index;
  // Loop over each pass
  for (int i = 0; i < n - 1; i++) {
    sorted_index =
        n - i; // Elements from sorted_index to n-1 are in sorted order
    // Inner loop to bubble up the largest element
    for (int j = 0; j < n - i - 1; j++) {
      // Visualize the current comparison (highlight indices j and j+1)
      visualize_sorting(arr, n, j, j + 1, -1, -1, -1, sorted_index,
                        "Bubble Sort Visualization", 10000);

      if (arr[j] > arr[j + 1]) {
        // Swap the elements
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        // Visualize after the swap to see the effect immediately
        visualize_sorting(arr, n, j, j + 1, -1, -1, -1, sorted_index,
                          "Bubble Sort Visualization", 10000);
      }
    }
  }
  // Final visualization: entire array is now sorted
  visualize_sorting(arr, n, -1, -1, -1, -1, -1, n, "Bubble Sort Visualization",
                    50000);
}
