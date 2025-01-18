#include "../../include/algorithms/quick_sort.h"
#include "../../include/utils/array_utils.h"

// Partition function for quick sort
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      // Swap elements
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;

      // Visualize only when swapping
      visualize_quickSort(arr, high + 1, low, high, i, j, high);
    }
  }
  // Swap pivot element to correct position
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  // Visualize after pivot placement
  visualize_quickSort(arr, high + 1, low, high, -1, -1, i + 1);

  return i + 1;
}

// Quick sort function
void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    // Visualize the current range being sorted
    visualize_quickSort(arr, high + 1, low, high, -1, -1, high);

    int pi = partition(arr, low, high);

    // Recursively sort before and after partition
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}
