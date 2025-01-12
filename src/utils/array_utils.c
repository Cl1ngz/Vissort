#include "../../include/utils/array_utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// ANSI color codes
#define COLOR_RED "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_RESET "\033[0m"

// Move the cursor to a specific position
#define MOVE_CURSOR(row, col) printf("\033[%d;%dH", (row), (col))

void visualize_array(int arr[], int n, int highlight_index1,
                     int highlight_index2, int sorted_index) {
  printf("\033[H\033[J"); //  Clear screen

  // Get the terminal dimensions dynamically
  int rows = 24; // Default fallback for terminal rows
  int cols = 80; // Default fallback for terminal cols
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

// ANSI color codes
/* #define COLOR_RED "\033[31m" */
/* #define COLOR_BLUE "\033[34m" */
/* #define COLOR_RESET "\033[0m" */

// Move the cursor to a specific position
#define MOVE_CURSOR(row, col) printf("\033[%d;%dH", (row), (col))

void visualize_quickSort(int arr[], int n, int highlight_index1,
                         int highlight_index2, int pivot_index) {
  printf("\033[H\033[J"); // Clear screen

  // Get terminal size dynamically
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

  // Display visualization title
  const char *title = "Quick Sort Visualization";
  int title_col = (cols - strlen(title)) / 2;
  MOVE_CURSOR(2, title_col);
  printf("%s%s%s", COLOR_BLUE, title, COLOR_RESET);

  // Calculate visualization starting point
  int start_row = rows - max_height - 3;
  int start_col = (cols - (n * 2)) / 2;

  // Draw the array visualization
  for (int row = max_height; row > 0; row--) {
    MOVE_CURSOR(start_row + max_height - row, start_col);
    for (int i = 0; i < n; i++) {
      if (arr[i] >= row) {
        if (i == highlight_index1 || i == highlight_index2) {
          printf("%s█%s ", COLOR_RED,
                 COLOR_RESET); // Highlight current comparison
        } else if (i == pivot_index) {
          printf("%s█%s ", COLOR_BLUE, COLOR_RESET); // Highlight pivot
        } else {
          printf("█ "); // Normal blocks
        }
      } else {
        printf("  "); // Empty space
      }
    }
    printf("\n");
  }
  fflush(stdout);
  usleep(100000); // Delay for visualization
}
