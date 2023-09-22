#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 * shell sort algorithm Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void shell_sort(int *array, size_t size)
{
	size_t h;
	int n, i, j, temp;

	if (size < 2)
		return;

	h = 1;
	n = size;
	while (h < n / 3)
		h = 3 * h + 1;

	while (h >= 1)
	{
		for (i = h; i < n; i++)
		{
			for (j = i; j >= h && array[j] < array[j - h]; j = j - h)
			{
				temp = array[j];
				array[j] = array[j - h];
				array[j - h] = temp;
			}
		}
		print_array(array, size);
		h = h / 3;
	}
}
