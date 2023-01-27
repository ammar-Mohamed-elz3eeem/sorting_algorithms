#include "sort.h"
#include <stdio.h>
/**
 * quick_sort - function that sorts array using quick sort Algorithm
 * @array: the array to be sorted
 * @size: number of elements in that array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sorting(array, 0, size - 1, size);
}

/**
 * sort_partition - sorts sub array using quick sort algorithm
 * @array: array of integers to be sorted
 * @first: first element on that array
 * @last: last element on that array
 * @size: size of the array
 *
 * Return: the pivot position of the pivot element
 */

int sort_partition(int *array, int first, int last, int size)
{
	int idx, curr, tmp, pivot;

	pivot = array[last];
	curr = first - 1;

	for (idx = first; idx < last; idx++)
	{
		if (array[idx] < pivot)
		{
			curr++;
			if (array[idx] != array[curr])
			{
				tmp = array[idx];
				array[idx] = array[curr];
				array[curr] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[curr + 1] != array[last])
	{
		tmp = array[curr + 1];
		array[curr + 1] = pivot;
		array[last] = tmp;
		print_array(array, size);
	}

	return (curr + 1);
}

/**
 * sorting - recursively sorts array from left and right
 * @array: array of integers to be sorted
 * @lowerBound: first element on that array
 * @upperBound: last element on that array
 * @size: size of the array
 */

void sorting(int *array, int lowerBound, int upperBound, int size)
{
	int pivot;

	if (upperBound > lowerBound)
	{
		pivot = sort_partition(array, lowerBound, upperBound, size);
		sorting(array, lowerBound, pivot - 1, size);
		sorting(array, pivot + 1, upperBound, size);
	}
}
