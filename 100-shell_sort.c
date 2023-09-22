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
	size_t n, s, i, j;
	int temp;

	if (size < 2)
		return;

	n = 1;
	s = size;
	while (n < s / 3)
		n = n * 3 + 1;

	while (n >= 1)
	{
		for (i = n; i < s; i++)
		{
			for (j = i; j >= n && array[j] < array[j - n]; j = j - n)
			{
				temp = array[j];
				array[j] = array[j - n];
				array[j - n] = temp;
			}
		}
		print_array(array, size);
		n = n / 3;
	}
}
