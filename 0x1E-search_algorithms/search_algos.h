#ifndef SEARCH_ALGORITH
#define SEARCH_ALGORITH
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int linear_search(int *array, size_t size, int value);
void print_arr_at_index(int *array, int low, int high);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);

#endif
