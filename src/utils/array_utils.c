#include "../../include/utils/array_utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_ROWS 24
#define DEFAULT_COLS 80

// ANSI color codes
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

// Move cursor macro
#define MOVE_CURSOR(row, col) printf("\033[%d;%dH", (row), (col))

// Retrieve terminal size (rows, cols) using "stty size"
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

// Return the maximum element in the array
int get_max_height(int arr[], int n) {
  int max_height = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max_height) {
      max_height = arr[i];
    }
  }
  return max_height;
}

/*
 * A single unified visualization function.
 *
 * Parameters:
 *   arr[]            - the array to visualize
 *   n                - number of elements in arr
 *   highlight1, highlight2  - indices you want to highlight in red (e.g.,
 *   current comparison)
 *   pivot_index      - index of the pivot (e.g., in quicksort); pass -1 if not
 * used part_low, part_high     - range of "active partition" in green; pass -1
 * if not used sorted_index     - if some portion of the array is considered
 * "sorted" (e.g., bubble sort), pass the boundary index. Everything >=
 * sorted_index gets a color. Pass -1 if not used. title - a string title to
 * print at the top delay_microsec   - delay in microseconds for the animation
 */
void visualize_sorting(int arr[], int n, int highlight1, int highlight2,
                       int pivot_index, int part_low, int part_high,
                       int sorted_index, const char *title,
                       useconds_t delay_microsec) {

  // TODO: verify the if statmets

  // Clear the screen
  printf("\033[H\033[J");

  // Get terminal size
  int rows = DEFAULT_ROWS, cols = DEFAULT_COLS;
  get_terminal_size(&rows, &cols);

  // Find max height
  int max_height = get_max_height(arr, n);

  // Print title near top center
  int title_col = (cols - (int)strlen(title)) / 2;
  int title_row = 2;
  MOVE_CURSOR(title_row, title_col);
  printf("%s%s%s", COLOR_BLUE, title, COLOR_RESET);

  // Start drawing from the bottom
  int start_row = rows - max_height - 2; // a bit above last line
  if (start_row < 3) {
    start_row = 3; // Avoid overwriting title
  }
  int start_col = (cols - n) / 2; // center horizontally

  // Print from top (max_height) down to 1
  for (int h = max_height; h >= 1; h--) {
    MOVE_CURSOR(start_row + (max_height - h), start_col);
    for (int i = 0; i < n; i++) {
      // Decide which color to use
      const char *color = COLOR_RESET;

      // If this element's height >= current row
      if (arr[i] >= h) {
        // Priority #1: pivot
        if (i == pivot_index && pivot_index != -1) {
          color = COLOR_BLUE;
        }
        // Priority #2: highlight (comparison)
        else if ((i == highlight1 && highlight1 != -1) ||
                 (i == highlight2 && highlight2 != -1)) {
          color = COLOR_RED;
        }
        // Priority #3: partition range
        else if (part_low != -1 && part_high != -1 && i >= part_low &&
                 i <= part_high) {
          color = COLOR_GREEN;
        }
        // Priority #4: sorted boundary
        else if (sorted_index != -1 && i >= sorted_index) {
          color = COLOR_YELLOW;
        }
        // else default color

        printf("%s█%s", color, COLOR_RESET);
      } else {
        // Print space if block is not tall enough
        printf(" ");
      }
    }
    printf("\n");
  }

  // Legend (optional) at the bottom
  MOVE_CURSOR(rows, 1);
  printf("%sLegend:%s ", COLOR_RESET, COLOR_RESET);
  printf("%sBlue%s=Pivot, ", COLOR_BLUE, COLOR_RESET);
  printf("%sRed%s=Highlight, ", COLOR_RED, COLOR_RESET);
  printf("%sGreen%s=Partition, ", COLOR_GREEN, COLOR_RESET);
  printf("%sYellow%s=Sorted\n", COLOR_YELLOW, COLOR_RESET);

  fflush(stdout);
  usleep(delay_microsec);
}
