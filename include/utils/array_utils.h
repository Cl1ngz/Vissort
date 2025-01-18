#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

void visualize_array(int arr[], int n, int index1, int index2,
                     int sorted_index);

void visualize_quickSort(int arr[], int n, int low, int high,
                         int highlight_index1, int highlight_index2,
                         int pivot_index);

void visualize_counting_sort(int arr[], int n, int count[], int range,
                             int stage, int output[]);
#endif
