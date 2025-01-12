#include "../../include/algorithms/merge_sort.h"
#include "../../include/utils/array_utils.h"

// Merge function that merges two halves of the array
void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temporary arrays for left and right halves
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;
  // Merge the left and right arrays back into the original array
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;

    // Visualize the array after each merge operation
    visualize_array(arr, r + 1, k - 1, -1, -1);
  }

  // Copy the remaining elements of L[], if any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
    visualize_array(arr, r + 1, k - 1, -1, -1);
  }

  // Copy the remaining elements of R[], if any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
    visualize_array(arr, r + 1, k - 1, -1, -1);
  }

  // Final visualization after merge is complete
  visualize_array(arr, r + 1, -1, -1, -1);
}

// Merge sort function
void merge_sort(int arr[], int l, int r) {
  if (l < r) {
    // Visualize the current state before the recursion splits the array
    visualize_array(arr, r + 1, -1, -1, -1);

    // Find the middle point and divide the array into two halves
    int m = l + (r - l) / 2;

    // Recursively sort the first and second halves
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}
