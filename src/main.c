#include "../include/algorithms/bubble_sort.h"
#include <ncurses.h>
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

  // Inicialize ncurses
  initscr();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);

  printw("Press any key to start sorting...");
  refresh();
  getch();

  // Sorting and visualization
  bubble_sort(arr, n);

  // End of sorting
  printw("\nSorting complete. Press any key to exit.");
  refresh();
  getch();

  endwin(); // End ncurses
  return 0;
}
