#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <unistd.h>  // for useconds_t

/**
 * Parameters:
 *   arr[]         - The array to visualize.
 *   n             - The number of elements in the array.
 *   highlight1    - First index to highlight (e.g., current comparison), or -1 if unused.
 *   highlight2    - Second index to highlight, or -1 if unused.
 *   pivot_index   - Index of the pivot element (if applicable), or -1 if unused.
 *   part_low      - Lower bound of the active partition (if applicable), or -1 if unused.
 *   part_high     - Upper bound of the active partition (if applicable), or -1 if unused.
 *   sorted_index  - Boundary index for sorted portion (if applicable), or -1 if unused.
 *   title         - Title to display at the top of the visualization.
 *   delay_microsec- Delay in microseconds between visualization frames.
 */
void visualize_sorting(int arr[], int n,
                       int highlight1, int highlight2,
                       int pivot_index,
                       int part_low, int part_high,
                       int sorted_index,
                       const char *title,
                       useconds_t delay_microsec);

#endif 
