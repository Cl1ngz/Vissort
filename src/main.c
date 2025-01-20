#include "../include/algorithms/bubble_sort.h"
#include "../include/algorithms/counting_sort.h"
#include "../include/algorithms/insertion_sort.h"
#include "../include/algorithms/quick_sort.h"
#include "../include/algorithms/selection_sort.h"
#include "../include/utils/file_utils.h"
#include "../include/utils/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n = 20; // Default size of array
  int arr[n];

  Node *random_list = NULL;
  Node *sorted_list = NULL;

  const char *filename = "numbers.txt";

  // Generate random table and add to linked list
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 20 + 1;
    append_node(&random_list, arr[i]);
  }

  // Save random numbers to file
  save_numbers_to_file(filename, arr, n, "Random Numbers:");

  printf("Random numbers (saved to file):\n");
  print_list(random_list); // Print random numbers from the linked list

  // Sorting and visualization
  printf("Press Enter to get into selection of sorting algorithm.");
  getchar();

  // Select an algorithm to visualize
  printf("Available sorting algorithms:\n");
  printf("1) Bubble Sort\n");
  printf("2) Selection Sort\n");
  printf("3) Insertion Sort\n");
  printf("4) Quick Sort\n");
  printf("5) Counting Sort\n");
  printf("Select an algorithm to visualize:\n");

  int choice;
  scanf("%d", &choice);
  getchar();
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
    quick_sort(arr, 0, n - 1);
    break;
  case 5:
    counting_sort(arr, n);
    break;
  default:
    printf("Invalid choice. Exiting.\n");
    free_list(random_list);
    return 1;
  }

  // Add sorted numbers to linked list
  for (int i = 0; i < n; i++) {
    append_node(&sorted_list, arr[i]);
  }

  // Save sorted numbers to file
  save_numbers_to_file(filename, arr, n, "Sorted Numbers:");

  printf("\nSorted numbers (saved to file):\n");
  print_list(sorted_list); // Print sorted numbers from the linked list

  // Read and display content from the file
  printf("\nContents of the file:\n");
  read_numbers_from_file(filename);

  free_list(random_list);
  free_list(sorted_list);

  printf("\nSorting complete. Press Enter to exit.");
  getchar();

  return 0;
}
