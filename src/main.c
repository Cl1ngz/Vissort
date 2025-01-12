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
  printf("Press Enter to get into selection of sorting algorithm.");
  getchar();

  // Select an algorithm to visualize
  printf("Awailable sorting algorithms:\n");
  printf("1) Bubble Sort\n");
  printf("2) Selection Sort\n");
  printf("3) Insertion Sort\n");
  printf("4) Merge Sort\n");
  printf("5) Quick Sort\n");
  printf("6) Counting Sort\n");
  printf("Select an algorithm to visualize:\n");

  int choice;
  scanf("%d", &choice);
  switch (choice) {
  case 1:
    bubble_sort(arr, n);
    break;
  case 2:
    selection_sort(arr, n);
    break;
  case 3:
    insertion_sort(arr, n);
    break;
  case 4:
    // TODO: Fix this
    merge_sort(arr, 0, n - 1);
    break;
  case 5:
    quick_sort(arr, 0, n - 1);
    break;
  case 6:
    counting_sort(arr, n);
    break;
  default:
    printf("Invalid choice. Exiting.");
    return 1;
  }

  // End of sorting
  printf("\nSorting complete. Press Enter to exit.");
  getchar();

  return 0;
}
