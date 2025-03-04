#include "../../include/algorithms/counting_sort.h"
#include "../../include/utils/array_utils.h"

void counting_sort(int arr[], int n, int range) {
  int count[range];
  int k = 0;

  // Initialize the count array to zero
  for (int i = 0; i < range; i++) {
    count[i] = 0;
  }

  // Count the frequency of each element in arr
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
    // Visualize while counting frequencies.
    // Here, we highlight index i of the original array.
    visualize_sorting(arr, n, i, -1, -1, 0, n - 1, -1,
                      "Counting Sort: Counting Frequency", 100000);
  }

  // Reconstruct the sorted array using the count array.
  // We iterate over each possible value (from 0 to range-1)
  // and write it to arr as many times as it appears.
  for (int i = 0; i < range; i++) {
    while (count[i] > 0) {
      arr[k] = i;
      k++;
      count[i]--;
      // Visualize the reconstruction process:
      // highlight the recently updated index (k-1) and show that the sorted
      // portion grows.
      visualize_sorting(arr, n, k - 1, -1, -1, 0, n - 1, k,
                        "Counting Sort: Reconstructing Array", 100000);
    }
  }

  // Final visualization: show the fully sorted array.
  visualize_sorting(arr, n, -1, -1, -1, 0, n - 1, n, "Counting Sort: Sorted",
                    500000);
}
