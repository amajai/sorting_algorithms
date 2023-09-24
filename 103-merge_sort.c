#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	merge_sorting(array, 0, size - 1, size);
}

/**
 * merge_sorting - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @fdx: First index in @array
 * @ldx: Last index in @array
 * @size: Number of elements in @array
*/
void merge_sorting(int *array, int fdx, int ldx, size_t size)
{
	int mid;

	if (ldx > fdx)
	{
		mid = fdx + ((ldx - fdx + 1) / 2);
		merge_sorting(array, fdx, mid - 1, size);
		merge_sorting(array, mid, ldx, size);
		merge(array, fdx, mid, ldx);
	}
}

/**
 * merge - Sorts an left and right arrays
 *
 * @array: The array to be sorted
 * @fdx: First index in @array
 * @mid: Middle index in @array
 * @ldx: Last index in @array
*/
void merge(int *array, int fdx, int mid, int ldx)
{
	int i, j, k, *temp_arr, temp_arr_size;
	int nl = mid - fdx;
	int nr = ldx - mid + 1;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < nl; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%i", array[fdx + i]);
	}
	printf("\n");

	printf("[right]: ");
	for (j = 0; j < nr; j++)
	{
		if (j > 0)
			printf(", ");
		printf("%i", array[mid + j]);
	}
	printf("\n");

	temp_arr = sorted_array(array, fdx, mid, nl, nr);
	temp_arr_size = nl + nr;

	printf("[Done]: ");
	i = 0;
	k = fdx;
	for (i = 0; i < temp_arr_size; i++)
	{
		array[k] = temp_arr[i];
		k++;
	}
	print_array(temp_arr, temp_arr_size);
	free(temp_arr);
}

/**
 * sorted_array - combine two arrays into a sorted array
 *
 * @array: The array to be sorted
 * @fdx: First index in @array
 * @mid: Middle index in @array
 * @n_arr_l: left array length
 * @n_arr_r: right array length
 *
 * Return: sorted array
*/
int *sorted_array(int *array, int fdx, int mid, int n_arr_l, int n_arr_r)
{
	int i = 0, j = 0, k = 0, arr_size, *sorted_arr;

	arr_size = n_arr_l + n_arr_r;

	sorted_arr = malloc(sizeof(int) * arr_size);
	if (sorted_arr == NULL)
		return (NULL);

	while (i < n_arr_l && j < n_arr_r)
	{
		if (array[fdx + i] <= array[mid + j])
		{
			sorted_arr[k] = array[fdx + i];
			i++;
		}
		else
		{
			sorted_arr[k] = array[mid + j];
			j++;
		}
		k++;
	}

	while (i < n_arr_l)
	{
		sorted_arr[k] = array[fdx + i];
		k++;
		i++;
	}

	while (j < n_arr_r)
	{
		sorted_arr[k] = array[mid + j];
		k++;
		j++;
	}

	return (sorted_arr);
}
