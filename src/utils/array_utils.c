#include "../../include/utils/array_utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Default terminal dimensions
#define DEFAULT_ROWS 24
#define DEFAULT_COLS 80

// ANSI color codes
#define COLOR_RED "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

// Move the cursor to a specific position
#define MOVE_CURSOR(row, col) printf("\033[%d;%dH", (row), (col))

// Helper function to get terminal dimensions
void get_terminal_size(int *rows, int *cols) {
  FILE *fp = popen("stty size", "r");
  if (fp) {
    fscanf(fp, "%d %d", rows, cols);
    pclose(fp);
  } else {
    fprintf(stderr, "Failed to retrieve terminal size. Using defaults.\n");
    *rows = DEFAULT_ROWS;
    *cols = DEFAULT_COLS;
  }
}

// Helper find the maximum value in an array
int get_max_height(int arr[], int n) {
  int max_height = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max_height) {
      max_height = arr[i];
    }
  }
  return max_height;
}

void visualize_array(int arr[], int n, int highlight_index1,
                     int highlight_index2, int sorted_index) {
  printf("\033[H\033[J");

  // Get terminal dimensions dynamically
  int rows = DEFAULT_ROWS, cols = DEFAULT_COLS;
  get_terminal_size(&rows, &cols);

  int max_height = get_max_height(arr, n);

  // Display title at the middle top
  const char *title = "Sorting Visualizer";
  int title_col = (cols - strlen(title)) / 2;
  MOVE_CURSOR(2, title_col);
  printf("%s%s%s", COLOR_BLUE, title, COLOR_RESET);

  // Start visualization at the bottom center
  int start_row = rows - max_height; // Start at the bottom of the terminal
  int start_col = (cols - n) / 2;    // Center the visualization horizontally

  // Print from top to bottom
  for (int row = max_height; row > 0; row--) {
    MOVE_CURSOR(start_row + max_height - row, start_col);
    for (int i = 0; i < n; i++) {
      // Blue for sorted elements
      if (i > sorted_index) {
        printf(COLOR_BLUE);
      }
      // Red for the current elements being compared
      else if (i == highlight_index1 || i == highlight_index2) {
        printf(COLOR_RED);
      }

      if (arr[i] >= row) {
        printf("█");
      } else {
        printf(" ");
      }
      printf(COLOR_RESET); // Reset color after each block
    }
    printf("\n");
  }

  // Add a key legend at the bottom of the screen
  MOVE_CURSOR(rows - 1, 0);
  printf("\n%sLegend:%s \033[32mRed\033[0m: Current Comparison, "
         "\033[34mBlue\033[0m: Sorted\n",
         COLOR_RESET, COLOR_RESET);

  fflush(stdout);
  usleep(100000); // Delay for visualization (100ms)
}

void visualize_quickSort(int arr[], int n, int low, int high,
                         int highlight_index1, int highlight_index2,
                         int pivot_index) {
  printf("\033[H\033[J"); // Clear screen

  // Get terminal dimensions dynamically
  int rows = DEFAULT_ROWS, cols = DEFAULT_COLS;
  get_terminal_size(&rows, &cols);

  int max_height = get_max_height(arr, n);

  // Display title at the middle top
  const char *title = "Quick Sort Visualizer";
  int title_col = (cols - strlen(title)) / 2;
  MOVE_CURSOR(2, title_col);
  printf("%s%s%s", COLOR_BLUE, title, COLOR_RESET);

  // Start visualization at the bottom center
  int start_row = rows - max_height; // Start at the bottom of the terminal
  int start_col = (cols - n) / 2;    // Center the visualization horizontally

  // Print from top to bottom
  for (int row = max_height; row > 0; row--) {
    MOVE_CURSOR(start_row + max_height - row, start_col);
    for (int i = 0; i < n; i++) {
      if (arr[i] >= row) {
        // Red for elements being compared
        if (i == highlight_index1 || i == highlight_index2) {
          printf(COLOR_RED);
        }
        // Blue for the pivot element
        else if (i == pivot_index) {
          printf(COLOR_BLUE);
        }
        // Green for elements in the current active partition
        else if (i >= low && i <= high) {
          printf(COLOR_GREEN);
        }
        // No color for elements outside the partition
        else {
          printf(COLOR_RESET);
        }

        printf("█");
      } else {
        printf(" ");
      }
      printf(COLOR_RESET); // Reset color after each block
    }
    printf("\n");
  }

  // Add a key legend at the bottom of the screen
  MOVE_CURSOR(rows - 1, 0);
  printf("\n%sLegend:%s \033[32mGreen\033[0m: Active Partition, "
         "\033[31mRed\033[0m: Current Comparison, \033[34mBlue\033[0m: Pivot\n",
         COLOR_RESET, COLOR_RESET);

  fflush(stdout);
  usleep(100000); // Delay for visualization (100ms)
}

void visualize_counting_sort(int arr[], int n, int count[], int range,
                             int stage, int output[]) {
  printf("\033[H\033[J"); // Clear screen

  int rows = DEFAULT_ROWS, cols = DEFAULT_COLS;
  get_terminal_size(&rows, &cols);

  int max_height = get_max_height(arr, n);
  int start_row = rows / 4;       // Start at 1/4 of terminal height
  int start_col = (cols - n) / 2; // Center horizontally

  // Display title
  const char *title = "Counting Sort Visualization";
  int title_col = (cols - strlen(title)) / 2;
  MOVE_CURSOR(2, title_col);
  printf("%s%s%s\n", COLOR_BLUE, title, COLOR_RESET);

  // Display stage information
  const char *stage_info;
  if (stage == 1)
    stage_info = "Stage 1: Counting Occurrences";
  else if (stage == 2)
    stage_info = "Stage 2: Cumulative Count";
  else if (stage == 3)
    stage_info = "Stage 3: Building Sorted Array";
  MOVE_CURSOR(4, (cols - (int)strlen(stage_info)) / 2);
  printf("%s%s%s\n", COLOR_GREEN, stage_info, COLOR_RESET);

  // Visualize the input array
  MOVE_CURSOR(start_row, 0);
  printf("\nInput Array:\n");
  for (int row = max_height; row > 0; row--) {
    MOVE_CURSOR(start_row + max_height - row + 1, start_col);
    for (int i = 0; i < n; i++) {
      if (arr[i] >= row) {
        printf("%s█%s", COLOR_GREEN, COLOR_RESET);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  // Visualize the count array
  int count_start_row =
      start_row + max_height + 3; // Spacing below the input array
  MOVE_CURSOR(count_start_row, 0);
  printf("\nCount Array:\n");
  for (int row = range; row > 0; row--) {
    MOVE_CURSOR(count_start_row + range - row + 1, start_col);
    for (int i = 0; i <= range; i++) {
      if (count[i] >= row) {
        printf("%s█%s ", COLOR_BLUE, COLOR_RESET);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // Visualize the output array for Stage 3
  if (stage == 3) {
    int output_start_row = count_start_row + range + 5; // Further down
    MOVE_CURSOR(output_start_row, 0);
    printf("\nSorted Array:\n");
    for (int row = max_height; row > 0; row--) {
      MOVE_CURSOR(output_start_row + max_height - row + 1, start_col);
      for (int i = 0; i < n; i++) {
        if (output[i] >= row) {
          printf("%s█%s", COLOR_GREEN, COLOR_RESET);
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  fflush(stdout);
  usleep(100000); // Delay for visualization
}
