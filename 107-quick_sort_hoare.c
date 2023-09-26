#include <stdio.h>
#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Hoare partition scheme)
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void quick_sort_hoare(int *array, size_t size)
{
	int fdx, ldx;

	if (size < 2)
		return;

	fdx = 0;
	ldx = size - 1;
	quick_sorting_hoare(array, fdx, ldx, size);
}

/**
 * partition_hoare - Get the pivot of the array
 *
 * @array: The array to be sorted
 * @fdx: First index in @array
 * @ldx: Last index in @array
 * @size: Number of elements in @array
 *
 * Return: pivot index
 *
*/
int partition_hoare(int *array, int fdx, int ldx, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[fdx];
	i = fdx - 1;
	j = ldx + 1;

	while (1)
	{
		i += 1;
		while (array[i] < pivot)
			i += 1;

		if (j == ldx + 1)
			j -= 1;
		while (array[j] > pivot)
			j -= 1;

		if (i >= j)
			return (j);

		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * quick_sorting_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @fdx: First index in @array
 * @ldx: Last index in @array
 * @size: Number of elements in @array
*/
void quick_sorting_hoare(int *array, int fdx, int ldx, size_t size)
{
	int pivot;

	if (ldx > fdx)
	{
		pivot = partition_hoare(array, fdx, ldx, size);
		quick_sorting_hoare(array, fdx, pivot, size);
		quick_sorting_hoare(array, pivot + 1, ldx, size);
	}
}
