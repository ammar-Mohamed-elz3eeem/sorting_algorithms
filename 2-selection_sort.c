#include "sort.h"

/**
 * selection_sort - function thay sorts array using selection sort Algorithm
 * @array: the array to be sorted
 * @size: number of elements in that array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, smallest = 0;
	int tmp;

	if (array == NULL || size == 0)
		return;

	while (i < size - 1)
	{
		j = i + 1;
		smallest = i;
		while (j < size)
		{
			if (array[j] < array[smallest])
				smallest = j;
			j++;
		}
		if (i != smallest)
		{
			tmp = array[i];
			array[i] = array[smallest];
			array[smallest] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
