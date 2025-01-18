#include "../../include/utils/file_utils.h"
#include <stdio.h>
#include <stdlib.h>

// Save numbers to a file with a specific message
void save_numbers_to_file(const char *filename, int *arr, int n,
                          const char *message) {
  FILE *file = fopen(filename, "w"); // Open file in append mode
  if (!file) {
    perror("Error opening file");
    return;
  }

  fprintf(file, "====================\n"); // Separator for readability
  fprintf(file, "%s\n", message);          // Write the message
  for (int i = 0; i < n; i++) {
    fprintf(file, "%d ", arr[i]); // Write the numbers
  }
  fprintf(file, "\n");                     // Newline after numbers
  fprintf(file, "====================\n"); // End of section
  fclose(file);                            // Close the file
}

// Read and print numbers from a file
void read_numbers_from_file(const char *filename) {
  FILE *file = fopen(filename, "r"); // Open file in read mode
  if (!file) {
    perror("Error opening file");
    return;
  }

  char line[256]; // Buffer to read lines
  printf("\nContents of %s:\n", filename);
  printf("--------------------\n");
  while (fgets(line, sizeof(line), file)) {
    printf("%s", line); // Print each line
  }
  printf("--------------------\n");
  fclose(file); // Close the file
}
