#include "../include/algorithms/bubble_sort.h"
#include "../include/algorithms/counting_sort.h"
#include "../include/algorithms/insertion_sort.h"
#include "../include/algorithms/merge_sort.h"
#include "../include/algorithms/quick_sort.h"
#include "../include/algorithms/selection_sort.h"
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

  /* bubble_sort(arr, n); */
  /* selection_sort(arr, n); */
  /*TODO: worng vizualisation frames skipping insertion_sort(arr, n); */
  /* merge_sort(arr, 0, n - 1); */

  /* quick_sort(arr, 0, n - 1); */

  counting_sort(arr, n);

  // End of sorting
  printf("\nSorting complete. Press Enter to exit.");
  getchar();

  return 0;
}
