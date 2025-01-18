#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>

void save_numbers_to_file(const char *filename, int *arr, int n,
                          const char *message);
void read_numbers_from_file(const char *filename);

#endif
