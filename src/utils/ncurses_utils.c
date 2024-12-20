#include "../../include/utils/ncurses_utils.h"
#include <ncurses.h>
#include <unistd.h>

void visualize_array(int arr[], int n) {
  int max_height, dummy_width;
  getmaxyx(stdscr, max_height, dummy_width);
  (void)dummy_width; // Mark dummy_width as unused

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < arr[i]; j++) {
      mvprintw(max_height - j - 1, i * 2, "|");
    }
  }
  refresh();
  usleep(100000); // delay for visualization
  clear();
}
