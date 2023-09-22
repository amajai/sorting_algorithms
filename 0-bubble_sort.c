#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void bubble_sort(int *array, size_t size)
{
	size_t temp, i, j;
	int is_swapped;

	for (i = 0; i < size - 1; i++)
	{
		is_swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				is_swapped = 1;
			}
		}
		if (!is_swapped)
			return;
	}
}