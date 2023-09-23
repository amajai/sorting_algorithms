#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void counting_sort(int *array, size_t size)
{
	size_t i, idx_arr_size;
	int k, *idx_arr, *sorted;

	if (size < 2)
		return;
	k = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	idx_arr_size = k + 1;
	idx_arr = malloc(sizeof(int) * idx_arr_size);
	if (idx_arr == NULL)
		return;

	for (i = 0; i < idx_arr_size; i++)
		idx_arr[i] = 0;

	for (i = 0; i < size; i++)
		idx_arr[array[i]] += 1;

	for (i = 0; i < idx_arr_size - 1; i++)
		idx_arr[i + 1] += idx_arr[i];

	print_array(idx_arr, idx_arr_size);
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		sorted[idx_arr[array[i]] - 1] = array[i];
		idx_arr[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(idx_arr);
	free(sorted);
}
