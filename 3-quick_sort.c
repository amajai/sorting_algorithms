#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void quick_sort(int *array, size_t size)
{
	int fdx, ldx;

	if (size < 2)
		return;

	fdx = 0;
	ldx = size - 1;
	quick_sorting(array, fdx, ldx, size);
}

/**
 * partition - Get the pivot of the array
 *
 * @array: The array to be sorted
 * @fdx: First index in @array
 * @ldx: Last index in @array
 * @size: Number of elements in @array
 *
 * Return: pivot index
 *
*/
int partition(int *array, int fdx, int ldx, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[ldx];
	i = fdx - 1;
	for (j = fdx; j <= ldx - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
			{
				print_array(array, size);
			}
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[ldx];
	array[ldx] = temp;
	if (ldx != i + 1)
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sorting - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @fdx: First index in @array
 * @ldx: Last index in @array
 * @size: Number of elements in @array
*/
void quick_sorting(int *array, int fdx, int ldx, size_t size)
{
	int pivot;

	if (ldx > fdx)
	{
		pivot = partition(array, fdx, ldx, size);
		quick_sorting(array, fdx, pivot - 1, size);
		quick_sorting(array, pivot + 1, ldx, size);
	}
}
