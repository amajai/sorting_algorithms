#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int temp;

	if (size < 2)
		return;
	temp = array[0];
	for (i = 0; i < size; i++)
	{
		idx = i;
		temp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i] && array[j] < temp)
			{
				temp = array[j];
				idx = j;
			}
		}
		if (!(idx == i))
		{
			array[idx] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
