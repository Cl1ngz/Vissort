#include "../../include/algorithms/counting_sort.h"
#include "../../include/utils/array_utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// ANSI color codes
#define COLOR_RED "\033[31m"
#define COLOR_BLUE "\033[34m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

// Move the cursor to a specific position
#define MOVE_CURSOR(row, col) printf("\033[%d;%dH", (row), (col))

// Counting Sort Visualization
void visualize_counting_sort(int arr[], int n, int count[], int range,
                             int stage, int output[]) {
  if (stage == 3) {
    printf("\033[H\033[J"); // Clear screen before Stage 3
  } else {
    printf("\033[H\033[J"); // Clear screen
  }

  // Title
  const char *title = "Counting Sort Visualization";
  printf("%s%s%s\n\n", COLOR_BLUE, title, COLOR_RESET);

  int rows = 24; // Default fallback rows
  int cols = 80; // Default fallback cols
  FILE *fp = popen("stty size", "r");
  if (fp) {
    fscanf(fp, "%d %d", &rows, &cols);
    pclose(fp);
  }

  int max_height = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max_height) {
      max_height = arr[i];
    }
  }

  // Calculate visualization starting point
  int start_row = rows - max_height - 10;
  int start_col = (cols - (n * 2)) / 2;

  // Draw the input array visualization
  printf("Input Array:\n");
  for (int row = max_height; row > 0; row--) {
    MOVE_CURSOR(start_row + max_height - row, start_col);
    for (int i = 0; i < n; i++) {
      if (arr[i] >= row) {
        printf("%s█%s ", COLOR_GREEN, COLOR_RESET);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // Draw the count array visualization
  printf("\nCount Array:\n");
  int count_row_start = start_row + max_height + 2;
  for (int row = range + 1; row > 0; row--) {
    MOVE_CURSOR(count_row_start + range - row, start_col);
    for (int i = 0; i <= range; i++) {
      if (count[i] >= row) {
        printf("%s█%s ", COLOR_BLUE, COLOR_RESET);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // Display stage information
  if (stage == 1) {
    printf("\033[32mStage 1: Counting Occurrences\033[0m\n");
  } else if (stage == 2) {
    printf("\033[32mStage 2: Cumulative Count\033[0m\n");
  } else if (stage == 3) {
    printf("\033[H\033[J"); // Clear screen explicitly before Stage 3
    printf("\033[32mStage 3: Building Sorted Array\033[0m\n");
    printf("\033[32mSorted Array:\033[0m\n");

    for (int row = max_height; row > 0; row--) {
      MOVE_CURSOR(start_row + max_height - row - 5,
                  start_col); // Adjusted row offset
      for (int i = 0; i < n; i++) {
        if (output != NULL && output[i] >= row) {
          printf("%s█%s ", COLOR_GREEN, COLOR_RESET);
        } else {
          printf("  ");
        }
      }
      printf("\n");
    }
  }

  fflush(stdout);
  usleep(300000); // Delay for visualization
}

void counting_sort(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  int range = max;
  int count[range + 1];
  memset(count, 0, sizeof(count));

  // Step 1: Count occurrences
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
    visualize_counting_sort(arr, n, count, range, 1, NULL);
  }

  // Step 2: Cumulative count
  for (int i = 1; i <= range; i++) {
    count[i] += count[i - 1];
    visualize_counting_sort(arr, n, count, range, 2, NULL);
  }

  // Step 3: Build the output array
  int output[n];
  memset(output, 0, sizeof(output));
  for (int i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
    visualize_counting_sort(arr, n, count, range, 3, output);
  }

  // Copy the sorted elements back into the original array
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  // Final visualization to show the completed sorted array
  visualize_counting_sort(arr, n, count, range, 3, output);
}
