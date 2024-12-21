#include "../include/algorithms/bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n = 20; // Default size of array
  int arr[n];

  // Generate random table
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 20 + 1;
  }

  // Sorting and visualization
  printf("Press Enter to start sorting...");
  getchar();

  bubble_sort(arr, n);

  // End of sorting
  printf("\nSorting complete. Press Enter to exit.");
  getchar();

  return 0;
}
