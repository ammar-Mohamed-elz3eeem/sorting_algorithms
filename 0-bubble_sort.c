#include "sort.h"

/**
 * bubble_sort - function thay sorts array using bubble sort Algorithm
 * @array: the array to be sorted
 * @size: number of elements in that array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int sorted = 0;

	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i + 1] < array[i])
			{
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				sorted = 0;
			}
		}
		print_array(array, size);
	}
}
