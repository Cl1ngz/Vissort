#include "../../include/algorithms/counting_sort.h"
#include "../../include/utils/array_utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

  // Stage 1: Count occurrences
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
    visualize_counting_sort(arr, n, count, range, 1, NULL);
  }
  printf("\033[H\033[J");

  // Stage 2: Cumulative count
  for (int i = 1; i <= range; i++) {
    count[i] += count[i - 1];
    visualize_counting_sort(arr, n, count, range, 2, NULL);
  }
  printf("\033[H\033[J");

  // Stage 3: Build sorted array
  int output[n];
  memset(output, 0, sizeof(output));
  for (int i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
    visualize_counting_sort(arr, n, count, range, 3, output);
  }

  // Final sorted array
  printf("\033[H\033[J");
  visualize_counting_sort(arr, n, count, range, 3, output);
}
